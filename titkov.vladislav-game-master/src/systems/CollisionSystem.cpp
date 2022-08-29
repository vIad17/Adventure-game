#include "systems/CollisionSystem.h"

#include <BearLibTerminal.h>

#include <algorithm>

#include "components/DamageComponent.h"
#include "components/DoorComponent.h"
#include "components/FoodComponent.h"
#include "components/HealthComponent.h"
#include "components/MovementComponent.h"
#include "components/PoisonComponent.h"
#include "components/PoisoningComponent.h"
#include "components/ScoresComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/AntidoteComponent.h"
#include "components/tags/BulletComponent.h"
#include "components/tags/EnemyComponent.h"
#include "components/tags/PlayerComponent.h"
#include "components/tags/WallComponent.h"
#include "ecs/EntityManager.h"

static bool FoodFilter(const Entity& entity) {
  return entity.Contains<FoodComponent>() && entity.Contains<TransformComponent>();
}

static bool AntidoteFilter(const Entity& entity) {
  return entity.Contains<AntidoteComponent>() && entity.Contains<TransformComponent>();
}

static bool EnemyFilter(const Entity& entity) {
  return entity.Contains<EnemyComponent>() && entity.Contains<TransformComponent>();
}

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<HealthComponent>() && entity.Contains<MovementComponent>();
}

static bool BulletFilter(const Entity& entity) {
  return entity.Contains<BulletComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<MovementComponent>();
}

static bool DoorFilter(const Entity& entity) {
  return entity.Contains<DoorComponent>() && entity.Contains<TransformComponent>();
}

static bool WallFilter(const Entity& entity) {
  return entity.Contains<WallComponent>() && entity.Contains<TransformComponent>();
}

static bool PawnFilter(const Entity& entity) {
  return entity.Contains<TransformComponent>() && entity.Contains<MovementComponent>();
}

void EntityHeal(const Entity& entity, int heal) {
  if (entity.Contains<HealthComponent>()) {
    auto hc = entity.Get<HealthComponent>();
    if (hc->health_ + heal < hc->max_health_)
      hc->health_ += heal;
    else
      hc->health_ = hc->max_health_;
  }
}

void EntityDamage(const Entity& entity, int damage) {
  if (entity.Contains<HealthComponent>()) {
    auto hc = entity.Get<HealthComponent>();
    if (hc->health_ - damage >= 0)
      hc->health_ -= damage;
    else
      hc->health_ = 0;
  }
}

void CollisionSystem::OnPreUpdate() {
  for (auto& entity1 : GetEntityManager()) {
    if (PlayerFilter(entity1)) {  // player
      for (auto& entity2 : GetEntityManager()) {
        if (EnemyFilter(entity2)) {  // player-enemy
          auto player_tc = entity1.Get<TransformComponent>();
          auto enemy_tc = entity2.Get<TransformComponent>();
          if (player_tc->x_ == enemy_tc->x_ && player_tc->y_ == enemy_tc->y_) {
            if (entity2.Contains<DamageComponent>()) EntityDamage(entity1, entity2.Get<DamageComponent>()->damage_);
            if (entity1.Contains<PoisoningComponent>() && entity2.Contains<PoisonComponent>()) {
              delay = i = ctx_->poison_delay_ = entity2.Get<PoisonComponent>()->delay_;
              entity1.Get<PoisoningComponent>()->is_poisoning_ = ctx_->is_poisoning_ = true;
            }
            engine_.GetEntityManager()->DeleteEntity(entity2.GetId());
          }
        }

        if (FoodFilter(entity2)) {  // player-food
          auto player_tc = entity1.Get<TransformComponent>();
          auto food_fc = entity2.Get<FoodComponent>();
          auto food_tc = entity2.Get<TransformComponent>();
          if (player_tc->x_ == food_tc->x_ && player_tc->y_ == food_tc->y_) {
            if (entity1.Contains<HealthComponent>()) {
              EntityHeal(entity1, food_fc->heal_);
            }
            engine_.GetEntityManager()->DeleteEntity(entity2.GetId());
          }
        }

        if (AntidoteFilter(entity2)) {  // player-antidote
          auto player_tc = entity1.Get<TransformComponent>();
          auto antidote_tc = entity2.Get<TransformComponent>();
          if (player_tc->x_ == antidote_tc->x_ && player_tc->y_ == antidote_tc->y_) {
            if (entity1.Contains<PoisoningComponent>()) {
              entity1.Get<PoisoningComponent>()->is_poisoning_ = false;
              ctx_->is_poisoning_ = false;
            }
            engine_.GetEntityManager()->DeleteEntity(entity2.GetId());
          }
        }
        if (DoorFilter(entity2)) {  // player-door
          auto player_tc = entity1.Get<TransformComponent>();
          // auto player_mc = entity1.Get<MovementComponent>();
          auto door_tc = entity2.Get<TransformComponent>();

          if (player_tc->x_ == door_tc->x_ && player_tc->y_ == door_tc->y_) {
            auto f = std::find(ctx_->levels_.begin(), ctx_->levels_.end(), ctx_->scene_);
            if (entity2.Get<DoorComponent>()->is_it_next_level_) {
              ctx_->is_it_next_level_ = true;
              ctx_->scene_ = ctx_->levels_.at(std::distance(ctx_->levels_.begin(), f + 1));
              player_tc->x_ = door_tc->x_ - 1;
            } else {
              ctx_->is_it_next_level_ = false;
              ctx_->scene_ = ctx_->levels_.at(std::distance(ctx_->levels_.begin(), f - 1));
              player_tc->x_ = door_tc->x_ + 1;
            }
          }
        }
      }
      ctx_->health_ = entity1.Get<HealthComponent>()->health_;
      if (entity1.Contains<PoisoningComponent>())
        ctx_->is_poisoning_ = entity1.Get<PoisoningComponent>()->is_poisoning_;
    }

    if (BulletFilter(entity1)) {  // bullet
      for (auto& entity2 : GetEntityManager()) {
        if (EnemyFilter(entity2)) {  // bullet-enemy
          auto bullet_tc = entity1.Get<TransformComponent>();
          auto bullet_mc = entity1.Get<MovementComponent>();
          auto enemy_tc = entity2.Get<TransformComponent>();
          if (bullet_tc->x_ == enemy_tc->x_ && bullet_tc->y_ == enemy_tc->y_) {
            bullet_mc->x_ = 0;
            bullet_mc->y_ = 0;
            if (entity2.Contains<ScoresComponent>()) {
              ctx_->score_ += entity2.Get<ScoresComponent>()->scores_;
            }
            engine_.GetEntityManager()->DeleteEntity(entity2.GetId());
          }
        }
      }
    }

    if (PawnFilter(entity1)) {  // pawn
      for (auto& entity2 : GetEntityManager()) {
        if (WallFilter(entity2)) {  // pawn-wall
          auto pawn_mc = entity1.Get<MovementComponent>();
          auto pawn_tc = entity1.Get<TransformComponent>();
          auto block_tc = entity2.Get<TransformComponent>();
          if (pawn_tc->x_ + pawn_mc->x_ == block_tc->x_ && pawn_tc->y_ + pawn_mc->y_ == block_tc->y_) {
            pawn_mc->x_ = 0;
            pawn_mc->y_ = 0;
          }
        }
      }
      if (entity1.Contains<PoisoningComponent>() && entity1.Contains<HealthComponent>() &&  // pawn if it is poisoned
          entity1.Get<PoisoningComponent>()->is_poisoning_) {
        if (i == delay) {
          EntityDamage(entity1, 1);
          i = 0;
        }
        i++;
      }
    }
  }
}

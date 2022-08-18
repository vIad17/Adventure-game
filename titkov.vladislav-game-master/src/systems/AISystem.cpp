#include "systems/AISystem.h"

#include <BearLibTerminal.h>

#include <cmath>
#include <random>

#include "components/AIPursuedComponent.h"
#include "components/AIRandomWalkComponent.h"
#include "components/MovementComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/PlayerComponent.h"
#include "ecs/entity_manager.h"

static bool RandomWalkFilter(const Entity& entity) {
  return entity.Contains<AIRandomWalkComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<MovementComponent>();
}

static bool PursuedFilter(const Entity& entity) {
  return entity.Contains<AIPursuedComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<MovementComponent>();
}

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<MovementComponent>();
}

void AISystem::OnUpdate() {
  for (auto& player_entity : GetEntityManager()) {
    if (PlayerFilter(player_entity)) {
      for (auto& ai_entity : GetEntityManager()) {
        if (RandomWalkFilter(ai_entity)) {
          auto ai_mc = ai_entity.Get<MovementComponent>();
          auto ai_rwc = ai_entity.Get<AIRandomWalkComponent>();
          if (ai_rwc->i_ == ai_rwc->delay_) {
            std::random_device device;
            random_generator_.seed(device());
            std::uniform_int_distribution<int> range(1, 4);
            int random = range(random_generator_);
            if (random == 1) {
              ai_mc->x_ = 1;
              ai_mc->y_ = 0;
            }
            if (random == 2) {
              ai_mc->x_ = -1;
              ai_mc->y_ = 0;
            }
            if (random == 3) {
              ai_mc->x_ = 0;
              ai_mc->y_ = -1;
            }
            if (random == 4) {
              ai_mc->x_ = 0;
              ai_mc->y_ = 1;
            }
            ai_rwc->i_ = 0;
          } else {
            ai_mc->x_ = 0;
            ai_mc->y_ = 0;
          }
          ai_rwc->i_++;
        }

        if (PursuedFilter(ai_entity)) {
          auto player_tc = player_entity.Get<TransformComponent>();
          auto ai_tc = ai_entity.Get<TransformComponent>();
          auto ai_mc = ai_entity.Get<MovementComponent>();
          auto ai_pc = ai_entity.Get<AIPursuedComponent>();
          auto dx = player_tc->x_ - ai_tc->x_;
          auto dy = player_tc->y_ - ai_tc->y_;
          if (abs(dx) <= ai_pc->vision_radius_ * 2 && abs(dy) <= ai_pc->vision_radius_) {
            if (ai_pc->i_ == ai_pc->delay_) {
              if (abs(dx) > abs(dy)) {
                ai_mc->x_ = dx / abs(dx);
                ai_mc->y_ = 0;
              } else {
                ai_mc->x_ = 0;
                ai_mc->y_ = dy / abs(dy);
              }
              ai_pc->i_ = 0;
            } else {
              ai_mc->x_ = 0;
              ai_mc->y_ = 0;
            }
            ai_pc->i_++;
          }
        }
      }
    }
  }
}

#include "systems/BulletManagerSystem.h"

#include <BearLibTerminal.h>

#include "components/BulletCountComponent.h"
#include "components/MovementComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/BulletComponent.h"
#include "components/tags/PlayerComponent.h"
#include "ecs/entity_manager.h"

static bool BulletFilter(const Entity& entity) {
  return entity.Contains<BulletComponent>() && entity.Contains<TransformComponent>();
}

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<MovementComponent>() && entity.Contains<BulletCountComponent>();
}

void BulletManagerSystem::OnUpdate() {
  for (auto& bullet_entity : GetEntityManager()) {
    if (BulletFilter(bullet_entity)) {
      for (auto& player_entity : GetEntityManager()) {
        if (PlayerFilter(player_entity)) {
          auto player_tc = player_entity.Get<TransformComponent>();
          auto bullet_tc = bullet_entity.Get<TransformComponent>();
          if (player_tc->x_ == bullet_tc->x_ && player_tc->y_ == bullet_tc->y_) {
            player_entity.Get<BulletCountComponent>()->bullet_count_++;
            bullet_entity.Delete<TransformComponent>();
          }
        }
      }
    }
  }
}

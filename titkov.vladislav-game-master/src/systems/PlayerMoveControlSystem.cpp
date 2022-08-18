#include "systems/PlayerMoveControlSystem.h"

#include "./components/MovementComponent.h"
#include "./components/PlayerMoveControlComponent.h"
#include "./components/TransformComponent.h"
#include "./ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<PlayerMoveControlComponent>() &&
         entity.Contains<TransformComponent>();
}

void PlayerMoveControlSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      auto mc = entity.Get<MovementComponent>();
      auto pmcc = entity.Get<PlayerMoveControlComponent>();

      if (controls_.IsPressed(pmcc->move_right_button_)) {
        mc->x_ = 1;
        mc->y_ = 0;
      } else if (controls_.IsPressed(pmcc->move_left_button_)) {
        mc->x_ = -1;
        mc->y_ = 0;
      } else if (controls_.IsPressed(pmcc->move_up_button_)) {
        mc->x_ = 0;
        mc->y_ = -1;
      } else if (controls_.IsPressed(pmcc->move_down_button_)) {
        mc->x_ = 0;
        mc->y_ = 1;
      } else {
        mc->x_ = 0;
        mc->y_ = 0;
      }
    }
  }
}

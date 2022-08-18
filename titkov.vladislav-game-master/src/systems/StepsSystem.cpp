#include "systems/StepsSystem.h"

#include "./ecs/entity_manager.h"
#include "components/MovementComponent.h"
#include "components/StepsComponent.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<StepsComponent>();
}

void StepsSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      auto mc = entity.Get<MovementComponent>();
      auto sc = entity.Get<StepsComponent>();
      if (sc->steps_ > 0 && (mc->x_ != 0 || mc->y_ != 0)) {
        sc->steps_--;
        ctx_->amount_of_steps_++;
      }
    }
  }
}

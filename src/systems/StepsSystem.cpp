#include "systems/StepsSystem.h"

#include "ecs/EntityManager.h"
#include "components/MovementComponent.h"
#include "components/tags/StepsComponent.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<StepsComponent>();
}

void StepsSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      auto mc = entity.Get<MovementComponent>();
      if (mc->x_ != 0 || mc->y_ != 0) {
        ctx_->amount_of_steps_++;
      }
    }
  }
}

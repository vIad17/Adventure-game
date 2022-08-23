#include "systems/MovementSystem.h"

#include "components/MovementComponent.h"
#include "components/TransformComponent.h"
#include "ecs/EntityManager.h"


void MovementSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<MovementComponent>() && entity.Contains<TransformComponent>()) {
      auto tc = entity.Get<TransformComponent>();
      auto mc = entity.Get<MovementComponent>();
      tc->x_ += mc->x_;
      tc->y_ += mc->y_;
    }
  }
}

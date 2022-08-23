#include "systems/GameOverSystem.h"

#include "components/HealthComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/PlayerComponent.h"
#include "components/tags/StepsComponent.h"
#include "ecs/EntityManager.h"

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<HealthComponent>() && entity.Contains<StepsComponent>();
}

void GameOverSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (PlayerFilter(entity) && entity.Get<HealthComponent>()->health_ <= 0) {
      ctx_->scene_ = ctx_->levels_[static_cast<int>(ctx_->levels_.size() - 1)];
    }
  }
}

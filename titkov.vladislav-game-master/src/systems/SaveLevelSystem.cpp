#include "systems/SaveLevelSystem.h"

#include <vector>

#include "ecs/EntityManager.h"

void SaveLevelSystem::OnUpdate() {
  if (ctx_->level_entities_.find(ctx_->scene_) == ctx_->level_entities_.end()) {
    std::vector<Entity> vec;
    for (auto entity : GetEntityManager()) {
      vec.push_back(entity);
    }
    ctx_->level_entities_[ctx_->scene_] = vec;
  }
}

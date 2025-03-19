#include "systems/PauseSystem.h"

#include <BearLibTerminal.h>

#include "components/HealthComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/PlayerComponent.h"
#include "components/tags/StepsComponent.h"
#include "ecs/EntityManager.h"

void PauseSystem::OnUpdate() {
  if (controls_.IsPressed(TK_ESCAPE)) {
    ctx_->prev_scene_ = ctx_->scene_;
    ctx_->scene_ = ctx_->levels_[static_cast<int>(ctx_->levels_.size() - 4)];
  }
}

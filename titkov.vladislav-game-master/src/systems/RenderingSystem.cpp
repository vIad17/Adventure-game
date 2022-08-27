#include "systems/RenderingSystem.h"

#include <BearLibTerminal.h>

#include "components/BulletCountComponent.h"
#include "components/ColorComponent.h"
#include "components/GraphicComponent.h"
#include "components/HealthComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/PlayerComponent.h"
#include "ecs/EntityManager.h"

void RenderingSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<TransformComponent>()) {
      auto transform = entity.Get<TransformComponent>();
      if (entity.Contains<GraphicComponent>()) {
        terminal_put(transform->x_, transform->y_, entity.Get<GraphicComponent>()->symbol_);
      } else if (entity.Contains<TextureComponent>()) {
        if (entity.Contains<ColorComponent>()) terminal_color(entity.Get<ColorComponent>()->color_);
        terminal_put(transform->x_, transform->y_, entity.Get<TextureComponent>()->symbol_);
        terminal_color("white");
      }
    }

    if (entity.Contains<PlayerComponent>()) {
      if (entity.Contains<BulletCountComponent>()) {
        auto a = entity.Get<BulletCountComponent>()->bullet_count_;
        terminal_printf(1, 0, "Bullets: %d", a);
      }

      terminal_printf(35, 0, "Scores: %d", ctx_->score_);

      if (entity.Contains<HealthComponent>()) {
        auto a = entity.Get<HealthComponent>()->health_;
        terminal_printf(69, 0, "Health: %d", a);
      }
    }
  }
}

void RenderingSystem::OnPreUpdate() {
  terminal_clear();
}

void RenderingSystem::OnPostUpdate() {
  terminal_refresh();
}

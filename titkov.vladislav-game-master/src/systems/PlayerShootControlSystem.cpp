#include "systems/PlayerShootControlSystem.h"

#include "components/BulletCountComponent.h"
#include "components/GraphicComponent.h"
#include "components/MovementComponent.h"
#include "components/PlayerShootControlComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/BulletComponent.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<PlayerShootControlComponent>() &&
         entity.Contains<TransformComponent>();
}

void PlayerShootControlSystem::Shoot(Entity* entity, int dx, int dy) {
  auto tc = entity->Get<TransformComponent>();

  if (entity->Contains<BulletCountComponent>()) {
    auto bcc = entity->Get<BulletCountComponent>();
    if (bcc->bullet_count_ > 0)
      bcc->bullet_count_--;
    else
      return;
  }

  bullets.push_back(engine_.GetEntityManager()->CreateEntity());
  bullets.back()->Add<BulletComponent>();
  bullets.back()->Add<TransformComponent>(tc->x_, tc->y_);
  bullets.back()->Add<MovementComponent>(dx, dy);
  bullets.back()->Add<TextureComponent>('*');
  bullets.back()->Add<GraphicComponent>(0x11);
}

void PlayerShootControlSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      auto pscc = entity.Get<PlayerShootControlComponent>();
      if (controls_.IsPressed(pscc->shoot_right_button_)) {
        Shoot(&entity, 1, 0);
      } else if (controls_.IsPressed(pscc->shoot_left_button_)) {
        Shoot(&entity, -1, 0);
      } else if (controls_.IsPressed(pscc->shoot_up_button_)) {
        Shoot(&entity, 0, -1);
      } else if (controls_.IsPressed(pscc->shoot_down_button_)) {
        Shoot(&entity, 0, 1);
      }
    }
  }

  for (unsigned int i = 0; i < bullets.size(); i++) {
    auto mc = bullets.at(i)->Get<MovementComponent>();
    if (mc->x_ == 0 && mc->y_ == 0) {
      engine_.GetEntityManager()->DeleteEntity(bullets.at(i)->GetId());
      bullets.erase(bullets.begin() + i);
    }
  }
}

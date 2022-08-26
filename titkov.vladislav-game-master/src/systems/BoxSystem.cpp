#include "systems/BoxSystem.h"

#include <BearLibTerminal.h>

#include <random>

#include "components/BoxComponent.h"
#include "components/ColorComponent.h"
#include "components/FoodComponent.h"
#include "components/MovementComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/BulletComponent.h"
#include "components/tags/PlayerComponent.h"
#include "ecs/EntityManager.h"

static bool BoxFilter(const Entity& entity) {
  return entity.Contains<BoxComponent>() && entity.Contains<TransformComponent>();
}

static bool PlayerFilter(const Entity& entity) {
  return entity.Contains<PlayerComponent>() && entity.Contains<TransformComponent>();
}

static bool BulletFilter(const Entity& entity) {
  return entity.Contains<BulletComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<MovementComponent>();
}

void BoxSystem::OnUpdate() {
  for (auto& entity1 : GetEntityManager()) {
    if (PlayerFilter(entity1) || BulletFilter(entity1)) {
      for (auto& entity2 : GetEntityManager()) {
        if (BoxFilter(entity2)) {
          auto entity1_tc = entity1.Get<TransformComponent>();
          auto box_tc = entity2.Get<TransformComponent>();
          auto box_bc = entity2.Get<BoxComponent>();
          if (entity1_tc->x_ == box_tc->x_ && entity1_tc->y_ == box_tc->y_) {
            box_bc->flag = true;
            entity2.Delete<TextureComponent>();
            if (BulletFilter(entity1)) {
              entity1.Get<MovementComponent>()->x_ = 0;
              entity1.Get<MovementComponent>()->y_ = 0;
            }
          }
          if (box_bc->flag) {
            std::random_device device;
            random_generator_.seed(device());
            std::uniform_int_distribution<int> range_x(-2, 2);
            std::uniform_int_distribution<int> range_y(-1, 1);
            int rx = range_x(random_generator_);
            int ry = range_y(random_generator_);

            if (box_bc->bullet_count_ > 0) {
              auto entity = engine_.GetEntityManager()->CreateEntity();
              entity->Add<BulletComponent>();
              entity->Add<ColorComponent>("green");
              entity->Add<TransformComponent>(box_tc->x_ + rx, box_tc->y_ + ry);
              entity->Add<TextureComponent>('$');

              box_bc->bullet_count_--;
            } else if (box_bc->food_count_ > 0) {
              auto entity = engine_.GetEntityManager()->CreateEntity();
              entity->Add<FoodComponent>(50);
              entity->Add<ColorComponent>("green");
              entity->Add<TransformComponent>(box_tc->x_ + rx, box_tc->y_ + ry);
              entity->Add<TextureComponent>('%');

              box_bc->food_count_--;
            } else {
              engine_.GetEntityManager()->DeleteEntity(entity2.GetId());
            }
          }
        }
      }
    }
  }
}

#include "scenes/BattlefieldScene.h"

#include "./Reader.h"
#include "components/AIPursuedComponent.h"
#include "components/AIRandomWalkComponent.h"
#include "components/BulletCountComponent.h"
#include "components/ColorComponent.h"
#include "components/DamageComponent.h"
#include "components/DoorComponent.h"
#include "components/FoodComponent.h"
#include "components/GraphicComponent.h"
#include "components/HealthComponent.h"
#include "components/MovementComponent.h"
#include "components/PlayerMoveControlComponent.h"
#include "components/PlayerShootControlComponent.h"
#include "components/PoisonComponent.h"
#include "components/PoisoningComponent.h"
#include "components/ScoresComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"
#include "components/tags/AntidoteComponent.h"
#include "components/tags/BulletComponent.h"
#include "components/tags/EnemyComponent.h"
#include "components/tags/PlayerComponent.h"
#include "components/tags/StepsComponent.h"
#include "components/tags/WallComponent.h"
#include "ecs/Engine.h"
#include "ecs/EntityManager.h"
#include "ecs/System.h"
#include "lib/Delay.h"
#include "systems/AISystem.h"
#include "systems/BulletManagerSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/GameOverSystem.h"
#include "systems/MovementSystem.h"
#include "systems/PauseSystem.h"
#include "systems/PlayerMoveControlSystem.h"
#include "systems/PlayerShootControlSystem.h"
#include "systems/RenderingSystem.h"
#include "systems/StepsSystem.h"

void BattlefieldScene::OnCreate() {
  std::ifstream file(file_);
  Reader reader(engine, ctx_, file);
  reader.ReadFile();

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>(ctx_);
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<PlayerMoveControlSystem>(controls_);
  sys->AddSystem<PlayerShootControlSystem>(controls_, engine);
  sys->AddSystem<BulletManagerSystem>(ctx_);
  sys->AddSystem<CollisionSystem>(ctx_, engine);
  sys->AddSystem<StepsSystem>(ctx_);
  sys->AddSystem<PauseSystem>(ctx_, controls_);
  sys->AddSystem<AISystem>();
  sys->AddSystem<GameOverSystem>(ctx_);
}
void BattlefieldScene::OnRender() {
  if (enemy_delay.IsReady()) {
    std::random_device device;
    random_generator_.seed(device());
    std::uniform_int_distribution<int> rangei(1, 78);
    std::uniform_int_distribution<int> rangej(2, 23);
    int i = rangei(random_generator_);
    int j = rangej(random_generator_);

    auto entity = engine.GetEntityManager()->CreateEntity();
    entity->Add<EnemyComponent>();
    entity->Add<ColorComponent>("red");
    entity->Add<ScoresComponent>(100);
    entity->Add<AIPursuedComponent>(15, 5);
    entity->Add<AIRandomWalkComponent>(30);
    entity->Add<MovementComponent>(0, 0);
    entity->Add<DamageComponent>(50);
    entity->Add<TransformComponent>(i, j);
    entity->Add<TextureComponent>('E');
    entity->Add<GraphicComponent>(0x03);
  }

  if (snake_delay.IsReady()) {
    std::random_device device;
    random_generator_.seed(device());
    std::uniform_int_distribution<int> rangei(1, 78);
    std::uniform_int_distribution<int> rangej(2, 23);
    int i = rangei(random_generator_);
    int j = rangej(random_generator_);

    auto entity = engine.GetEntityManager()->CreateEntity();
    entity->Add<EnemyComponent>();
    entity->Add<ColorComponent>("red");
    entity->Add<ScoresComponent>(150);
    entity->Add<AIPursuedComponent>(10, 3);
    entity->Add<AIRandomWalkComponent>(45);
    entity->Add<MovementComponent>(0, 0);
    entity->Add<DamageComponent>(10);
    entity->Add<PoisonComponent>(50);
    entity->Add<TransformComponent>(i, j);
    entity->Add<TextureComponent>('S');
    entity->Add<GraphicComponent>(0x04);
  }

  if (bullet_delay.IsReady()) {
    std::random_device device;
    random_generator_.seed(device());
    std::uniform_int_distribution<int> rangei(1, 78);
    std::uniform_int_distribution<int> rangej(2, 23);
    int i = rangei(random_generator_);
    int j = rangej(random_generator_);

    auto entity = engine.GetEntityManager()->CreateEntity();
    entity->Add<BulletComponent>();
    entity->Add<ColorComponent>("green");
    entity->Add<TransformComponent>(i, j);
    entity->Add<TextureComponent>('$');
    entity->Add<GraphicComponent>(0x06);
  }

  if (food_delay.IsReady()) {
    std::random_device device;
    random_generator_.seed(device());
    std::uniform_int_distribution<int> rangei(1, 78);
    std::uniform_int_distribution<int> rangej(2, 23);
    int i = rangei(random_generator_);
    int j = rangej(random_generator_);

    auto entity = engine.GetEntityManager()->CreateEntity();
    entity->Add<FoodComponent>(50);
    entity->Add<ColorComponent>("green");
    entity->Add<TransformComponent>(i, j);
    entity->Add<TextureComponent>('%');
    entity->Add<GraphicComponent>(0x07);
  }

  if (antidote_delay.IsReady()) {
    std::random_device device;
    random_generator_.seed(device());
    std::uniform_int_distribution<int> rangei(1, 78);
    std::uniform_int_distribution<int> rangej(2, 23);
    int i = rangei(random_generator_);
    int j = rangej(random_generator_);

    auto entity = engine.GetEntityManager()->CreateEntity();
    entity->Add<AntidoteComponent>();
    entity->Add<ColorComponent>("green");
    entity->Add<TransformComponent>(i, j);
    entity->Add<TextureComponent>('&');
    entity->Add<GraphicComponent>(0x05);
  }

  enemy_delay.Update();
  snake_delay.Update();
  bullet_delay.Update();
  food_delay.Update();
  antidote_delay.Update();
  engine.OnUpdate();
}
void BattlefieldScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}

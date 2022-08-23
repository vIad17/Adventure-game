#include "scenes/LevelScene.h"

#include "./Reader.h"
#include "systems/AISystem.h"
#include "systems/BulletManagerSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/GameOverSystem.h"
#include "systems/MovementSystem.h"
#include "systems/PlayerMoveControlSystem.h"
#include "systems/PlayerShootControlSystem.h"
#include "systems/RenderingSystem.h"
#include "systems/StepsSystem.h"
#include "ecs/Engine.h"
#include "ecs/System.h"
#include "ecs/EntityManager.h"

void LevelScene::OnCreate() {
  std::ifstream file(file_);
  Reader reader(engine, ctx_, file);
  reader.ReadFile();

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<PlayerMoveControlSystem>(controls_);
  sys->AddSystem<PlayerShootControlSystem>(controls_, engine);
  sys->AddSystem<BulletManagerSystem>(ctx_);
  sys->AddSystem<CollisionSystem>(ctx_, engine);
  sys->AddSystem<StepsSystem>(ctx_);
  sys->AddSystem<AISystem>();
  sys->AddSystem<GameOverSystem>(ctx_);
}
void LevelScene::OnRender() {
  engine.OnUpdate();
}
void LevelScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}

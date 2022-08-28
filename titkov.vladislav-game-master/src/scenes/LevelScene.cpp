#include "scenes/LevelScene.h"

#include "./Reader.h"
#include "ecs/Engine.h"
#include "ecs/EntityManager.h"
#include "ecs/System.h"
#include "systems/AISystem.h"
#include "systems/BoxSystem.h"
#include "systems/BulletManagerSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/GameOverSystem.h"
#include "systems/MovementSystem.h"
#include "systems/PauseSystem.h"
#include "systems/PlayerMoveControlSystem.h"
#include "systems/PlayerShootControlSystem.h"
#include "systems/RenderingSystem.h"
#include "systems/StepsSystem.h"

void LevelScene::OnCreate() {
  // if (ctx_->visited_levels_.at(ctx_->scene_)) {
  //   std::ifstream file(copy_file_);
  //   Reader reader(engine, ctx_, file);
  //   reader.ReadFile();
  // } else {
  //   std::ifstream file(original_file_);
  //   Reader reader(engine, ctx_, file);
  //   reader.ReadFile();
  //   ctx_->visited_levels_.at(ctx_->scene_) = true;
  // }

  // if (ctx_->level_entities_.find(ctx_->scene_) != ctx_->level_entities_.end()) {
  //   for (auto c : ctx_->level_entities_.at(ctx_->scene_)) {
  //     auto entity = engine.GetEntityManager()->CreateEntity();
  //     entity = &c;
  //   }
  // } else {
  std::ifstream file(file_);
  Reader reader(engine, ctx_, file);
  reader.ReadFile();
  // for (auto entity : GetEntityManager()) {

  // }
  // }

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>(ctx_);
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<PlayerMoveControlSystem>(controls_);
  sys->AddSystem<PauseSystem>(ctx_, controls_);
  sys->AddSystem<PlayerShootControlSystem>(controls_, engine);
  sys->AddSystem<BulletManagerSystem>(ctx_);
  sys->AddSystem<CollisionSystem>(ctx_, engine);
  sys->AddSystem<StepsSystem>(ctx_);
  sys->AddSystem<AISystem>();
  sys->AddSystem<BoxSystem>(engine);
  sys->AddSystem<GameOverSystem>(ctx_);
}
void LevelScene::OnRender() {
  engine.OnUpdate();
}
void LevelScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}

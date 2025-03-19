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
  if (!ctx_->visited_levels_.at(ctx_->scene_)) {
    engine.GetEntityManager()->DeleteAll();
    std::ifstream file(original_file_);
    Reader reader(engine, ctx_, file);
    reader.ReadFile();
    ctx_->visited_levels_.at(ctx_->scene_) = true;
  }

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
    // engine.GetEntityManager()->DeleteAll();
    engine.GetSystemManager()->DeleteAll();
  }

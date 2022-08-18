#include <BearLibTerminal.h>

#include <string>
#include <vector>

#include "./Reader.h"
#include "lib/scene_manager.h"
#include "scenes/GameOverScene.h"
#include "scenes/LevelScene.h"
#include "scenes/WinGameScene.h"
#include "systems/AISystem.h"
#include "systems/BulletManagerSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/GameOverSystem.h"
#include "systems/MovementSystem.h"
#include "systems/PlayerMoveControlSystem.h"
#include "systems/PlayerShootControlSystem.h"
#include "systems/RenderingSystem.h"
#include "systems/StepsSystem.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls{};
  const Engine engine{};

  std::vector<std::string> levels{"level1", "game_over", "win_game"};

  Context ctx(levels);
  SceneManager sm(ctx);

  std::ifstream file("../include/Level1.txt");

  sm.Put(ctx.levels_[0], new LevelScene(&ctx, controls, file));
  sm.Put(ctx.levels_[1], new WinGameScene(&ctx, controls));
  sm.Put(ctx.levels_[2], new GameOverScene(&ctx, controls));

  ctx.scene_ = ctx.levels_[0];

  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE) || controls.IsPressed(TK_ESCAPE)) {
      break;
    }

    sm.OnRender();

    controls.Reset();
  }

  terminal_close();
}

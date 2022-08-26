#include <BearLibTerminal.h>

#include <string>
#include <vector>

#include "lib/SceneManager.h"
#include "scenes/BattlefieldGameOverScene.h"
#include "scenes/BattlefieldScene.h"
#include "scenes/GameOverScene.h"
#include "scenes/LeaderboardScene.h"
#include "scenes/LevelScene.h"
#include "scenes/MainMenuScene.h"
#include "scenes/WinGameScene.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls{};
  const Engine engine{};

  std::vector<std::string> levels{"MainMenu",    "Battlefield", "level1",   "level2",
                                  "level3",      "level4",      "level5",   "level6",
                                  "Leaderboard", "WinGame",     "GameOver", "BattlefieldGameOver"};
  std::vector<std::string> files{"./levels/Level1.txt",     "./levels/Level2.txt", "./levels/Level3.txt",
                                 "./levels/Level4.txt",     "./levels/Level5.txt", "./levels/Level6.txt",
                                 "./levels/Battlefield.txt"};
  Context ctx(levels);
  SceneManager sm(ctx);
  sm.Put(ctx.levels_[0], new MainMenuScene(&ctx, controls));
  sm.Put(ctx.levels_[1], new BattlefieldScene(&ctx, controls, files[6]));
  sm.Put(ctx.levels_[2], new LevelScene(&ctx, controls, files[0]));
  sm.Put(ctx.levels_[3], new LevelScene(&ctx, controls, files[1]));
  sm.Put(ctx.levels_[4], new LevelScene(&ctx, controls, files[2]));
  sm.Put(ctx.levels_[5], new LevelScene(&ctx, controls, files[3]));
  sm.Put(ctx.levels_[6], new LevelScene(&ctx, controls, files[4]));
  sm.Put(ctx.levels_[7], new LevelScene(&ctx, controls, files[5]));
  sm.Put(ctx.levels_[8], new LeaderboardScene(&ctx, controls));
  sm.Put(ctx.levels_[9], new WinGameScene(&ctx, controls));
  sm.Put(ctx.levels_[10], new GameOverScene(&ctx, controls));
  sm.Put(ctx.levels_[11], new BattlefieldGameOverScene(&ctx, controls));

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

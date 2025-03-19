#include <BearLibTerminal.h>

#include <map>
#include <string>
#include <vector>

#include "lib/PngConverter.h"
#include "lib/SceneManager.h"
#include "scenes/BattlefieldGameOverScene.h"
#include "scenes/BattlefieldScene.h"
#include "scenes/GameOverScene.h"
#include "scenes/LeaderboardScene.h"
#include "scenes/LevelScene.h"
#include "scenes/MainMenuScene.h"
#include "scenes/PauseScene.h"
#include "scenes/WinGameScene.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls{};

  std::vector<std::string> levels{"MainMenu",
                                  "Battlefield",
                                  "level1",
                                  "level2",
                                  "level3",
                                  "level4",
                                  "level5",
                                  "level6",
                                  "WinGame",
                                  "Pause",
                                  "Leaderboard",
                                  "GameOver",
                                  "BattlefieldGameOver"};
  std::map<std::string, bool> visited_levels{{"Battlefield", false}, {"level1", false}, {"level2", false},
                                             {"level3", false},      {"level4", false}, {"level5", false},
                                             {"level6", false}};
  std::vector<std::string> original_files{"./levels/original/Level1.txt",     "./levels/original/Level2.txt",
                                          "./levels/original/Level3.txt",     "./levels/original/Level4.txt",
                                          "./levels/original/Level5.txt",     "./levels/original/Level6.txt",
                                          "./levels/original/Battlefield.txt"};
  std::vector<std::string> copy_files{"./levels/copy/Level1.txt",     "./levels/copy/Level2.txt",
                                      "./levels/copy/Level3.txt",     "./levels/copy/Level4.txt",
                                      "./levels/copy/Level5.txt",     "./levels/copy/Level6.txt",
                                      "./levels/copy/Battlefield.txt"};

  auto converter = new PngConverter();
  converter->Convert();

  Context ctx(levels, visited_levels);

  SceneManager sm(ctx);
  sm.Put(ctx.levels_[0], new MainMenuScene(&ctx, controls));
  sm.Put(ctx.levels_[1], new BattlefieldScene(&ctx, controls, original_files[6], copy_files[6]));
  sm.Put(ctx.levels_[2], new LevelScene(&ctx, controls, original_files[0], copy_files[0]));
  sm.Put(ctx.levels_[3], new LevelScene(&ctx, controls, original_files[1], copy_files[1]));
  sm.Put(ctx.levels_[4], new LevelScene(&ctx, controls, original_files[2], copy_files[2]));
  sm.Put(ctx.levels_[5], new LevelScene(&ctx, controls, original_files[3], copy_files[3]));
  sm.Put(ctx.levels_[6], new LevelScene(&ctx, controls, original_files[4], copy_files[4]));
  sm.Put(ctx.levels_[7], new LevelScene(&ctx, controls, original_files[5], copy_files[5]));
  sm.Put(ctx.levels_[8], new WinGameScene(&ctx, controls));
  sm.Put(ctx.levels_[9], new PauseScene(&ctx, controls));
  sm.Put(ctx.levels_[10], new LeaderboardScene(&ctx, controls));
  sm.Put(ctx.levels_[11], new GameOverScene(&ctx, controls));
  sm.Put(ctx.levels_[12], new BattlefieldGameOverScene(&ctx, controls));

  ctx.scene_ = ctx.levels_[0];

  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE) || ctx.is_exit) {
      break;
    }

    sm.OnRender();

    controls.Reset();
  }

  terminal_close();
}

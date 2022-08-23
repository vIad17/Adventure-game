#include <BearLibTerminal.h>

#include <string>
#include <vector>

#include "lib/SceneManager.h"
#include "scenes/BattlefieldScene.h"
#include "scenes/GameOverScene.h"
#include "scenes/LevelScene.h"
#include "scenes/MainMenuScene.h"
#include "scenes/WinGameScene.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls{};
  const Engine engine{};

  std::vector<std::string> levels{"MainMenu", "Battlefield", "level1", "level2", "level3", "game_over", "win_game"};
  std::vector<std::string> files{"/home/vlad/CLionProjects/untitled/levels/Level1.txt",
                                 "/home/vlad/CLionProjects/untitled/levels/Level2.txt",
                                 "/home/vlad/CLionProjects/untitled/levels/Level3.txt",
                                 "/home/vlad/CLionProjects/untitled/levels/Battlefield.txt"};
  Context ctx(levels);
  SceneManager sm(ctx);
  sm.Put(ctx.levels_[0], new MainMenuScene(&ctx, controls));
  sm.Put(ctx.levels_[1], new BattlefieldScene(&ctx, controls, files[3]));
  sm.Put(ctx.levels_[2], new LevelScene(&ctx, controls, files[0]));
  sm.Put(ctx.levels_[3], new LevelScene(&ctx, controls, files[1]));
  sm.Put(ctx.levels_[4], new LevelScene(&ctx, controls, files[2]));
  sm.Put(ctx.levels_[5], new WinGameScene(&ctx, controls));
  sm.Put(ctx.levels_[6], new GameOverScene(&ctx, controls));

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

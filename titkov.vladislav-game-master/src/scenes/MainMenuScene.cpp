#include "scenes/MainMenuScene.h"

#include <BearLibTerminal.h>

#include <string>

#include "./Controls.h"
#include "components/ColorComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"

void MainMenuScene::OnCreate() {}

void MainMenuScene::OnRender() {
  terminal_clear();

  terminal_color("white");
  terminal_print(x, y, "->");

  terminal_print(x + 2, min_y, "Story mode");
  terminal_print(x + 2, min_y + 1, "Battlefield");

  if (controls_.IsPressed(TK_UP)) {
    y--;
    if (y < min_y) y = max_y;
  }
  if (controls_.IsPressed(TK_DOWN)) {
    y++;
    if (y > max_y) y = min_y;
  }

  if (controls_.IsPressed(TK_ENTER)) {
    if (y == min_y) ctx_->scene_ = ctx_->levels_[static_cast<int>(2)];
    if (y == min_y + 1) ctx_->scene_ = ctx_->levels_[static_cast<int>(1)];
  }

  terminal_refresh();
}

void MainMenuScene::OnExit() {}

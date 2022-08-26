#include "scenes/MainMenuScene.h"

#include <BearLibTerminal.h>

#include <string>

#include "./Controls.h"
#include "components/ColorComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"

void MainMenuScene::OnCreate() {
  ctx_->health_ = 100;
  ctx_->bullets_ = 0;
  ctx_->amount_of_steps_ = 0;
  ctx_->score_ = 0;
  ctx_->is_poisoning_ = false;
}

void MainMenuScene::OnRender() {
  terminal_clear();

  terminal_color("white");
  terminal_print(x, y, "->");

  terminal_print(x + 2, min_y, "Story mode");
  terminal_print(x + 2, min_y + 1, "Battlefield");
  terminal_print(x + 2, min_y + 2, "Leaderboard");

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
    if (y == min_y + 2) ctx_->scene_ = ctx_->levels_[static_cast<int>(ctx_->levels_.size() - 4)];
  }

  terminal_refresh();
}

void MainMenuScene::OnExit() {}

#include "scenes/MainMenuScene.h"

#include <BearLibTerminal.h>

#include <string>

#include "./Controls.h"
#include "components/ColorComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"

void MainMenuScene::PrintMessage(int current_x, int current_y, const char* message) {
  if (y == current_y) terminal_color("white");
  terminal_print(current_x, current_y, message);
  terminal_color("gray");
}

void MainMenuScene::OnCreate() {
  ctx_->health_ = 100;
  ctx_->bullets_ = 0;
  ctx_->amount_of_steps_ = 0;
  ctx_->score_ = 0;
  ctx_->is_poisoning_ = false;

  for (auto it = ctx_->visited_levels_.begin(); it != ctx_->visited_levels_.end(); ++it) {
    it->second = false;
  }
}

void MainMenuScene::OnRender() {
  terminal_clear();

  terminal_color("white");
  terminal_print(x, y, "->");
  terminal_color("gray");

  PrintMessage(x + 2, min_y, "Story mode");
  PrintMessage(x + 2, min_y + 1, "Battlefield");
  PrintMessage(x + 2, min_y + 2, "Leaderboard");
  PrintMessage(x + 2, min_y + 3, "Graphic");
  PrintMessage(x + 2, min_y + 4, "Exit");

  if (controls_.IsPressed(TK_UP)) {
    y--;
    if (y < min_y) y = max_y;
  }
  if (controls_.IsPressed(TK_DOWN)) {
    y++;
    if (y > max_y) y = min_y;
  }

  if (y == min_y + 3) {
    if (ctx_->is_graphic) terminal_color("white");
    terminal_print(x + 15, min_y + 3, "On");
    terminal_color("gray");

    if (!ctx_->is_graphic) terminal_color("white");
    terminal_print(x + 19, min_y + 3, "Off");
    terminal_color("gray");
  }

  if (controls_.IsPressed(TK_ENTER)) {
    if (y == min_y) ctx_->scene_ = ctx_->levels_[2];
    if (y == min_y + 1) ctx_->scene_ = ctx_->levels_[1];
    if (y == min_y + 2) ctx_->scene_ = ctx_->levels_[static_cast<int>(ctx_->levels_.size() - 3)];
    if (y == min_y + 3) ctx_->is_graphic = !ctx_->is_graphic;
    if (y == min_y + 4) ctx_->is_exit = true;
  }

  if (y == min_y + 3 && (controls_.IsPressed(TK_RIGHT) || controls_.IsPressed(TK_LEFT)))
    ctx_->is_graphic = !ctx_->is_graphic;

  terminal_refresh();
}

void MainMenuScene::OnExit() {}

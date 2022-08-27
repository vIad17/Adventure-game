#include "scenes/GameOverScene.h"

#include <BearLibTerminal.h>

#include <string>

void GameOverScene::OnCreate() {}

void GameOverScene::OnRender() {
  terminal_clear();

  terminal_color("white");

  std::string steps = "Steps: " + std::to_string(ctx_->amount_of_steps_);
  std::string score = "Scores: " + std::to_string(ctx_->score_);

  terminal_print(35, 11, "Game over");
  terminal_print(35, 15, steps.c_str());
  terminal_print(35, 16, score.c_str());

  terminal_color("white");
  terminal_print(x, y, "->");

  terminal_print(x + 2, min_y, "Main menu");

  if (controls_.IsPressed(TK_UP)) {
    y--;
    if (y < min_y) y = max_y;
  }
  if (controls_.IsPressed(TK_DOWN)) {
    y++;
    if (y > max_y) y = min_y;
  }

  if (controls_.IsPressed(TK_ENTER)) {
    if (y == min_y) ctx_->scene_ = ctx_->levels_[0];
  }

  terminal_refresh();
}

void GameOverScene::OnExit() {}

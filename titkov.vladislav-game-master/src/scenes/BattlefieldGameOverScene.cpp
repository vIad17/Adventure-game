#include "scenes/BattlefieldGameOverScene.h"

#include <BearLibTerminal.h>

#include <string>

void BattlefieldGameOverScene::PrintMessage(int current_x, int current_y, const char* message) {
  if (y == current_y) terminal_color("white");
  terminal_print(current_x, current_y, message);
  terminal_color("gray");
}

void BattlefieldGameOverScene::OnCreate() {
  ctx_->attempts_++;
  for (int i = 0; i < 3; i++) {
    if (ctx_->score_ >= ctx_->score_leaders_[i]) {
      for (int j = 2; j > i; j--) {
        ctx_->score_leaders_[j] = ctx_->score_leaders_[j - 1];
      }
      ctx_->score_leaders_[i] = ctx_->score_;
      break;
    }
  }
}

void BattlefieldGameOverScene::OnRender() {
  terminal_clear();

  terminal_color("white");

  std::string steps = "Steps: " + std::to_string(ctx_->amount_of_steps_);
  std::string score = "Scores: " + std::to_string(ctx_->score_);

  terminal_print(35, 11, "Game over");
  terminal_print(35, 15, steps.c_str());
  terminal_print(35, 16, score.c_str());

  terminal_color("white");
  terminal_print(x, y, "->");
  terminal_color("gray");

  PrintMessage(x + 2, min_y, "Leaderboard");
  PrintMessage(x + 2, min_y + 1, "Main menu");

  if (controls_.IsPressed(TK_UP)) {
    y--;
    if (y < min_y) y = max_y;
  }
  if (controls_.IsPressed(TK_DOWN)) {
    y++;
    if (y > max_y) y = min_y;
  }

  if (controls_.IsPressed(TK_ENTER)) {
    if (y == min_y) ctx_->scene_ = ctx_->levels_[static_cast<int>(ctx_->levels_.size() - 3)];
    if (y == min_y + 1) ctx_->scene_ = ctx_->levels_[0];
  }

  terminal_refresh();
}

void BattlefieldGameOverScene::OnExit() {}

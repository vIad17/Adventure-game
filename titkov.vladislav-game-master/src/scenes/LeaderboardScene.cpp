#include "scenes/LeaderboardScene.h"

#include <BearLibTerminal.h>

#include <string>

void LeaderboardScene::OnCreate() {
}

void LeaderboardScene::OnRender() {
  terminal_clear();

  terminal_color("white");

  std::string creators_score = "1)Сreator of the game : 999999999999999999";
  std::string asian_score = "2)That asian guy      : 1849064306600";

  terminal_print(35, 5, "Leaders");
  terminal_print(20, 10, creators_score.c_str());
  terminal_print(20, 11, asian_score.c_str());

  for (int i = 0; i < 3 && i < ctx_->attempts_; i++) {
    std::string players_score =
        std::to_string(i + 3) + ")You                 : " + std::to_string(ctx_->score_leaders_[i]);
    terminal_print(20, 12 + i, players_score.c_str());
  }

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

void LeaderboardScene::OnExit() {}

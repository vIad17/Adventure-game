#include "scenes/WinGameScene.h"

#include <BearLibTerminal.h>

#include <string>

void WinGameScene::OnCreate() {
}

void WinGameScene::OnRender() {
  terminal_clear();

  terminal_color("white");

  std::string steps = "Steps: " + std::to_string(ctx_->amount_of_steps_);
  std::string score = "Score: " + std::to_string(ctx_->score_);

  terminal_print(35, 11, "You Win!");
  terminal_print(30, 15, steps.c_str());
  terminal_print(30, 16, score.c_str());

  terminal_refresh();
}

void WinGameScene::OnExit() {}

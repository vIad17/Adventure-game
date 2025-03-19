#include "scenes/PauseScene.h"

#include <BearLibTerminal.h>

#include <string>

#include "./Controls.h"
#include "components/ColorComponent.h"
#include "components/TextureComponent.h"
#include "components/TransformComponent.h"

void PauseScene::PrintMessage(int current_x, int current_y, const char* message) {
  if (y == current_y) terminal_color("white");
  terminal_print(current_x, current_y, message);
  terminal_color("gray");
}

void PauseScene::OnCreate() {
}

void PauseScene::OnRender() {
  terminal_clear();

  terminal_color("white");
  terminal_print(pause_text_x, pause_text_y, "Pause");

  terminal_print(x, y, "->");
  terminal_color("gray");

  PrintMessage(x + 2, min_y, "Resume");
  PrintMessage(x + 2, min_y + 1, "Graphic");
  PrintMessage(x + 2, min_y + 2, "Main menu");

  if (controls_.IsPressed(TK_UP)) {
    y--;
    if (y < min_y) y = max_y;
  }
  if (controls_.IsPressed(TK_DOWN)) {
    y++;
    if (y > max_y) y = min_y;
  }

  if (y == min_y + 1) {
    if (ctx_->is_graphic) terminal_color("white");
    terminal_print(x + 15, min_y + 1, "On");
    terminal_color("gray");

    if (!ctx_->is_graphic) terminal_color("white");
    terminal_print(x + 19, min_y + 1, "Off");
    terminal_color("gray");
  }

  if (controls_.IsPressed(TK_ENTER)) {
    if (y == min_y) ctx_->scene_ = ctx_->prev_scene_;
    if (y == min_y + 1) ctx_->is_graphic = !ctx_->is_graphic;
    if (y == min_y + 2) ctx_->scene_ = ctx_->levels_[0];
  }

  if (y == min_y + 3 && (controls_.IsPressed(TK_RIGHT) || controls_.IsPressed(TK_LEFT)))
    ctx_->is_graphic = !ctx_->is_graphic;

  terminal_refresh();
}

void PauseScene::OnExit() {}

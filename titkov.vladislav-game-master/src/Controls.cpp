#include <BearLibTerminal.h>

#include "./Controls.h"

bool Controls::IsMove() const {
  return is_move_up_ || is_move_down_ || is_move_left_ || is_move_right_;
}

bool Controls::IsMoveRight() const {
  return is_move_right_;
}

bool Controls::IsMoveLeft() const {
  return is_move_left_;
}

bool Controls::IsMoveUp() const {
  return is_move_up_;
}

bool Controls::IsMoveDown() const {
  return is_move_down_;
}

bool Controls::IsExit() const {
  return is_exit_;
}

void Controls::SetIsMove(bool b) {
  is_move_up_ = is_move_down_ = is_move_left_ = is_move_right_ = b;
}

void Controls::SetIsMoveRight(bool b) {
  is_move_right_ = b;
}

void Controls::SetIsMoveLeft(bool b) {
  is_move_left_ = b;
}

void Controls::SetIsMoveUp(bool b) {
  is_move_up_ = b;
}

void Controls::SetIsMoveDown(bool b) {
  is_move_down_ = b;
}

void Controls::Update() {
  is_move_right_ = false;
  is_move_left_ = false;
  is_move_up_ = false;
  is_move_down_ = false;
  is_exit_ = false;

  if (terminal_has_input()) {
    auto key = terminal_read();
    if (key == TK_RIGHT) is_move_right_ = true;
    if (key == TK_LEFT) is_move_left_ = true;
    if (key == TK_UP) is_move_up_ = true;
    if (key == TK_DOWN) is_move_down_ = true;

    if (key == TK_CLOSE || key == TK_ESCAPE) is_exit_ = true;
  }
}

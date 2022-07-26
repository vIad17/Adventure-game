#include <BearLibTerminal.h>

#include "./Player.h"

void Player::Render() {
  terminal_put(x_, y_, '@');
  terminal_printf(40, 0, "Health: %d", health_);
  terminal_printf(70, 0, "Steps: %d", steps_);
}

void Player::Move() {
  if (health_ > 0) {
    if (controls_.IsMoveRight()) x_++;
    if (controls_.IsMoveLeft()) x_--;
    if (controls_.IsMoveUp()) y_--;
    if (controls_.IsMoveDown()) y_++;

    if (controls_.IsMove()) {
      steps_++;
      if (poison) {
        Damage(1);
      }
    }
  }
}

void Player::Update() {
  Move();
  Render();
}

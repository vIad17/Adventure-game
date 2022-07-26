#include <BearLibTerminal.h>

#include "./CollisionManager.h"

void CollisionManager::Update() {
  for (unsigned int i = 0; i < walls_.size(); i++) {
    if (player_.GetX() + 1 == walls_[i].GetX() && player_.GetY() == walls_[i].GetY()) {
        controls_.SetIsMoveRight(false);
    }
    else if (player_.GetX() - 1 == walls_[i].GetX() && player_.GetY() == walls_[i].GetY()) {
      controls_.SetIsMoveLeft(false);
    }
    else if (player_.GetX()  == walls_[i].GetX() && player_.GetY() - 1 == walls_[i].GetY()) {
      controls_.SetIsMoveUp(false);
    }
    else if (player_.GetX() == walls_[i].GetX() && player_.GetY() + 1 == walls_[i].GetY()) {
      controls_.SetIsMoveDown(false);
    }

    walls_[i].Update();
  }
}

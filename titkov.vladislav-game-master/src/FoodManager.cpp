#include <BearLibTerminal.h>

#include "./FoodManager.h"

void FoodManager::Update() {
  for (unsigned int i = 0; i < food_.size(); i++) {
    if (player_.GetX() == food_[i].GetX() && player_.GetY() == food_[i].GetY()) {
      player_.Heal(25);
      food_.erase(food_.begin() + i);
    }

    food_[i].Update();
  }
}

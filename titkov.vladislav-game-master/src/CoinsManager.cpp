#include <BearLibTerminal.h>

#include "./CoinsManager.h"

void CoinsManager::Update() {
  for (unsigned int i = 0; i < coins_.size(); i++) {
    if (player_.GetX() == coins_[i].GetX() && player_.GetY() == coins_[i].GetY()) {
      c++;
      coins_.erase(coins_.begin() + i);
    }

    coins_[i].Update();
  }

  terminal_printf(1, 0, "Coins: %d", c);
}

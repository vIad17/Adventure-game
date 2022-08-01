#ifndef INCLUDE_COINSMANAGER_H_
#define INCLUDE_COINSMANAGER_H_

#include <vector>

#include "./Coin.h"
#include "./Player.h"

class CoinsManager {
  const Player &player_;
  std::vector<Coin> coins_;

  int c = 0;

 public:
  CoinsManager(const Player &player, std::vector<Coin> coins) : player_(player), coins_(coins) {}

  void Update();
};

#endif  // INCLUDE_COINSMANAGER_H_

#ifndef INCLUDE_FOODMANAGER_H_
#define INCLUDE_FOODMANAGER_H_

#include <vector>

#include "./Food.h"
#include "./Player.h"

class FoodManager {
  Player &player_;
  std::vector<Food> food_;

 public:
  FoodManager(Player &player, std::vector<Food> food) : player_(player), food_(food) {}

  void Update();
};

#endif  // INCLUDE_FOODMANAGER_H_

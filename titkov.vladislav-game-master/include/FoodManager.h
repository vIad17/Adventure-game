#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_FOODMANAGER_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_FOODMANAGER_H_

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

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_FOODMANAGER_H_

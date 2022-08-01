#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <vector>

#include "./IReader.h"
#include "./Coin.h"
#include "./Food.h"
#include "./Player.h"
#include "./Wall.h"

class Reader : IReader{
  std::vector<Coin> &coins_;
  std::vector<Food> &food_;
  std::vector<Wall> &walls_;
  Player &player_;

 public:
  Reader(std::vector<Coin> &coins, std::vector<Food> &food, std::vector<Wall> &walls, Player &player)
      : coins_(coins), food_(food), walls_(walls), player_(player) {}
  void ReadFile();
};

#endif  // INCLUDE_READER_H_

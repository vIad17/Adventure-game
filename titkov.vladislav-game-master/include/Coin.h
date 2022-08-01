#ifndef INCLUDE_COIN_H_
#define INCLUDE_COIN_H_

#include "./UObject.h"

class Coin : public UObject {
 public:
  Coin(int x, int y) {
    x_ = x, y_ = y;
    symbol = '$';
  }
};

#endif  // INCLUDE_COIN_H_

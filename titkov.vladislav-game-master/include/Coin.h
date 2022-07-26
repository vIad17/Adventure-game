#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_COIN_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_COIN_H_

#include "./UObject.h"

class Coin : public UObject {
 public:
  Coin(int x, int y) {
    x_ = x, y_ = y;
    symbol = '$';
  }
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_COIN_H_

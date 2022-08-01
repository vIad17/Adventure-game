#ifndef INCLUDE_FOOD_H_
#define INCLUDE_FOOD_H_

#include "./UObject.h"

class Food : public UObject {
 public:
  Food(int x, int y) {
    x_ = x, y_ = y;
    symbol = '%';
  }
};

#endif  // INCLUDE_FOOD_H_

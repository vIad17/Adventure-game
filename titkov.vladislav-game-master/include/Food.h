#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_FOOD_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_FOOD_H_

#include "./UObject.h"

class Food : public UObject {
 public:
  Food(int x, int y) {
    x_ = x, y_ = y;
    symbol = '%';
  }
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_FOOD_H_

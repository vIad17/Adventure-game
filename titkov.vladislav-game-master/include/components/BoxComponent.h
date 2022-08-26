#ifndef INCLUDE_COMPONENTS_BOXCOMPONENT_H_
#define INCLUDE_COMPONENTS_BOXCOMPONENT_H_

#include "ecs/Component.h"

class BoxComponent : public IComponent {
 public:
  int bullet_count_ = 0;
  int food_count_ = 0;
  bool flag = false;

  explicit BoxComponent(int bullet_count, int food_count) : bullet_count_(bullet_count), food_count_(food_count) {}
};

#endif  // INCLUDE_COMPONENTS_BOXCOMPONENT_H_

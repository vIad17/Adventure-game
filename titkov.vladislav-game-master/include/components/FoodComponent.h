#ifndef INCLUDE_COMPONENTS_FOODCOMPONENT_H_
#define INCLUDE_COMPONENTS_FOODCOMPONENT_H_

#include "ecs/component.h"

class FoodComponent : public IComponent {
 public:
  int heal_;

  explicit FoodComponent(int heal) : heal_(heal) {}
};

#endif  // INCLUDE_COMPONENTS_FOODCOMPONENT_H_

#ifndef INCLUDE_COMPONENTS_POISONCOMPONENT_H_
#define INCLUDE_COMPONENTS_POISONCOMPONENT_H_

#include "ecs/component.h"

class PoisonComponent : public IComponent {
 public:
  unsigned int delay_;

  explicit PoisonComponent(unsigned int delay) : delay_(delay) {}
};

#endif  // INCLUDE_COMPONENTS_POISONCOMPONENT_H_

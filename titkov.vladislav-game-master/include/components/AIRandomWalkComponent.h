#ifndef INCLUDE_COMPONENTS_AIRANDOMWALKCOMPONENT_H_
#define INCLUDE_COMPONENTS_AIRANDOMWALKCOMPONENT_H_

#include "ecs/Component.h"

class AIRandomWalkComponent : public IComponent {
 public:
  int delay_;

  explicit AIRandomWalkComponent(int delay) : delay_(delay) {}

  int i_ = delay_;
};

#endif  // INCLUDE_COMPONENTS_AIRANDOMWALKCOMPONENT_H_

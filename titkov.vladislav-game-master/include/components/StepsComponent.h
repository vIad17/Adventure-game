#ifndef INCLUDE_COMPONENTS_STEPSCOMPONENT_H_
#define INCLUDE_COMPONENTS_STEPSCOMPONENT_H_

#include "./ecs/component.h"

class StepsComponent : public IComponent {
 public:
  unsigned int steps_;

  explicit StepsComponent(unsigned  int steps) : steps_(steps) {}
};


#endif  // INCLUDE_COMPONENTS_STEPSCOMPONENT_H_

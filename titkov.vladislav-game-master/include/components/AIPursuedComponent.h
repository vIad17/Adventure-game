#ifndef INCLUDE_COMPONENTS_AIPURSUEDCOMPONENT_H_
#define INCLUDE_COMPONENTS_AIPURSUEDCOMPONENT_H_

#include "ecs/Component.h"

class AIPursuedComponent : public IComponent {
 public:
  int delay_;
  int i_;
  int vision_radius_;

  explicit AIPursuedComponent(int delay, int vision_radius) : delay_(delay), i_(delay), vision_radius_(vision_radius) {}
};

#endif  // INCLUDE_COMPONENTS_AIPURSUEDCOMPONENT_H_

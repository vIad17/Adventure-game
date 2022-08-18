#ifndef INCLUDE_COMPONENTS_MOVEMENTCOMPONENT_H_
#define INCLUDE_COMPONENTS_MOVEMENTCOMPONENT_H_

#include <./ecs/component.h>

class MovementComponent : public IComponent {
 public:
  int x_;
  int y_;

  explicit MovementComponent(int x, int y) : x_(x), y_(y){}
};

#endif  // INCLUDE_COMPONENTS_MOVEMENTCOMPONENT_H_

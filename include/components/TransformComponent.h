#ifndef INCLUDE_COMPONENTS_TRANSFORMCOMPONENT_H_
#define INCLUDE_COMPONENTS_TRANSFORMCOMPONENT_H_

#include "ecs/Component.h"

class TransformComponent : public IComponent {
 public:
  int x_;
  int y_;

  explicit TransformComponent(int x, int y) : x_(x), y_(y) {}
};


#endif  // INCLUDE_COMPONENTS_TRANSFORMCOMPONENT_H_

#ifndef INCLUDE_COMPONENTS_COLLISIONCOMPONENT_H_
#define INCLUDE_COMPONENTS_COLLISIONCOMPONENT_H_

#include <string>

#include "./ecs/component.h"

class CollisionComponent : public IComponent {
 public:
  std::string collision_type_;

  explicit CollisionComponent(std::string collision_type) : collision_type_(collision_type) {}
};

#endif  // INCLUDE_COMPONENTS_COLLISIONCOMPONENT_H_

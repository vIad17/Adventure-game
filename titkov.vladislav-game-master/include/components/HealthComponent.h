#ifndef INCLUDE_COMPONENTS_HEALTHCOMPONENT_H_
#define INCLUDE_COMPONENTS_HEALTHCOMPONENT_H_

#include "./ecs/component.h"

class HealthComponent : public IComponent {
 public:
  int health_;
  int max_health_;

  explicit HealthComponent(int health, int max_health) : health_(health), max_health_(max_health) {}
};

#endif  // INCLUDE_COMPONENTS_HEALTHCOMPONENT_H_

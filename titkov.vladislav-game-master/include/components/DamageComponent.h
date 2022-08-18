#ifndef INCLUDE_COMPONENTS_DAMAGECOMPONENT_H_
#define INCLUDE_COMPONENTS_DAMAGECOMPONENT_H_

#include "./ecs/component.h"

class DamageComponent : public IComponent {
 public:
  int damage_;

  explicit DamageComponent(int damage) : damage_(damage) {}
};

#endif  // INCLUDE_COMPONENTS_DAMAGECOMPONENT_H_

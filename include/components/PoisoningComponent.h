#ifndef INCLUDE_COMPONENTS_POISONINGCOMPONENT_H_
#define INCLUDE_COMPONENTS_POISONINGCOMPONENT_H_

#include "ecs/Component.h"

class PoisoningComponent : public IComponent {
 public:
  bool is_poisoning_;

  explicit PoisoningComponent(bool is_poisoning) : is_poisoning_(is_poisoning) {}
};

#endif  // INCLUDE_COMPONENTS_POISONINGCOMPONENT_H_

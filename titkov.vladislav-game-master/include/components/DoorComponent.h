#ifndef INCLUDE_COMPONENTS_DOORCOMPONENT_H_
#define INCLUDE_COMPONENTS_DOORCOMPONENT_H_

#include "ecs/Component.h"

class DoorComponent : public IComponent {
 public:
  bool is_it_next_level_;

  explicit DoorComponent(bool is_it_next_level) : is_it_next_level_(is_it_next_level) {}
};

#endif  // INCLUDE_COMPONENTS_DOORCOMPONENT_H_

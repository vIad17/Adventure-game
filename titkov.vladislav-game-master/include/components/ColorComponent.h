#ifndef INCLUDE_COMPONENTS_COLORCOMPONENT_H_
#define INCLUDE_COMPONENTS_COLORCOMPONENT_H_

#include <string>

#include "ecs/Component.h"

class ColorComponent : public IComponent {
 public:
  const char* color_;

  explicit ColorComponent(const char* color) : color_(color) {}
};

#endif  // INCLUDE_COMPONENTS_COLORCOMPONENT_H_

#ifndef INCLUDE_COMPONENTS_GRAPHICCOMPONENT_H_
#define INCLUDE_COMPONENTS_GRAPHICCOMPONENT_H_

#include "ecs/Component.h"

class GraphicComponent : public IComponent {
 public:
  const char symbol_;

  explicit GraphicComponent(const char symbol) : symbol_(symbol) {}
};


#endif  // INCLUDE_COMPONENTS_GRAPHICCOMPONENT_H_

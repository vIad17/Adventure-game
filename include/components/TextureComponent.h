#ifndef INCLUDE_COMPONENTS_TEXTURECOMPONENT_H_
#define INCLUDE_COMPONENTS_TEXTURECOMPONENT_H_

#include "ecs/Component.h"

class TextureComponent : public IComponent {
 public:
  char symbol_;

  explicit TextureComponent(char symbol) : symbol_(symbol) {}
};


#endif  // INCLUDE_COMPONENTS_TEXTURECOMPONENT_H_

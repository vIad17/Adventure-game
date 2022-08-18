#ifndef INCLUDE_COMPONENTS_TEXTURECOMTONENT_H_
#define INCLUDE_COMPONENTS_TEXTURECOMTONENT_H_

#include "./ecs/component.h"

class TextureComponent : public IComponent {
 public:
  char symbol_;

  explicit TextureComponent(char symbol) : symbol_(symbol) {}
};


#endif  // INCLUDE_COMPONENTS_TEXTURECOMTONENT_H_

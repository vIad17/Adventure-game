#ifndef INCLUDE_COMPONENTS_BULLETCOUNTCOMPONENT_H_
#define INCLUDE_COMPONENTS_BULLETCOUNTCOMPONENT_H_

#include "./ecs/component.h"

class BulletCountComponent : public IComponent {
 public:
  int bullet_count_ = 0;

  explicit BulletCountComponent(int bullet_count) : bullet_count_(bullet_count) {}
};

#endif  // INCLUDE_COMPONENTS_BULLETCOUNTCOMPONENT_H_

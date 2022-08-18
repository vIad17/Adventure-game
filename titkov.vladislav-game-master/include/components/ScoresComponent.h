#ifndef INCLUDE_COMPONENTS_SCORESCOMPONENT_H_
#define INCLUDE_COMPONENTS_SCORESCOMPONENT_H_

#include "ecs/component.h"

class ScoresComponent : public IComponent {
 public:
  int scores_;

  explicit ScoresComponent(int scores) : scores_(scores) {}
};

#endif  // INCLUDE_COMPONENTS_SCORESCOMPONENT_H_

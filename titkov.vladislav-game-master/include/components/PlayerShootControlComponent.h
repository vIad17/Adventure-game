#ifndef INCLUDE_COMPONENTS_PLAYERSHOOTCONTROLCOMPONENT_H_
#define INCLUDE_COMPONENTS_PLAYERSHOOTCONTROLCOMPONENT_H_

#include "./ecs/component.h"

class PlayerShootControlComponent : public IComponent {
 public:
  int shoot_right_button_;
  int shoot_left_button_;
  int shoot_up_button_;
  int shoot_down_button_;

  explicit PlayerShootControlComponent(int shoot_right_button, int shoot_left_button, int shoot_up_button,
                                      int shoot_down_button)
      : shoot_right_button_(shoot_right_button),
        shoot_left_button_(shoot_left_button),
        shoot_up_button_(shoot_up_button),
        shoot_down_button_(shoot_down_button) {}
};

#endif  // INCLUDE_COMPONENTS_PLAYERSHOOTCONTROLCOMPONENT_H_

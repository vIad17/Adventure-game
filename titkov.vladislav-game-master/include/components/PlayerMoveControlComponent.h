#ifndef INCLUDE_COMPONENTS_PLAYERMOVECONTROLCOMPONENT_H_
#define INCLUDE_COMPONENTS_PLAYERMOVECONTROLCOMPONENT_H_

#include "ecs/Component.h"

class PlayerMoveControlComponent : public IComponent {
 public:
  int move_right_button_;
  int move_left_button_;
  int move_up_button_;
  int move_down_button_;

  explicit PlayerMoveControlComponent(int move_right_button, int move_left_button, int move_up_button,
                                      int move_down_button)
      : move_right_button_(move_right_button),
        move_left_button_(move_left_button),
        move_up_button_(move_up_button),
        move_down_button_(move_down_button) {}
};

#endif  // INCLUDE_COMPONENTS_PLAYERMOVECONTROLCOMPONENT_H_

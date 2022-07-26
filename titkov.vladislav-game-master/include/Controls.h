#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_CONTROLS_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_CONTROLS_H_

class Controls {
  bool is_move_up_;
  bool is_move_down_;
  bool is_move_left_;
  bool is_move_right_;
  bool is_exit_;

 public:
  bool IsMove() const;
  bool IsMoveRight() const;
  bool IsMoveLeft() const;
  bool IsMoveUp() const;
  bool IsMoveDown() const;

  bool IsExit() const;

  void SetIsMove(bool b);
  void SetIsMoveRight(bool b);
  void SetIsMoveLeft(bool b);
  void SetIsMoveUp(bool b);
  void SetIsMoveDown(bool b);

  void Update();
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_CONTROLS_H_

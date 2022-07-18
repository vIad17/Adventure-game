#include <BearLibTerminal.h>

class Controls
{
  bool is_move_up_;
  bool is_move_down_;
  bool is_move_left_;
  bool is_move_right_;
  bool is_exit_;

public:
  bool IsMoveUp() const { return is_move_up_; }
  bool IsMoveDown() const { return is_move_down_; }
  bool IsMoveLeft() const { return is_move_left_; }
  bool IsMoveRight() const { return is_move_right_; }
  bool IsExit() const { return is_exit_; }

  void Update() 
  {
    is_move_up_ = false;
    is_move_down_ = false;
    is_move_left_ = false;
    is_move_right_ = false;
    is_exit_ = false;

    if (terminal_has_input())
    {
      auto key = terminal_read();

      if (key == TK_UP) is_move_up_ = true;
      if (key == TK_DOWN) is_move_down_ = true;
      if (key == TK_LEFT) is_move_left_ = true;
      if (key == TK_RIGHT) is_move_right_ = true;
      if (key == TK_CLOSE || key == TK_ESCAPE) is_exit_ = true;
    }
  }
};

class Player
{
  const Controls &controls_;

  int x_;
  int y_;

  void Render() 
  {
    terminal_put(x_, y_, '@'); 
  }

  void Move()
  {
    if (controls_.IsMoveUp()) y_--;
    if (controls_.IsMoveDown()) y_++;
    if (controls_.IsMoveLeft()) x_--;
    if (controls_.IsMoveRight()) x_++;
  }

public:
  Player(const Controls &controls, int x, int y) 
      : controls_(controls), x_(x), y_(y) {}

  int GetX() const { return x_; }
  int GetY() const { return y_; }

  void Update()
  {
    Move();
    Render();
  }
};


int main() {
  terminal_open();
  terminal_refresh();

  const int x = 40;
  const int y = 10;

  Controls controls;
  Player player{controls, x, y};

  while (true)
  {
    terminal_clear();

    controls.Update();
    if (controls.IsExit()) 
    {
      break;
    }

    player.Update();

    terminal_refresh();
  }

  terminal_close();
};

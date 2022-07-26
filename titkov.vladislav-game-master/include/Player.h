#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_PLAYER_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_PLAYER_H_

#include "./Controls.h"
#include "./Health.h"
#include "./UObject.h"

class Player : public Health, public UObject {
  const Controls &controls_;

  int steps_ = 0;

  void Render();

  void Move();

 public:
  Player(const Controls &controls, int x, int y, int health, int max_health) : controls_(controls) {
    health_ = health;
    max_health_ = max_health;
    x_ = x;
    y_ = y;
  }

  void Update();
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_PLAYER_H_

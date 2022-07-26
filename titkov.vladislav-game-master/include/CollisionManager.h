#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_COLLISIONMANAGER_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_COLLISIONMANAGER_H_

#include <vector>

#include "./Controls.h"
#include "./Player.h"
#include "./Wall.h"

class CollisionManager {
  Controls &controls_;
  Player &player_;
  std::vector<Wall> walls_;

 public:
  CollisionManager(Controls &controls, Player &player, std::vector<Wall> walls)
      : controls_(controls), player_(player), walls_(walls) {}

  void Update();
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_COLLISIONMANAGER_H_

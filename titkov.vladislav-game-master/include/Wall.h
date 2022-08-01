#ifndef INCLUDE_WALL_H_
#define INCLUDE_WALL_H_

class Wall : public UObject {
 public:
  Wall(int x, int y) {
    x_ = x, y_ = y;
    symbol = '#';
  }
};

#endif  // INCLUDE_WALL_H_

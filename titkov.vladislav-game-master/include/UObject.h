#ifndef INCLUDE_UOBJECT_H_
#define INCLUDE_UOBJECT_H_

class UObject {
 public:
  int x_;
  int y_;

  char symbol;

  int GetX() const;
  int GetY() const;

  void Update();
};

#endif  // INCLUDE_UOBJECT_H_

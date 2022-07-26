#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_UOBJECT_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_UOBJECT_H_

class UObject {
 public:
  int x_;
  int y_;

  char symbol;

  int GetX() const;
  int GetY() const;

  void Update();
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_UOBJECT_H_

#ifndef _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_HEALTH_H_
#define _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_HEALTH_H_

class Health {
 public:
  int health_;
  int max_health_;

  bool poison = false;

  void Heal(int a);
  void Damage(int a);
  void Poison();
};

#endif  // _HOME_VLAD_CLIONPROJECTS_UNTITLED_INCLUDE_HEALTH_H_

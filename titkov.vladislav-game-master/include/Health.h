#ifndef INCLUDE_HEALTH_H_
#define INCLUDE_HEALTH_H_

class Health {
 public:
  int health_;
  int max_health_;

  bool poison = false;

  void Heal(int a);
  void Damage(int a);
  void Poison();
};

#endif  // INCLUDE_HEALTH_H_

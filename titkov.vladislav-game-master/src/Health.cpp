#include <BearLibTerminal.h>

#include "./Health.h"

void Health::Heal(int a) {
  if (health_ + a > max_health_)
    health_ = max_health_;
  else
    health_ += a;
}

void Health::Damage(int a) {
  if (health_ - a < 0)
    health_ = 0;
  else
    health_ -= a;
}

void Health::Poison() {
  poison = true;
}

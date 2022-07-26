#include <BearLibTerminal.h>

#include "./UObject.h"

int UObject::GetX() const {
  return x_;
}
int UObject::GetY() const {
  return y_;
}

void UObject::Update() {
  terminal_put(x_, y_, symbol);
}

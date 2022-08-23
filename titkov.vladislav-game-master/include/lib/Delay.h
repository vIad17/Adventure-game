#ifndef INCLUDE_LIB_DELAY_H_
#define INCLUDE_LIB_DELAY_H_

#include <string>
#include <utility>
#include <vector>

class Delay {
 public:
  int i = 0;
  int delay_;

  explicit Delay(int delay) : delay_(delay) {}

  bool IsReady() {
    return i == delay_;
  }

  void Update() {
    if (IsReady()) i = 0;
    else i++;
  }

  int score_{0};
  int amount_of_steps_{0};
};

#endif  // INCLUDE_LIB_DELAY_H_

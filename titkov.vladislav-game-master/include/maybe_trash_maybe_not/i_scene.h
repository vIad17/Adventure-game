#ifndef INCLUDE_MAYBE_TRASH_MAYBE_NOT_I_SCENE_H_
#define INCLUDE_MAYBE_TRASH_MAYBE_NOT_I_SCENE_H_

#include "maybe_trash_maybe_not/context.h"

class IScene {
 protected:
  Context* const ctx_;

 public:
  explicit IScene(Context* const ctx) : ctx_(ctx) {}
  virtual ~IScene() = default;

  virtual void OnCreate() = 0;
  virtual void OnRender() = 0;
  virtual void OnExit() = 0;
};

#endif  // INCLUDE_MAYBE_TRASH_MAYBE_NOT_I_SCENE_H_

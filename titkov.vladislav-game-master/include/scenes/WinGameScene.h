#ifndef INCLUDE_SCENES_WINGAMESCENE_H_
#define INCLUDE_SCENES_WINGAMESCENE_H_

#include "./Controls.h"
#include "lib/IScene.h"

class WinGameScene : public IScene {
  const Controls &controls_;

 public:
  explicit WinGameScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_WINGAMESCENE_H_

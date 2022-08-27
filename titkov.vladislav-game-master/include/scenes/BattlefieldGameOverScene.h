#ifndef INCLUDE_SCENES_BATTLEFIELDGAMEOVERSCENE_H_
#define INCLUDE_SCENES_BATTLEFIELDGAMEOVERSCENE_H_

#include "./Controls.h"
#include "lib/IScene.h"

class BattlefieldGameOverScene : public IScene {
  const Controls &controls_;

  int x = 33;
  int y = 20;
  int index = 1;
  int min_y = y;
  int max_y = y + index;

 public:
  explicit BattlefieldGameOverScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_BATTLEFIELDGAMEOVERSCENE_H_

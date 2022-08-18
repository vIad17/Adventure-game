#ifndef INCLUDE_SCENES_GAMEOVERSCENE_H_
#define INCLUDE_SCENES_GAMEOVERSCENE_H_

#include "./Controls.h"
#include "lib/i_scene.h"

class GameOverScene : public IScene {
  const Controls &controls_;

 public:
  explicit GameOverScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_GAMEOVERSCENE_H_

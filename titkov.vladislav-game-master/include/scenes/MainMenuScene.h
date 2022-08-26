#ifndef INCLUDE_SCENES_MAINMENUSCENE_H_
#define INCLUDE_SCENES_MAINMENUSCENE_H_

#include "./Controls.h"
#include "ecs/Engine.h"
#include "lib/IScene.h"

class MainMenuScene : public IScene {
  const Controls &controls_;

 protected:
  const Engine engine{};

  int x = 30;
  int y = 8;
  int index = 2;
  int min_y = y;
  int max_y = y + index;

 public:
  explicit MainMenuScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_MAINMENUSCENE_H_

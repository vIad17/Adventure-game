#ifndef INCLUDE_SCENES_MAINMENUSCENE_H_
#define INCLUDE_SCENES_MAINMENUSCENE_H_

#include "./Controls.h"
#include "ecs/Engine.h"
#include "lib/IScene.h"

class MainMenuScene : public IScene {
  const Controls &controls_;

 protected:
  const Engine engine{};

  int x = 31;
  int y = 9;
  int index = 4;
  int min_y = y;
  int max_y = y + index;

 private:
  void PrintMessage(int current_x, int current_y, const char *message);

 public:
  explicit MainMenuScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_MAINMENUSCENE_H_

#ifndef INCLUDE_SCENES_PAUSESCENE_H_
#define INCLUDE_SCENES_PAUSESCENE_H_

#include "./Controls.h"
#include "ecs/Engine.h"
#include "lib/IScene.h"

class PauseScene : public IScene {
  const Controls &controls_;

 protected:
  const Engine engine{};

  int x = 31;
  int y = 9;
  int pause_text_x = 33;
  int pause_text_y = 5;
  int index = 2;
  int min_y = y;
  int max_y = y + index;

 private:
  void PrintMessage(int current_x, int current_y, const char *message);

 public:
  explicit PauseScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_PAUSESCENE_H_

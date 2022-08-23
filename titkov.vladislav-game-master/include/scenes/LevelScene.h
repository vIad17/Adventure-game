#ifndef INCLUDE_SCENES_LEVELSCENE_H_
#define INCLUDE_SCENES_LEVELSCENE_H_

#include <fstream>
#include <string>

#include "./Controls.h"
#include "ecs/Engine.h"
#include "lib/IScene.h"

class LevelScene : public IScene {
  const Controls &controls_;
  std::string &file_;

 protected:
  const Engine engine{};

 public:
  explicit LevelScene(Context *const ctx, const Controls &controls, std::string &file)
      : IScene(ctx), controls_(controls), file_(file) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_LEVELSCENE_H_

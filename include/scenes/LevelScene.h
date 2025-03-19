#ifndef INCLUDE_SCENES_LEVELSCENE_H_
#define INCLUDE_SCENES_LEVELSCENE_H_

#include <fstream>
#include <string>

#include "./Controls.h"
#include "ecs/Engine.h"
#include "lib/IScene.h"

class LevelScene : public IScene {
  const Controls &controls_;
  const std::string &original_file_;
  const std::string &copy_file_;
 protected:
  const Engine engine{};

 public:
 public:
  explicit LevelScene(Context *const ctx, const Controls &controls, const std::string &original_file,
                            const std::string &copy_file)
      : IScene(ctx), controls_(controls), original_file_(original_file), copy_file_(copy_file) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_LEVELSCENE_H_

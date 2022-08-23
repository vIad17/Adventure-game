#ifndef INCLUDE_SCENES_BATTLEFIELDSCENE_H_
#define INCLUDE_SCENES_BATTLEFIELDSCENE_H_

#include <random>
#include <fstream>
#include <string>

#include "./Controls.h"
#include "ecs/Engine.h"
#include "lib/Delay.h"
#include "lib/IScene.h"

class BattlefieldScene : public IScene {
  const Controls &controls_;
  std::string &file_;

 protected:
  const Engine engine{};
  Delay enemy_delay = Delay(300);
  Delay snake_delay = Delay(350);
  Delay bullet_delay = Delay(150);
  Delay food_delay = Delay(800);
  Delay antidote_delay = Delay(1000);

  std::mt19937 random_generator_;

 public:
  explicit BattlefieldScene(Context *const ctx, const Controls &controls, std::string &file)
      : IScene(ctx), controls_(controls), file_(file) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_BATTLEFIELDSCENE_H_

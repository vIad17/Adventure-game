#ifndef INCLUDE_SCENES_LEADERBOARDSCENE_H_
#define INCLUDE_SCENES_LEADERBOARDSCENE_H_

#include "./Controls.h"
#include "lib/IScene.h"

class LeaderboardScene : public IScene {
  const Controls &controls_;

  int x = 33;
  int y = 20;
  int index = 0;
  int min_y = y;
  int max_y = y + index;

 public:
  explicit LeaderboardScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};

#endif  // INCLUDE_SCENES_LEADERBOARDSCENE_H_

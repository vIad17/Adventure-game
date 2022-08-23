#ifndef INCLUDE_SYSTEMS_GAMEOVERSYSTEM_H_
#define INCLUDE_SYSTEMS_GAMEOVERSYSTEM_H_

#include <vector>

#include "ecs/System.h"
#include "lib/Context.h"

class GameOverSystem : public ISystem{
 protected:
  void OnUpdate() override;

  Context *const ctx_;
 public:
  GameOverSystem(EntityManager *const entity_manager, SystemManager *const system_manager,
                 Context *const ctx) : ISystem(entity_manager, system_manager), ctx_(ctx) {}
};

#endif  // INCLUDE_SYSTEMS_GAMEOVERSYSTEM_H_

#ifndef INCLUDE_SYSTEMS_PLAYERMOVECONTROLSYSTEM_H_
#define INCLUDE_SYSTEMS_PLAYERMOVECONTROLSYSTEM_H_

#include "./Controls.h"
#include "ecs/system.h"

class Entity;

class PlayerMoveControlSystem : public ISystem {
  const Controls& controls_;

 protected:
  void OnUpdate() override;

 public:
  PlayerMoveControlSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                          const Controls& controls)
      : ISystem(entity_manager, system_manager), controls_(controls) {}
};

#endif  // INCLUDE_SYSTEMS_PLAYERMOVECONTROLSYSTEM_H_

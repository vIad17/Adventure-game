#ifndef INCLUDE_SYSTEMS_BULLETMANAGERSYSTEM_H_
#define INCLUDE_SYSTEMS_BULLETMANAGERSYSTEM_H_

#include "ecs/system.h"

class BulletManagerSystem : public ISystem {
 protected:
  void OnUpdate() override;

 public:
  BulletManagerSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
      : ISystem(entity_manager, system_manager) {}
};

#endif  // INCLUDE_SYSTEMS_BULLETMANAGERSYSTEM_H_

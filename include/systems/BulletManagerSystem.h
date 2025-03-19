#ifndef INCLUDE_SYSTEMS_BULLETMANAGERSYSTEM_H_
#define INCLUDE_SYSTEMS_BULLETMANAGERSYSTEM_H_

#include "ecs/System.h"
#include "lib/Context.h"

class BulletManagerSystem : public ISystem {
 protected:
  void OnUpdate() override;

  Context* const ctx_;

 public:
  BulletManagerSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* const ctx)
      : ISystem(entity_manager, system_manager), ctx_(ctx) {}
};

#endif  // INCLUDE_SYSTEMS_BULLETMANAGERSYSTEM_H_

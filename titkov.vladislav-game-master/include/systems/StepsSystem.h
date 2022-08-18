#ifndef INCLUDE_SYSTEMS_STEPSSYSTEM_H_
#define INCLUDE_SYSTEMS_STEPSSYSTEM_H_

#include "ecs/system.h"
#include "lib/context.h"

class StepsSystem : public ISystem{
 protected:
  void OnUpdate() override;

  Context* const ctx_;

 public:
  StepsSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* const ctx)
      : ISystem(entity_manager, system_manager), ctx_(ctx) {}
};

#endif  // INCLUDE_SYSTEMS_STEPSSYSTEM_H_

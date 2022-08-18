#ifndef INCLUDE_SYSTEMS_COLLISIONSYSTEM_H_
#define INCLUDE_SYSTEMS_COLLISIONSYSTEM_H_

#include "ecs/engine.h"
#include "ecs/system.h"
#include "lib/context.h"

class CollisionSystem : public ISystem {
 protected:
  void OnPreUpdate() override;

  Context* const ctx_;
  const Engine& engine_;

  unsigned int i = 0;
  unsigned int delay = 0;

 public:
  CollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* const ctx,
                  const Engine& engine)
      : ISystem(entity_manager, system_manager), ctx_(ctx), engine_(engine) {}
};

#endif  // INCLUDE_SYSTEMS_COLLISIONSYSTEM_H_

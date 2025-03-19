#ifndef INCLUDE_SYSTEMS_COLLISIONSYSTEM_H_
#define INCLUDE_SYSTEMS_COLLISIONSYSTEM_H_

#include "ecs/Engine.h"
#include "ecs/System.h"
#include "lib/Context.h"

class CollisionSystem : public ISystem {
 protected:
  void OnPreUpdate() override;

  Context* const ctx_;
  const Engine& engine_;
  unsigned int i = ctx_->poison_delay_;
  unsigned int delay = ctx_->poison_delay_;

 public:
  CollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* const ctx,
                  const Engine& engine)
      : ISystem(entity_manager, system_manager), ctx_(ctx), engine_(engine) {}
};

#endif  // INCLUDE_SYSTEMS_COLLISIONSYSTEM_H_

#ifndef INCLUDE_SYSTEMS_PAUSESYSTEM_H_
#define INCLUDE_SYSTEMS_PAUSESYSTEM_H_

#include <vector>

#include "./Controls.h"
#include "ecs/System.h"
#include "lib/Context.h"

class PauseSystem : public ISystem {
 protected:
  void OnUpdate() override;

  Context *const ctx_;
  const Controls &controls_;

 public:
  PauseSystem(EntityManager *const entity_manager, SystemManager *const system_manager, Context *const ctx,
              const Controls &controls)
      : ISystem(entity_manager, system_manager), ctx_(ctx), controls_(controls) {}
};

#endif  // INCLUDE_SYSTEMS_PAUSESYSTEM_H_

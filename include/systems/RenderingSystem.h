#ifndef INCLUDE_SYSTEMS_RENDERINGSYSTEM_H_
#define INCLUDE_SYSTEMS_RENDERINGSYSTEM_H_

#include "./ecs/System.h"
#include "lib/Context.h"

class RenderingSystem : public ISystem {
 protected:
  void OnPreUpdate() override;
  void OnUpdate() override;
  void OnPostUpdate() override;

  Context* const ctx_;

 public:
  RenderingSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* const ctx)
      : ISystem(entity_manager, system_manager), ctx_(ctx) {}
};

#endif  // INCLUDE_SYSTEMS_RENDERINGSYSTEM_H_

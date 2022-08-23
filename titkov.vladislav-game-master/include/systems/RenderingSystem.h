#ifndef INCLUDE_SYSTEMS_RENDERINGSYSTEM_H_
#define INCLUDE_SYSTEMS_RENDERINGSYSTEM_H_

#include "./ecs/System.h"

class RenderingSystem : public ISystem {
 protected:
  void OnPreUpdate() override;
  void OnUpdate() override;
  void OnPostUpdate() override;

 public:
  RenderingSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
      : ISystem(entity_manager, system_manager) {}
};

#endif  // INCLUDE_SYSTEMS_RENDERINGSYSTEM_H_

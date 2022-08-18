#ifndef INCLUDE_SYSTEMS_MOVEMENTSYSTEM_H_
#define INCLUDE_SYSTEMS_MOVEMENTSYSTEM_H_

#include <vector>

#include "ecs/system.h"

class MovementSystem : public ISystem{
 protected:
  void OnUpdate() override;

 public:
  MovementSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
      : ISystem(entity_manager, system_manager) {}
};

#endif  // INCLUDE_SYSTEMS_MOVEMENTSYSTEM_H_

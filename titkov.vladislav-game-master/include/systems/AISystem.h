#ifndef INCLUDE_SYSTEMS_AISYSTEM_H_
#define INCLUDE_SYSTEMS_AISYSTEM_H_

#include <random>

#include "ecs/system.h"

class AISystem : public ISystem {
 protected:
  void OnUpdate() override;

  std::mt19937 random_generator_;

 public:
  AISystem(EntityManager* const entity_manager, SystemManager* const system_manager)
      : ISystem(entity_manager, system_manager) {}
};

#endif  // INCLUDE_SYSTEMS_AISYSTEM_H_

#ifndef INCLUDE_SYSTEMS_BOXSYSTEM_H_
#define INCLUDE_SYSTEMS_BOXSYSTEM_H_

#include <random>

#include "ecs/Engine.h"
#include "ecs/System.h"
#include "lib/Context.h"

class BoxSystem : public ISystem {
 protected:
  void OnUpdate() override;

  std::mt19937 random_generator_;
  const Engine& engine_;

 public:
  BoxSystem(EntityManager* const entity_manager, SystemManager* const system_manager, const Engine& engine)
      : ISystem(entity_manager, system_manager), engine_(engine) {}
};

#endif  // INCLUDE_SYSTEMS_BOXSYSTEM_H_

#ifndef INCLUDE_SYSTEMS_PLAYERSHOOTCONTROLSYSTEM_H_
#define INCLUDE_SYSTEMS_PLAYERSHOOTCONTROLSYSTEM_H_

#include <vector>

#include "./Controls.h"
#include "ecs/System.h"
#include "ecs/Engine.h"

class Entity;

class PlayerShootControlSystem : public ISystem {
  const Controls& controls_;
  const Engine& engine_;

 protected:
  void OnUpdate() override;
  void Shoot(Entity* entity, int dx, int dy);
  std::vector<Entity*> bullets;

 public:
  PlayerShootControlSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                      const Controls& controls, const Engine& engine)
      : ISystem(entity_manager, system_manager), controls_(controls), engine_(engine) {}
};

#endif  // INCLUDE_SYSTEMS_PLAYERSHOOTCONTROLSYSTEM_H_

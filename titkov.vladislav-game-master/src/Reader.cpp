#include "./Reader.h"

#include <BearLibTerminal.h>

#include "components/AIPursuedComponent.h"
#include "components/AIRandomWalkComponent.h"
#include "components/BulletCountComponent.h"
#include "components/ColorComponent.h"
#include "components/DamageComponent.h"
#include "components/DoorComponent.h"
#include "components/FoodComponent.h"
#include "components/HealthComponent.h"
#include "components/MovementComponent.h"
#include "components/PlayerMoveControlComponent.h"
#include "components/PlayerShootControlComponent.h"
#include "components/PoisonComponent.h"
#include "components/PoisoningComponent.h"
#include "components/ScoresComponent.h"
#include "components/StepsComponent.h"
#include "components/TextureComtonent.h"
#include "components/TransformComponent.h"
#include "components/tags/AntidoteComponent.h"
#include "components/tags/BulletComponent.h"
#include "components/tags/EnemyComponent.h"
#include "components/tags/PlayerComponent.h"
#include "components/tags/WallComponent.h"

void Reader::ReadFile() {
  int x = 81;
  int y = 25;

  char myArray[x][y];

  if (file_) {
    for (int j = 0; j < y; j++) {
      for (int i = 0; i < x; i++) {
        file_ >> myArray[i][j];
        if (myArray[i][j] != '\'') {
          if (myArray[i][j] == '/')
            break;

          else if (myArray[i][j] == '$') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<BulletComponent>();
            entity->Add<ColorComponent>("green");
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('$');
          }

          else if (myArray[i][j] == '%') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<FoodComponent>(50);
            entity->Add<ColorComponent>("green");
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('%');
          }

          else if (myArray[i][j] == '&') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<AntidoteComponent>();
            entity->Add<ColorComponent>("green");
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('&');
          }

          else if (myArray[i][j] == '#') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<WallComponent>();
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('#');
          }

          else if (myArray[i][j] == '<') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<DoorComponent>(false);
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('<');
          }

          else if (myArray[i][j] == '>') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<DoorComponent>(true);
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('>');
          }

          else if (myArray[i][j] == '@') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<ColorComponent>("yellow");
            entity->Add<StepsComponent>(100);
            entity->Add<PoisoningComponent>(false);
            entity->Add<PlayerComponent>();
            entity->Add<HealthComponent>(100, 100);
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('@');
            entity->Add<MovementComponent>(0, 0);
            entity->Add<PlayerMoveControlComponent>(TK_RIGHT, TK_LEFT, TK_UP, TK_DOWN);
            entity->Add<PlayerShootControlComponent>(TK_D, TK_A, TK_W, TK_S);
            entity->Add<BulletCountComponent>(10);
          }

          else if (myArray[i][j] == 'E') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<EnemyComponent>();
            entity->Add<ColorComponent>("red");
            entity->Add<ScoresComponent>(100);
            entity->Add<AIPursuedComponent>(15, 5);
            entity->Add<AIRandomWalkComponent>(30);
            entity->Add<MovementComponent>(0, 0);
            entity->Add<DamageComponent>(75);
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('E');
          }

          else if (myArray[i][j] == 'S') {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<EnemyComponent>();
            entity->Add<ColorComponent>("red");
            entity->Add<ScoresComponent>(150);
            entity->Add<AIPursuedComponent>(10, 3);
            entity->Add<AIRandomWalkComponent>(45);
            entity->Add<MovementComponent>(0, 0);
            entity->Add<DamageComponent>(10);
            entity->Add<PoisonComponent>(50);
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>('S');
          } else {
            auto entity = engine_.GetEntityManager()->CreateEntity();
            entity->Add<TransformComponent>(i, j);
            entity->Add<TextureComponent>(myArray[i][j]);
          }
        }
      }
    }
  } else {
    terminal_printf(0, 0, "Уровень не найден");
  }
  file_.close();
}

#include <BearLibTerminal.h>

#include <vector>

#include "./Coin.h"
#include "./CoinsManager.h"
#include "./CollisionManager.h"
#include "./Controls.h"
#include "./Food.h"
#include "./FoodManager.h"
#include "./Player.h"
#include "./Reader.h"
#include "./Wall.h"

int main() {
  terminal_open();
  terminal_refresh();

  const int x = 40;
  const int y = 12;

  std::vector<Coin> coins;
  std::vector<Food> food;
  std::vector<Wall> walls;

  Controls controls{};
  Player player{controls, x, y, 100, 100};

  Reader reader(coins, food, walls, player);
  reader.ReadFile();
  CoinsManager cm{player, coins};
  FoodManager fm{player, food};
  CollisionManager colm{controls, player, walls};

  player.Poison();

  while (true) {
    terminal_clear();

    controls.Update();
    if (controls.IsExit()) {
      break;
    }

    cm.Update();
    fm.Update();
    colm.Update();

    player.Update();

    terminal_refresh();
  }

  terminal_close();
}

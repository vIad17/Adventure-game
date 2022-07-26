#include <BearLibTerminal.h>

#include <vector>

#include "./Coin.h"
#include "./CoinsManager.h"
#include "./CollisionManager.h"
#include "./Controls.h"
#include "./Food.h"
#include "./FoodManager.h"
#include "./Player.h"
#include "./Wall.h"

int main() {
  terminal_open();
  terminal_refresh();

  const int x = 40;
  const int y = 10;

  std::vector<Coin> coins{{2, 7}, {5, 2}, {10, 24}, {22, 4}, {12, 12}, {40, 20}, {75, 22}, {46, 2}, {70, 5}};
  std::vector<Food> food{{2, 1}, {6, 5}, {15, 16}, {19, 7}, {10, 21}, {55, 55}, {75, 34}, {49, 6}, {70, 12}};
  std::vector<Wall> walls{{41, 10}};

  for (int i = 0; i < 80; i++) walls.push_back({i, 1});
  for (int i = 0; i < 80; i++) walls.push_back({i, 24});
  for (int i = 2; i < 24; i++) walls.push_back({0, i});
  for (int i = 2; i < 24; i++) walls.push_back({79, i});

  Controls controls;
  Player player{controls, x, y, 100, 100};
  CoinsManager cm{player, coins};
  FoodManager fm{player, food};
  CollisionManager colm{controls, player, walls};

  Food f{20, 20};
  f.Update();

  Coin c{1, 8};
  c.Update();

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

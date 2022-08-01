#include "./Reader.h"

#include <BearLibTerminal.h>

#include <fstream>
#include <string>
#include <vector>

void Reader::ReadFile() {
  int x = 81;
  int y = 25;

  char myArray[x][y];

  std::vector<Coin> coins;
  std::vector<Food> food;
  std::vector<Wall> walls;
  std::ifstream my_file("../include/Level1.txt");

  if (my_file) {
    for (int j = 0; j < y; j++) {
      for (int i = 0; i < x; i++) {
        my_file >> myArray[i][j];

        if (myArray[i][j] == '/') break;
        if (myArray[i][j] == '$') coins_.emplace_back(i, j);
        if (myArray[i][j] == '%') food_.emplace_back(i, j);
        if (myArray[i][j] == '#') walls_.emplace_back(i, j);
        if (myArray[i][j] == '@') player_.SetLocation(i, j);
      }
    }
  } else {
    terminal_printf(0, 0, "Уровень не найден");
  }
  my_file.close();
}

//  std::ifstream my_file("../include/Level1.txt");
//  int j = 0;
//  while (my_file) {
//    std::string strInp;
//    getline(my_file, strInp);
//    const char *ch = strInp.c_str();
//    for (int i = 0; i < x; i++) {
//      if (ch[i] == '#') walls_.emplace_back(i, j);
//    }
//    ++y;
//  }
//  my_file.close();

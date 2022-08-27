#ifndef INCLUDE_LIB_PNGCONVERTER_H_
#define INCLUDE_LIB_PNGCONVERTER_H_

#include <BearLibTerminal.h>

class PngConverter {
 public:
  void Convert() {
    terminal_set("0x01: pictures/main_character.png, resize=16x16, align=center");
    terminal_set("0x02: pictures/ninja.png, resize=16x16, align=center");
    terminal_set("0x03: pictures/enemy.png, resize=16x16, align=center");
    terminal_set("0x04: pictures/snake.png, resize=16x16, align=center");
    terminal_set("0x05: pictures/antidote.png, resize=16x16, align=center");
    terminal_set("0x06: pictures/bullet.png, resize=16x16, align=center");
    terminal_set("0x07: pictures/heal.png, resize=16x16, align=center");
    terminal_set("0x08: pictures/wall.png, resize=16x16, align=center");
    // terminal_set(
    //     "0x02: "
    //     "/home/vlad/projects/7bits/titkov.vladislav-game-master/pictures/"
    //     "background.png, resize=640x320");
  }
};

#endif  // INCLUDE_LIB_PNGCONVERTER_H_

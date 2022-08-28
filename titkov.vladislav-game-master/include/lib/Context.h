#ifndef INCLUDE_LIB_CONTEXT_H_
#define INCLUDE_LIB_CONTEXT_H_

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "ecs/Entity.h"

/**
 * В контексте хранится информация о сцене, которую нужно сейчас отрисоватывать.
 * Контекст должен создаться где-то во вне и передаться по указателю во все сцены,
 * чтобы они могли им манипулировать и в SceneManager,
 * чтобы он мог читать из него информацию о сценах.
 *
 * Кстати, можно использовать контекст для хранения некоторой информации при переходе между сценами.
 * Но рекомендуется придумать механизм, чтобы не пришлось постоянно править класс контектса.
 * Как минимум используйте map<string, iobject*>
 */

class Context {
 public:
  std::vector<std::string> levels_{};
  std::map<std::string, std::vector<Entity>> level_entities_;
  int scene_number_ = 0;
  std::string scene_;
  std::string prev_scene_;
  bool is_it_next_level_ = true;
  int health_ = 100;
  int bullets_ = 0;
  bool is_poisoning_ = false;
  int poison_delay_ = 0;
  int score_ = 0;
  int score_leaders_[3] = {0, 0, 0};
  int amount_of_steps_ = 0;
  int attempts_ = 0;
  bool is_graphic = false;
  bool is_exit = false;

  explicit Context(std::vector<std::string> levels) : levels_(std::move(levels)) {}
};

#endif  // INCLUDE_LIB_CONTEXT_H_

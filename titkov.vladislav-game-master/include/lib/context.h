#ifndef INCLUDE_LIB_CONTEXT_H_
#define INCLUDE_LIB_CONTEXT_H_

#include <string>
#include <utility>
#include <vector>

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
  int scene_number_ = 0;
  std::string scene_;
  bool graphics_ = false;

  explicit Context(std::vector<std::string> levels) : levels_(std::move(levels)) {}

  int score_{0};
  int amount_of_steps_{0};
};

#endif  // INCLUDE_LIB_CONTEXT_H_

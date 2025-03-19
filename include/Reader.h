#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <fstream>
#include <vector>

#include "./IReader.h"
#include "ecs/Engine.h"
#include "lib/Context.h"

class Reader : IReader {
  const Engine &engine_;
  const Context *ctx_;
  std::ifstream &file_;

 public:
  Reader(const Engine &engine, const Context *ctx, std::ifstream &file) : engine_(engine), ctx_(ctx), file_(file) {}

  void ReadFile() override;
};

#endif  // INCLUDE_READER_H_

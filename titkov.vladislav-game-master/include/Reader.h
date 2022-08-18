#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <fstream>
#include <vector>

#include "./IReader.h"
#include "ecs/engine.h"

class Reader : IReader {
  const Engine &engine_;
  std::ifstream &file_;

 public:
  Reader(const Engine &engine, std::ifstream &file) : engine_(engine), file_(file) {}
  void ReadFile() override;
};

#endif  // INCLUDE_READER_H_

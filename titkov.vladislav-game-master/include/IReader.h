#ifndef INCLUDE_IREADER_H_
#define INCLUDE_IREADER_H_

class IReader {
 public:
  explicit IReader() = default;
  virtual ~IReader() = default;

  virtual void ReadFile() = 0;
};

#endif  // INCLUDE_IREADER_H_

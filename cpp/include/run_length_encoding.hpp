#pragma once

#include <string>

class RunLengthEncoding {
public:
  static std::string encode(std::string);
  static std::string decode(std::string);
};

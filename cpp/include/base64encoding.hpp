#pragma once

#include <bitset>
#include <iostream>
#include <map>
#include <string>

class Base64encoding {
public:
  static std::string encode(std::string);
  static char bit_to_base64char(std::string);
};

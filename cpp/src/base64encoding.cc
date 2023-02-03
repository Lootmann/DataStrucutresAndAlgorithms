#include "../include/base64encoding.hpp"

std::string Base64encoding::encode(std::string str) {
  // bit to chars
  std::string bit_to_chars{};
  for (auto &ch : str) {
    bit_to_chars += std::bitset<8>(int(ch)).to_string();
  }

  // split each 6 bits
  // padding 0
  if (int mod = bit_to_chars.size() % 6; mod != 0) {
    for (int i = 0; i < 6 - mod; ++i) {
      bit_to_chars += "0";
    }
  }

  // convert bits to Base64char
  std::string convert{};

  // convert each 6 bits to Base64char
  for (size_t i = 0; i < bit_to_chars.size() / 6; ++i) {
    std::string bit = bit_to_chars.substr(6 * i, 6);
    convert.push_back(bit_to_base64char(bit));
  }

  if (int mod = convert.size() % 4; mod != 0) {
    for (int i = 0; i < 4 - mod; ++i) {
      convert += "=";
    }
  }

  return convert;
}

// bit to char
char Base64encoding::bit_to_base64char(std::string bit) {
  int i = std::stoi(bit, nullptr, 2);
  char ch{};

  if (0 <= i && i <= 25) {
    ch = (char)((int)'A' + i);
  } else if (26 <= i && i <= 51) {
    ch = (char)((int)'a' + i - 26);
  } else if (52 <= i && i <= 61) {
    ch = (char)('0' + i - 52);
  } else if (i == 62) {
    ch = '+';
  } else {
    ch = '/';
  }

  return ch;
}

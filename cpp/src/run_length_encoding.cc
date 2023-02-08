#include "../include/run_length_encoding.hpp"

#include <iostream>

std::string RunLengthEncoding::encode(std::string input) {
  std::string output{};
  int count{1};

  for (size_t i = 0; i < input.size() - 1; ++i) {
    if (input[i] != input[i + 1]) {
      output.push_back(input[i]);

      if (count != 1) {
        output += std::to_string(count);
      }

      count = 1;
    } else {
      count++;
    }
  }

  if (count == 1) {
    output.push_back(input.back());
  } else {
    output.push_back(input.back());
    output += std::to_string(count);
  }

  return output;
}

auto mystoi = [](std::string const number) {
  int result{0}, base{1};
  for (auto num : number) {
    result += (int)(num - '0') * base;
    base *= 10;
  }
  return result;
};

std::string RunLengthEncoding::decode(std::string input) {
  std::string output{};
  std::string number{};

  for (int i = (int)input.size() - 1; i >= 0; --i) {
    if ('0' <= input[i] && input[i] <= '9') {
      number = input[i] + number;
    } else {
      for (int j = 0; j < std::max(mystoi(number), 1); ++j) {
        output = input[i] + output;
      }

      number = "";
    }
  }

  return output;
}

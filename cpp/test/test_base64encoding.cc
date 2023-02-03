#include <gtest/gtest.h>

#include <vector>

#include "../include/base64encoding.hpp"

#define mp std::make_pair
using std::pair;
using std::string;
using std::vector;

TEST(Base64encodingTest, Encoding) {
  vector<pair<string, string>> vpp{
      mp("ABCDEFG", "QUJDREVGRw=="),
      mp("hogehoge", "aG9nZWhvZ2U="),
      mp("SmileFaceWithRofl", "U21pbGVGYWNlV2l0aFJvZmw="),
      mp("OriginalSoundTruckCalledByBase64EncoderMachine",
         "T3JpZ2luYWxTb3VuZFRydWNrQ2FsbGVkQnlCYXNlNjRFbmNvZGVyTWFjaGluZQ=="),
  };

  for (auto &p : vpp) {
    EXPECT_EQ(Base64encoding::encode(p.first), p.second);
  }
}

TEST(Base64encoding, BitToBase64char) {
  vector<pair<string, char>> vp{
      mp("000000", 'A'), mp("011001", 'Z'), mp("011010", 'a'),
      mp("010001", 'R'), mp("101011", 'r'), mp("110011", 'z'),
      mp("110100", '0'), mp("111101", '9'), mp("111110", '+'),
      mp("111111", '/'),
  };

  for (auto p : vp) {
    char res = Base64encoding::bit_to_base64char(p.first);
    EXPECT_EQ(res, p.second);
  }
}

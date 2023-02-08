#include <gtest/gtest.h>

#include <vector>

#include "../include/run_length_encoding.hpp"

using std::pair;
using std::string;
using std::vector;

class RunLengthEncodingTest : public testing::Test {
protected:
  vector<pair<string, string>> testcases{
      std::make_pair("ABCDEFG", "ABCDEFG"),
      std::make_pair("AA", "A2"),
      std::make_pair("VVV", "V3"),
      std::make_pair("KKA", "K2A"),
      std::make_pair("KKAA", "K2A2"),
      std::make_pair("KKAAA", "K2A3"),
      std::make_pair("ABBCCCDDDD", "AB2C3D4"),
      std::make_pair("AAAABBBCCD", "A4B3C2D"),
  };

  void SetUp() override {}
  virtual void TearDown() override {}
};

TEST_F(RunLengthEncodingTest, Encoding) {
  for (auto testcase : testcases) {
    std::string got = RunLengthEncoding::encode(testcase.first);
    std::string want = testcase.second;
    EXPECT_EQ(got, want);
  }
}

TEST_F(RunLengthEncodingTest, Decoding) {
  for (auto testcase : testcases) {
    std::string got = RunLengthEncoding::decode(testcase.second);
    std::string want = testcase.first;
    EXPECT_EQ(got, want);
  }
}

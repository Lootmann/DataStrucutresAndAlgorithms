#include <gtest/gtest.h>

#include "../include/searching.hpp"
#include "../include/util.hpp"

class SearchingTest : public testing::Test {
protected:
  std::vector<int> vec_small;
  std::vector<int> vec_middle;

  void SetUp() override {
    vec_small = GenerateVector<int>(200);
  }
  virtual void TearDown() override {}
};

TEST_F(SearchingTest, Constructor) {
  EXPECT_NE(Searching<int>::LinearSearch(vec_small, 1), -1);
  EXPECT_EQ(Searching<int>::LinearSearch(vec_small, 200), -1);
}

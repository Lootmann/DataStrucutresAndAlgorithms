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

TEST_F(SearchingTest, LinearSearch) {
  EXPECT_NE(Searching<int>::LinearSearch(vec_small, 1), -1);
  EXPECT_EQ(Searching<int>::LinearSearch(vec_small, 200), -1);
}

TEST_F(SearchingTest, BinarySearch) {
  std::sort(vec_small.begin(), vec_small.end());
  EXPECT_EQ(Searching<int>::BinarySearch(vec_small, -1), -1);
  EXPECT_EQ(Searching<int>::BinarySearch(vec_small, 0), 0);
  EXPECT_EQ(Searching<int>::BinarySearch(vec_small, 1), 1);
  EXPECT_EQ(Searching<int>::BinarySearch(vec_small, 199), 199);
  EXPECT_EQ(Searching<int>::BinarySearch(vec_small, 200), -1);
}

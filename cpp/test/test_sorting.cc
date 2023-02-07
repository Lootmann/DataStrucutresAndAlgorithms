#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>

#include "../include/sorting.hpp"

std::vector<int> GenerateVector(std::size_t size = 20) {
  std::vector<int> v(size);
  std::iota(v.begin(), v.end(), 0);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(v.begin(), v.end(), engine);

  return v;
}

TEST(SortingTest, BubbleSortFixed) {
  std::vector<int> v{10, 3, 4, 6, 2, 1, 9};

  Sorting<int>::BubbleSort(v);
  testing::internal::CaptureStdout();
  for (auto num : v) std::cout << num << ' ';
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1 2 3 4 6 9 10 ");
}

TEST(SortingTest, BubbleSortRandom) {
  auto v = GenerateVector(10);

  testing::internal::CaptureStdout();
  for (auto num : v) std::cout << num;
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_NE(output, "0123456789");

  Sorting<int>::BubbleSort(v);
  testing::internal::CaptureStdout();
  for (auto num : v) std::cout << num;
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "0123456789");
}

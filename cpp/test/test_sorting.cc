#include <gtest/gtest.h>

#include "../include/sorting.hpp"
#include "../include/util.hpp"

TEST(SortingTest, BubbleSortFixed) {
  std::vector<int> v{10, 3, 4, 6, 2, 1, 9};

  Sorting<int>::BubbleSort(v);
  testing::internal::CaptureStdout();
  for (auto num : v) std::cout << num << ' ';
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1 2 3 4 6 9 10 ");
}

TEST(SortingTest, BubbleSortRandom) {
  auto v = GenerateVector<int>(10);

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

TEST(SortingTest, SelectionSortFixed) {
  std::vector<int> v{10, 3, 4, 6, 2, 1, 9};

  Sorting<int>::SelectionSort(v);
  testing::internal::CaptureStdout();
  for (auto num : v) std::cout << num << ' ';
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1 2 3 4 6 9 10 ");
}

TEST(SortingTest, InsertionSortFixed) {
  std::vector<int> v{10, 3, 4, 6, 2, 1, 9};

  Sorting<int>::InsertionSort(v);
  testing::internal::CaptureStdout();
  for (auto num : v) std::cout << num << ' ';
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1 2 3 4 6 9 10 ");
}

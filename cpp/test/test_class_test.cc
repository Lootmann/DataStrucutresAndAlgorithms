#include <gtest/gtest.h>

#include "../include/class_test.hpp"

class ArrayClassTest : public testing::Test {
protected:
  array<int, 5> a{1, 2, 3, 4, 5};
  void SetUp() override {}
  virtual void TearDown() override {}
};

TEST_F(ArrayClassTest, Init) {
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(a[i], i + 1);
  }
}

TEST_F(ArrayClassTest, at) {
  ASSERT_NO_THROW(a.at(1));
  ASSERT_THROW(a.at(100), std::out_of_range);
}

TEST_F(ArrayClassTest, Begin) {
  auto iter = a.begin();
  EXPECT_EQ(*iter, 1);
  ++iter;
  EXPECT_EQ(*iter, 2);
  iter++;
  EXPECT_EQ(*iter, 3);
}

TEST_F(ArrayClassTest, End) {
  auto iter = a.end();
  --iter;
  EXPECT_EQ(*iter, 5);
  iter--;
  EXPECT_EQ(*iter, 4);
}

TEST_F(ArrayClassTest, OperatorEqual) {
  auto left = std::begin(a);
  auto right = std::end(a);
  EXPECT_TRUE(left != right);
  ++left;
  left++;

  --right;
  right--;
  --right;
  EXPECT_TRUE(left == right);
}

TEST_F(ArrayClassTest, OperatorPlusEqual) {
  auto left = std::begin(a);
  auto right = std::end(a);
  EXPECT_TRUE(left != right);

  left += 2;
  right -= 3;
  EXPECT_TRUE(left == right);
}

TEST_F(ArrayClassTest, OperatorAccess) {
  EXPECT_EQ(a[1], 2);
  auto i = a.begin();
  EXPECT_EQ(*(i + 1), 2);
  EXPECT_EQ(*(i + 2), 3);
  EXPECT_EQ(*(i + 3), 4);
}

TEST_F(ArrayClassTest, OperatorComparisonGreator) {
  auto left = std::begin(a);
  auto right = std::begin(a);

  EXPECT_FALSE(left < right);
  EXPECT_TRUE(left <= right);

  right++;
  EXPECT_TRUE(left < right);
  EXPECT_TRUE(left <= right);
}

TEST_F(ArrayClassTest, OperatorComparisonSmaller) {
  auto left = a.end();
  auto right = a.end();

  EXPECT_FALSE(left > right);
  EXPECT_TRUE(left >= right);
  EXPECT_TRUE(left == right);
}

TEST_F(ArrayClassTest, Front) {
  EXPECT_EQ(a.front(), 1);
}

TEST_F(ArrayClassTest, Back) {
  EXPECT_EQ(a.back(), 5);
}

TEST_F(ArrayClassTest, Fill) {
  a.fill(9);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(a[i], 9);
  }
}

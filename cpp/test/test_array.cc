#include <gtest/gtest.h>

#include <iostream>

#include "../include/array.hpp"

class ArrayTest : public testing::Test {
protected:
  Array<int> a;
  Array<int> b{100};
  Array<int> c{20, 9};
  Array<int> huge{100000};

  void SetUp() override {}
  virtual void TearDown() override {}
};

TEST_F(ArrayTest, Constructor) {
  EXPECT_EQ(a.size(), 10);
  for (int i = 0; i < a.size(); ++i) {
    EXPECT_EQ(a[i], 0);
  }

  EXPECT_EQ(b.size(), 100);
  for (int i = 0; i < b.size(); ++i) {
    EXPECT_EQ(b[i], 0);
  }

  EXPECT_EQ(c.size(), 20);
  for (int i = 0; i < c.size(); ++i) {
    EXPECT_EQ(c[i], 9);
    EXPECT_NE(c[i], 0);
  }
}

TEST_F(ArrayTest, EqualOperator) {
  EXPECT_EQ(a.size(), 10);
  for (int i = 0; i < a.size(); ++i) {
    EXPECT_EQ(a[i], 0);
  }

  EXPECT_EQ(c.size(), 20);
  for (int i = 0; i < c.size(); ++i) {
    EXPECT_EQ(c[i], 9);
  }

  a = c;

  EXPECT_EQ(a.size(), 20);

  for (int i = 0; i < a.size(); ++i) {
    EXPECT_EQ(a[i], 9);
    EXPECT_EQ(c[i], 9);
  }
}

TEST_F(ArrayTest, OutBound) {
  ASSERT_NO_THROW(a[a.size() - 1]);
  ASSERT_DEATH(a[a.size()], "");
  ASSERT_DEATH(a[-1], "");
}

TEST_F(ArrayTest, HugeTest) {
  EXPECT_EQ(huge.size(), 100000);

  for (int i = 0; i < huge.size(); ++i) {
    huge[i] = i;
  }

  for (int i = 0; i < huge.size(); ++i) {
    EXPECT_EQ(huge[i], i);
  }
}

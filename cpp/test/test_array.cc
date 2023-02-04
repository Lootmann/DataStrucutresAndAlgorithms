#include <gtest/gtest.h>

#include <iostream>

#include "../include/array.hpp"

class ArrayTest : public testing::Test {
protected:
  Array a;
  Array b{100};
  Array c{20, 9};

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

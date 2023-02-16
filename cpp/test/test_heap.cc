#include <gtest/gtest.h>

#include <iostream>

#include "../include/heap.hpp"

class HeapTest : public testing::Test {
protected:
  Heap<int> a;
  void SetUp() override {}
  virtual void TearDown() override {}
};

TEST_F(HeapTest, Init) {
  EXPECT_EQ(a.size(), 0);
}

TEST_F(HeapTest, Add) {
  for (int i = 0; i < 10; ++i) {
    a.add(i);
    EXPECT_EQ(a.size(), i + 1);
  }
}

TEST_F(HeapTest, Remove) {
  for (int i = 0; i < 10; ++i) {
    a.add(i);
  }

  EXPECT_EQ(a.remove(), 0);
  EXPECT_EQ(a.remove(), 1);
  EXPECT_EQ(a.remove(), 2);
  EXPECT_EQ(a.remove(), 3);
  EXPECT_EQ(a.remove(), 4);
  EXPECT_EQ(a.remove(), 5);
  EXPECT_EQ(a.remove(), 6);

  a.add(0);
  EXPECT_EQ(a.remove(), 0);
  EXPECT_EQ(a.remove(), 7);
}

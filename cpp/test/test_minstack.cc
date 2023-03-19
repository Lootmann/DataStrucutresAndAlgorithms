#include <gtest/gtest.h>

#include <iostream>

#include "../include/stack.hpp"

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define reps(i, s, n) for (int i = s; i < (int)n; ++i)

class MinStackTest : public testing::Test {
protected:
  MinStack st;

  void SetUp() override {
    st = MinStack();
  }

  virtual void TearDown() override {}
};

TEST_F(MinStackTest, Init) {
  EXPECT_TRUE(st.empty());
  EXPECT_EQ(st.size(), 0);
}

TEST_F(MinStackTest, Push) {
  rep(i, 10) {
    EXPECT_EQ(st.size(), i);
    st.push(i);
    EXPECT_FALSE(st.empty());
  }
}

TEST_F(MinStackTest, Top) {
  rep(i, 10) {
    st.push(i);
    EXPECT_EQ(st.top(), i);
  }
}

TEST_F(MinStackTest, Min) {
  rep(i, 10) {
    st.push(i);
    EXPECT_EQ(st.min(), 0);
  }
}

TEST_F(MinStackTest, MinReverse) {
  for (int i = 10; i >= 0; --i) {
    st.push(i);
    EXPECT_EQ(st.min(), i);
  }
}

TEST_F(MinStackTest, MinMix) {
  const int size = 10;
  int nums[size] = {5, 7, 11, 4, 9, 3, 12, 1, 0, 8};
  int current{}, min_{9999};

  rep(i, size) {
    st.push(nums[i]);
    current = nums[i];
    min_ = std::min(min_, nums[i]);

    EXPECT_EQ(st.top(), current);
    EXPECT_EQ(st.min(), min_);
  }
}

TEST_F(MinStackTest, Pop) {
  const int size = 10;

  rep(i, size) {
    st.push(i);
  }

  rep(i, size) {
    EXPECT_EQ(st.top(), size - i - 1);
    EXPECT_EQ(st.size(), size - i);
    st.pop();
  }
  EXPECT_EQ(st.size(), 0);
}

TEST_F(MinStackTest, PopMix) {
  const int size = 7;
  int nums[size] = {10, 5, 7, 3, 6, 2, 1};
  rep(i, size) st.push(nums[i]);

  EXPECT_EQ(st.size(), 7);
  EXPECT_EQ(st.top(), 1);
  EXPECT_EQ(st.min(), 1);
  st.pop();

  EXPECT_EQ(st.size(), 6);
  EXPECT_EQ(st.top(), 2);
  EXPECT_EQ(st.min(), 2);
  st.pop();

  EXPECT_EQ(st.size(), 5);
  EXPECT_EQ(st.top(), 6);
  EXPECT_EQ(st.min(), 3);
  st.pop();

  EXPECT_EQ(st.size(), 4);
  EXPECT_EQ(st.top(), 3);
  EXPECT_EQ(st.min(), 3);
  st.pop();

  EXPECT_EQ(st.size(), 3);
  EXPECT_EQ(st.top(), 7);
  EXPECT_EQ(st.min(), 5);
  st.pop();

  EXPECT_EQ(st.size(), 2);
  EXPECT_EQ(st.top(), 5);
  EXPECT_EQ(st.min(), 5);
  st.pop();

  EXPECT_EQ(st.size(), 1);
  EXPECT_EQ(st.top(), 10);
  EXPECT_EQ(st.min(), 10);
  st.pop();

  EXPECT_TRUE(st.empty());
}

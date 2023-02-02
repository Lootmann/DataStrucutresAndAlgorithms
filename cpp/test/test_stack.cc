#include <gtest/gtest.h>

#include <iostream>

#include "../include/stack.hpp"

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define reps(i, s, n) for (int i = s; i < (int)n; ++i)

class StackTest : public testing::Test {
protected:
  void SetUp() override {
    st = new Stack();
  }
  Stack *st;
};

TEST_F(StackTest, Init) {
  EXPECT_TRUE(st->empty());
  EXPECT_EQ(st->size(), 0);
}

TEST_F(StackTest, Push) {
  st->push(10);
  EXPECT_EQ(st->top(), 10);
  EXPECT_EQ(st->size(), 1);
}

TEST_F(StackTest, PushMany) {
  rep(i, 100) {
    st->push(i);
    EXPECT_EQ(st->top(), i);
    EXPECT_EQ(st->size(), i + 1);
  }
}

TEST_F(StackTest, Pop) {
  reps(i, 0, 100) st->push(i);
  EXPECT_EQ(st->top(), 99);
  EXPECT_EQ(st->size(), 100);

  auto p = st->pop();
  EXPECT_EQ(p->m_val, 99);
  EXPECT_EQ(st->size(), 99);
}

TEST_F(StackTest, PopWithEmptyStack) {
  ASSERT_THROW(st->pop(), std::out_of_range);
}

TEST_F(StackTest, PopThrow) {
  ASSERT_THROW(st->pop(), std::out_of_range);
}

TEST_F(StackTest, PopThrowAfterManyPush) {
  rep(i, 1000) st->push(i);
  rep(i, 1000) st->pop();

  ASSERT_THROW(st->pop(), std::out_of_range);
}

TEST_F(StackTest, Top) {
  rep(i, 1000) {
    st->push(i);
    EXPECT_EQ(st->top(), i);
  }
}

TEST_F(StackTest, TopWithRaise) {
  ASSERT_THROW(st->top(), std::out_of_range);
}

TEST_F(StackTest, Empty) {
  EXPECT_TRUE(st->empty());

  st->push(0);
  EXPECT_FALSE(st->empty());
}

TEST_F(StackTest, Size) {
  rep(i, 1000) {
    st->push(i);
    EXPECT_EQ(st->size(), i + 1);
  }
}

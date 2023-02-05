#include <gtest/gtest.h>

#include <iostream>

#include "../include/queue_ring_buffer.hpp"

#define rep(i, n) for (int i = 0; i < (int)n; ++i)

class RingBufferQueueTest : public testing::Test {
protected:
  RingBufferQueue<int> qi;

  void SetUp() override {}

  virtual void TearDown() override {}
};

TEST_F(RingBufferQueueTest, InitWithoutSize) {
  EXPECT_TRUE(qi.is_empty());
  EXPECT_FALSE(qi.is_full());
  EXPECT_EQ(qi.size(), 0);
}

TEST_F(RingBufferQueueTest, Enqueue) {
  qi.enqueue(1);
  EXPECT_FALSE(qi.is_empty());
  EXPECT_FALSE(qi.is_full());

  EXPECT_EQ(qi.front(), 1);
  EXPECT_EQ(qi.back(), 1);

  qi.enqueue(9999);
  EXPECT_EQ(qi.front(), 1);
  EXPECT_EQ(qi.back(), 9999);

  ASSERT_TRUE(qi.front());
  ASSERT_TRUE(qi.back());

  qi.enqueue(1234);
  EXPECT_EQ(qi.front(), 1);
  EXPECT_EQ(qi.back(), 1234);
  EXPECT_EQ(qi.size(), 3);
}

TEST_F(RingBufferQueueTest, Dequeue) {
  qi.enqueue(10);
  EXPECT_FALSE(qi.is_empty());
  EXPECT_FALSE(qi.is_full());
  EXPECT_EQ(qi.size(), 1);

  EXPECT_EQ(qi.dequeue(), 10);
  EXPECT_TRUE(qi.is_empty());
  EXPECT_FALSE(qi.is_full());
  EXPECT_EQ(qi.size(), 0);
}

TEST_F(RingBufferQueueTest, Mix) {
  rep(i, 5) qi.enqueue(i);
  EXPECT_EQ(qi.size(), 5);
  EXPECT_EQ(qi.front(), 0);
  EXPECT_EQ(qi.back(), 4);

  rep(i, 5) EXPECT_EQ(qi.dequeue(), i);
  EXPECT_EQ(qi.size(), 0);

  qi.enqueue(10);
  EXPECT_EQ(qi.front(), 10);
  EXPECT_EQ(qi.back(), 10);
  EXPECT_EQ(qi.size(), 1);

  qi.enqueue(99);
  EXPECT_EQ(qi.front(), 10);
  EXPECT_EQ(qi.back(), 99);
  EXPECT_EQ(qi.size(), 2);

  rep(i, 5) qi.enqueue(i);
  EXPECT_EQ(qi.front(), 10);
  EXPECT_EQ(qi.back(), 4);
  EXPECT_EQ(qi.size(), 7);

  rep(i, 6) qi.dequeue();
  EXPECT_EQ(qi.front(), 4);
  EXPECT_EQ(qi.back(), 4);
  EXPECT_EQ(qi.size(), 1);
}

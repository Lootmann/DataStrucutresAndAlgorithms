#include <gtest/gtest.h>

#include <iostream>

#include "../include/queue.hpp"

#define rep(i, n) for (int i = 0; i < (int)n; ++i)

class QueueTest : public testing::Test {
protected:
  void SetUp() override {
    q = new Queue();
  }
  Queue *q;
};

TEST_F(QueueTest, Init) {
  EXPECT_TRUE(q->empty());
  EXPECT_EQ(q->size(), 0);
}

TEST_F(QueueTest, Enqueue) {
  rep(i, 100) {
    q->enqueue(i);
    EXPECT_EQ(q->front(), 0);
    EXPECT_EQ(q->back(), i);
    EXPECT_EQ(q->size(), i + 1);
  }
}

TEST_F(QueueTest, Dequeue) {
  int size{100};
  rep(i, size) q->enqueue(i);

  int idx{0};
  while (!q->empty()) {
    EXPECT_EQ(q->front(), idx);
    EXPECT_EQ(q->back(), size - 1);
    EXPECT_EQ(q->size(), size - idx);

    auto f = q->dequeue();
    EXPECT_EQ(f->m_val, idx);
    idx++;
  }
}

TEST_F(QueueTest, FrontWithRaise) {
  ASSERT_THROW(q->front(), std::out_of_range);
}

TEST_F(QueueTest, BackWithRaise) {
  ASSERT_THROW(q->back(), std::out_of_range);
}

TEST_F(QueueTest, Empty) {
  EXPECT_TRUE(q->empty());
  q->enqueue(1);
  EXPECT_FALSE(q->empty());
}

TEST_F(QueueTest, Size) {
  rep(i, 1000) {
    q->enqueue(i);
    EXPECT_EQ(q->size(), i + 1);
  }
}

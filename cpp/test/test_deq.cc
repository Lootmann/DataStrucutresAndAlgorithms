#include <gtest/gtest.h>

#include "../include/deq.hpp"

class DeqTest : public testing::Test {
protected:
  Deq *d;

  void SetUp() override {
    d = new Deq();
  }

  virtual void TearDown() override {
    delete d;
  }
};

TEST_F(DeqTest, DefaultValue) {
  EXPECT_EQ(d->size(), 0);
  EXPECT_TRUE(d->empty());
}

TEST_F(DeqTest, Pushback) {
  for (int i = 0; i < 1000; ++i) {
    d->push_back(i);
    EXPECT_EQ(d->size(), i + 1);
  }
}

TEST_F(DeqTest, Popback) {
  d->push_back(1000);
  EXPECT_EQ(d->size(), 1);
  EXPECT_EQ(d->back(), 1000);
  EXPECT_EQ(d->back(), 1000);

  int poped = d->pop_back();
  EXPECT_EQ(poped, 1000);
  EXPECT_EQ(d->size(), 0);
  ASSERT_THROW(d->back(), std::out_of_range);
}

TEST_F(DeqTest, PopbackMany) {
  for (int i = 0; i < 1000; ++i) {
    d->push_back(i);
    EXPECT_EQ(d->size(), i + 1);
    EXPECT_EQ(d->back(), i);
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(d->pop_back(), 999 - i);
    EXPECT_EQ(d->size(), 999 - i);
  }
}

TEST_F(DeqTest, PopbackWithRaise) {
  ASSERT_THROW(d->pop_back(), std::out_of_range);
}

TEST_F(DeqTest, Top) {
  for (int i = 0; i < 1000; ++i) {
    d->push_back(i);
    EXPECT_EQ(d->back(), i);
    EXPECT_EQ(d->size(), i + 1);
  }
}

TEST_F(DeqTest, TopWithRaise) {
  ASSERT_THROW(d->back(), std::out_of_range);
}

TEST_F(DeqTest, Back) {
  for (int i = 0; i < 1000; ++i) {
    d->push_back(i);
    EXPECT_EQ(d->back(), i);
    EXPECT_EQ(d->size(), i + 1);
  }
}

TEST_F(DeqTest, BackWithRaise) {
  ASSERT_THROW(d->back(), std::out_of_range);
}

TEST_F(DeqTest, Pushfront) {
  for (int i = 0; i < 1000; ++i) {
    d->push_front(i);
    EXPECT_EQ(d->size(), i + 1);
  }
}

TEST_F(DeqTest, Popfront) {
  for (int i = 0; i < 100; ++i) {
    d->push_front(i);
    EXPECT_EQ(d->size(), i + 1);
  }
}

TEST_F(DeqTest, PopfrontWithRaise) {
  ASSERT_THROW(d->pop_front(), std::out_of_range);
}

TEST_F(DeqTest, Front) {
  d->push_front(1);
  EXPECT_EQ(d->front(), 1);

  d->push_back(9);
  EXPECT_EQ(d->front(), 1);

  d->push_back(99);
  EXPECT_EQ(d->front(), 1);

  d->push_front(11);
  EXPECT_EQ(d->front(), 11);

  d->push_front(111);
  EXPECT_EQ(d->front(), 111);

  EXPECT_EQ(d->back(), 99);
}

TEST_F(DeqTest, FrontWithRaise) {
  ASSERT_THROW(d->front(), std::out_of_range);
}

TEST_F(DeqTest, MixOperations) {
  // 1 2 3 4 5 6
  d->push_front(1);
  for (int i = 2; i <= 6; ++i) {
    d->push_back(i);
  }
  EXPECT_EQ(d->pop_front(), 1);  // 2 3 4 5 6
  EXPECT_EQ(d->pop_back(), 6);   // 2 3 4 5
  EXPECT_EQ(d->pop_front(), 2);  // 3 4 5
  EXPECT_EQ(d->pop_back(), 5);   // 3 4

  d->push_back(9);      //  3 4 9
  d->push_back(100);    //  3 4 9 100
  d->push_front(9);     // 9 3 4 9 100
  d->push_front(9999);  //  9999 9 3 4 9 100

  EXPECT_EQ(d->size(), 6);
  EXPECT_EQ(d->pop_front(), 9999);  // 9 3 4 9 100
  EXPECT_EQ(d->pop_back(), 100);    // 9 3 4 9
  EXPECT_EQ(d->pop_back(), 9);      // 9 3 4
  EXPECT_EQ(d->pop_back(), 4);      // 9 3
  EXPECT_EQ(d->pop_front(), 9);     // 3
  EXPECT_EQ(d->pop_back(), 3);      // []

  ASSERT_THROW(d->pop_front(), std::out_of_range);
  ASSERT_THROW(d->pop_back(), std::out_of_range);

  ASSERT_THROW(d->front(), std::out_of_range);
  ASSERT_THROW(d->back(), std::out_of_range);
}

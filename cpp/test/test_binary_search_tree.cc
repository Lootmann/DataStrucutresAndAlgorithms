#include <gtest/gtest.h>

#include <iostream>

#include "../include/tree.hpp"

class BinarySearchTreeTest : public testing::Test {
protected:
  BinarySearchTree<int> *bst;

  void SetUp() override {
    bst = new BinarySearchTree<int>();
  }

  virtual void TearDown() override {
    delete bst;
  }
};

TEST_F(BinarySearchTreeTest, Init) {
  EXPECT_EQ(bst->size(), 0);
}

TEST_F(BinarySearchTreeTest, Insert) {
  bst->insert(5);
  EXPECT_EQ(bst->size(), 1);

  bst->insert(1);
  EXPECT_EQ(bst->size(), 2);

  bst->insert(10);
  EXPECT_EQ(bst->size(), 3);
}
/*
 *     10
 *  5     20
 * 1 8  14  25
 * */
TEST_F(BinarySearchTreeTest, Find) {
  int array[]{10, 5, 20, 1, 8, 14, 25};

  for (int i = 0; i < 7; ++i) {
    bst->insert(array[i]);
    EXPECT_EQ(bst->size(), i + 1);
  }

  auto found = bst->find(1);
  EXPECT_EQ(found->val_, 1);
  EXPECT_EQ(found->left_, nullptr);
  EXPECT_EQ(found->right_, nullptr);

  found = bst->find(20);
  auto left = bst->find(14);
  auto right = bst->find(25);
  EXPECT_EQ(found->left_, left);
  EXPECT_EQ(found->right_, right);
}

TEST_F(BinarySearchTreeTest, Contains) {
  int array[]{10, 5, 20, 1, 8, 14, 25};

  for (int i = 0; i < 7; ++i) {
    bst->insert(array[i]);
    EXPECT_EQ(bst->size(), i + 1);
  }

  EXPECT_EQ(bst->size(), 7);

  EXPECT_TRUE(bst->contains(1));
  EXPECT_TRUE(bst->contains(5));
  EXPECT_TRUE(bst->contains(8));
  EXPECT_TRUE(bst->contains(10));
  EXPECT_TRUE(bst->contains(14));
  EXPECT_TRUE(bst->contains(20));
  EXPECT_TRUE(bst->contains(25));

  EXPECT_FALSE(bst->contains(2));
  EXPECT_FALSE(bst->contains(7));
  EXPECT_FALSE(bst->contains(9));
  EXPECT_FALSE(bst->contains(12));
  EXPECT_FALSE(bst->contains(17));
  EXPECT_FALSE(bst->contains(22));
}

#include <gtest/gtest.h>

#include <cwchar>
#include <iostream>
#include <string>

#include "../include/tree.hpp"

class BinarySearchTreeTest : public testing::Test {
protected:
  BinarySearchTree<int> *bst, *traverse, *rmv;

  void SetUp() override {
    bst = new BinarySearchTree<int>();
    traverse = new BinarySearchTree<int>();
    rmv = new BinarySearchTree<int>();

    int array[]{10, 5, 20, 1, 8, 14, 25};
    for (auto num : array) {
      traverse->insert(num);
    }
  }

  virtual void TearDown() override {
    delete bst;
    delete traverse;
    delete rmv;
  }
};

TEST_F(BinarySearchTreeTest, Insert) {
  bst->insert(5);
  bst->insert(1);
  bst->insert(10);
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

TEST_F(BinarySearchTreeTest, NotFind) {
  int array[]{10, 5, 20, 1, 8, 14, 25};

  for (int i = 0; i < 7; ++i) {
    bst->insert(array[i]);
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

// util
TEST_F(BinarySearchTreeTest, Inorder) {
  testing::internal::CaptureStdout();
  traverse->inorder();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 5 8 10 14 20 25 \n", output);
}

TEST_F(BinarySearchTreeTest, Postorder) {
  testing::internal::CaptureStdout();
  traverse->postorder();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 8 5 14 25 20 10 \n", output);
}

TEST_F(BinarySearchTreeTest, Preorder) {
  testing::internal::CaptureStdout();
  traverse->preorder();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("10 5 1 8 20 14 25 \n", output);
}

void capture(BinarySearchTree<int> *node) {
  testing::internal::CaptureStdout();
  node->inorder();
}

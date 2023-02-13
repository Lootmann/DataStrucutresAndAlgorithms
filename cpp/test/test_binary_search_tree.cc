#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../include/tree.hpp"

class BinarySearchTreeTest : public testing::Test {
protected:
  BinarySearchTree<int> bst, traverse, rmv;

  void SetUp() override {
    int array[]{10, 5, 20, 1, 8, 14, 25};
    for (auto num : array) {
      traverse.insert(num);
    }
  }

  virtual void TearDown() override {}
};

/*
 *     10
 *  5     20
 * 1 8  14  25
 * */
TEST_F(BinarySearchTreeTest, Find) {
  int array[]{10, 5, 20, 1, 8, 14, 25};

  for (int i = 0; i < 7; ++i) {
    bst.insert(array[i]);
  }

  auto found = bst.find(1);
  EXPECT_EQ(found->val_, 1);
  EXPECT_EQ(found->left_, nullptr);
  EXPECT_EQ(found->right_, nullptr);

  found = bst.find(20);
  auto left = bst.find(14);
  auto right = bst.find(25);
  EXPECT_EQ(found->left_, left);
  EXPECT_EQ(found->right_, right);
}

TEST_F(BinarySearchTreeTest, NotFind) {
  int array[]{10, 5, 20, 1, 8, 14, 25};

  for (int i = 0; i < 7; ++i) {
    bst.insert(array[i]);
  }

  auto found = bst.find(1);
  EXPECT_EQ(found->val_, 1);
  EXPECT_EQ(found->left_, nullptr);
  EXPECT_EQ(found->right_, nullptr);

  found = bst.find(20);
  auto left = bst.find(14);
  auto right = bst.find(25);
  EXPECT_EQ(found->left_, left);
  EXPECT_EQ(found->right_, right);
}

// util
TEST_F(BinarySearchTreeTest, Inorder) {
  testing::internal::CaptureStdout();
  traverse.inorder();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 5 8 10 14 20 25 \n", output);
}

TEST_F(BinarySearchTreeTest, Postorder) {
  testing::internal::CaptureStdout();
  traverse.postorder();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 8 5 14 25 20 10 \n", output);
}

TEST_F(BinarySearchTreeTest, Preorder) {
  testing::internal::CaptureStdout();
  traverse.preorder();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("10 5 1 8 20 14 25 \n", output);
}

//*********************************************************
// remove
//*********************************************************

void capture(BinarySearchTree<int> *node) {
  testing::internal::CaptureStdout();
  node->inorder();
}

TEST_F(BinarySearchTreeTest, RemoveRoot) {
  rmv.insert(1);
  capture(&rmv);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 \n", output);

  rmv.remove(1);

  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("empty\n", output);
}

TEST_F(BinarySearchTreeTest, Removeleaf) {
  //  5
  // 1 X
  rmv.insert(5);
  rmv.insert(1);
  capture(&rmv);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 5 \n", output);

  rmv.remove(1);

  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("5 \n", output);

  //  5
  // X 99
  rmv.insert(99);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("5 99 \n", output);

  rmv.remove(99);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("5 \n", output);
}

TEST_F(BinarySearchTreeTest, RemoveRootWithLeafs) {
  //   5
  // 1  x
  rmv.insert(5);
  rmv.insert(1);

  capture(&rmv);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 5 \n", output);

  //   1
  // x  x
  rmv.remove(5);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 \n", output);

  //   1
  // x  2
  rmv.insert(2);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 2 \n", output);

  //   1
  // x   2
  //   x  3
  rmv.insert(3);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("1 2 3 \n", output);

  //   2
  // x  3
  rmv.remove(1);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("2 3 \n", output);

  // 3
  rmv.remove(2);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("3 \n", output);

  // x
  rmv.remove(3);
  capture(&rmv);
  output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("empty\n", output);
}

TEST_F(BinarySearchTreeTest, Depth) {
  bst.insert(10);
  EXPECT_EQ(bst.depth(), 1);

  bst.insert(5);
  bst.insert(15);
  EXPECT_EQ(bst.depth(), 2);

  bst.insert(1);
  bst.insert(8);
  bst.insert(12);
  bst.insert(20);
  EXPECT_EQ(bst.depth(), 3);

  bst.insert(100);
  EXPECT_EQ(bst.depth(), 4);

  bst.remove(100);
  EXPECT_EQ(bst.depth(), 3);
}

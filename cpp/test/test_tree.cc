#include <gtest/gtest.h>

#include "../include/tree.hpp"

class TreeNodeTest : public testing::Test {
protected:
  TreeNode<int> *node1, *node2;

  void SetUp() override {
    node1 = new TreeNode<int>();
    node2 = new TreeNode<int>(100);
  }

  virtual void TearDown() override {
    delete node1;
    delete node2;
  }
};

TEST_F(TreeNodeTest, Init) {
  EXPECT_EQ(node1->val_, 0);
  EXPECT_EQ(node1->right_, nullptr);
  EXPECT_EQ(node1->left_, nullptr);
}

TEST_F(TreeNodeTest, InitWithArgs) {
  EXPECT_EQ(node2->val_, 100);
  EXPECT_EQ(node2->right_, nullptr);
  EXPECT_EQ(node2->left_, nullptr);
}

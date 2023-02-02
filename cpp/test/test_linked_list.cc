#include <gtest/gtest.h>

#include "../include/linked_list_node.hpp"

class LinkedListTest : public testing::Test {
protected:
  LinkedListNode *l1;
  LinkedListNode *l2;

  void SetUp() override {
    l1 = new LinkedListNode();
    l2 = new LinkedListNode(1);
  }

  virtual void TearDown() override {
    delete l1;
    delete l2;
  }
};

TEST_F(LinkedListTest, DefaultValue) {
  ASSERT_TRUE(l1->m_val == 0);
}

TEST_F(LinkedListTest, AddingInitialValue) {
  ASSERT_TRUE(l2->m_val == 1);
}

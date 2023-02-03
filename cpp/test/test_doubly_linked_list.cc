#include <gtest/gtest.h>

#include "../include/doubly_linked_list_node.hpp"

class DoublyLinkedListTest : public testing::Test {
protected:
  DoublyLinkedListNode *l1, *l2;

  void SetUp() override {
    l1 = new DoublyLinkedListNode();
    l2 = new DoublyLinkedListNode(999);
  }

  virtual void TearDown() override {
    delete l1;
    delete l2;
  }
};

TEST_F(DoublyLinkedListTest, DefaultValue) {
  ASSERT_TRUE(l1->m_val == 0);
  EXPECT_EQ(l1->m_next, nullptr);
  EXPECT_EQ(l1->m_prev, nullptr);
}

TEST_F(DoublyLinkedListTest, AddingInitialValue) {
  ASSERT_TRUE(l2->m_val == 999);
  EXPECT_EQ(l2->m_next, nullptr);
  EXPECT_EQ(l2->m_prev, nullptr);
}

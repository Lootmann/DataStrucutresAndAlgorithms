#include <gtest/gtest.h>

#include "../include/linked_list_node.hpp"

TEST(LinkedListConstructure, DefaultValue) {
  LinkedListNode *l = new LinkedListNode();

  ASSERT_TRUE(l->m_val == 0);
}

TEST(LinkedListConstructure, AddingInitialValue) {
  LinkedListNode *l = new LinkedListNode(1);
  ASSERT_TRUE(l->m_val == 1);
}

#pragma once

#include <iostream>

class LinkedListNode {
public:
  int m_val;
  LinkedListNode *m_next;

  LinkedListNode(int = 0);
  ~LinkedListNode();
};

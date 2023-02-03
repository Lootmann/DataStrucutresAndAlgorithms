#pragma once

class DoublyLinkedListNode {
public:
  int m_val;
  DoublyLinkedListNode *m_next, *m_prev;

  DoublyLinkedListNode(int = 0);
  ~DoublyLinkedListNode();
};

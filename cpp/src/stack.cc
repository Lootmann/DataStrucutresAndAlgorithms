// src/stack.cc
#include "../include/stack.hpp"

Stack::Stack() {
  dummy = new LinkedListNode(-1);
  dummy->m_next = dummy;
}

void Stack::push(int val) {
  auto new_node = new LinkedListNode(val);
  new_node->m_next = dummy->m_next;
  dummy->m_next = new_node;
  m_size++;
}

int Stack::top() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }

  return dummy->m_next->m_val;
}

LinkedListNode* Stack::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }

  m_size--;
  auto popped = dummy->m_next;

  dummy->m_next = dummy->m_next->m_next;
  return popped;
}

bool Stack::empty() {
  return dummy->m_next == dummy;
}

int Stack::size() const {
  return m_size;
}

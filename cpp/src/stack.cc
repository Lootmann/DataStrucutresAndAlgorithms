// src/stack.cc
#include "../include/stack.hpp"

Stack::Stack() : m_size(0), head{nullptr} {}

Stack::~Stack() {
  while (!empty()) {
    LinkedListNode* tmp = head;
    head = head->m_next;
    delete tmp;
  }
}

void Stack::push(int val) {
  auto new_node = new LinkedListNode(val);

  if (empty()) {
    head = new_node;
  } else {
    new_node->m_next = head;
    head = new_node;
  }

  m_size++;
}

int Stack::top() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }

  return head->m_val;
}

int Stack::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }

  m_size--;

  int p = head->m_val;
  auto tmp = head;
  head = head->m_next;
  delete tmp;

  return p;
}

bool Stack::empty() {
  return head == nullptr;
}

int Stack::size() const {
  return m_size;
}

// MinStack
MinStack::MinStack() : m_size(0) {}

MinStack::~MinStack() {}

void MinStack::push(int val) {
  m_current.push(val);

  if (m_min.empty()) {
    m_min.push(val);
  } else if (m_min.top() > val) {
    m_min.push(val);
  } else {
    m_min.push(m_min.top());
  }

  m_size++;
}

int MinStack::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }

  m_size--;
  int popped = m_current.pop();
  m_min.pop();
  return popped;
}

int MinStack::top() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }

  return m_current.top();
}

int MinStack::min() {
  if (empty()) {
    throw std::out_of_range("Stack is Empty");
  }
  return m_min.top();
}

bool MinStack::empty() {
  return m_current.empty() || m_min.empty();
}

int MinStack::size() const {
  return m_size;
}

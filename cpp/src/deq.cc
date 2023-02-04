#include "../include/deq.hpp"

Deq::Deq() : m_size(0) {
  m_head = new DoublyLinkedListNode(-1);

  m_head->m_next = m_head;
  m_head->m_prev = m_head;
}

// NOTE: Dumb, Ugly, Confusing.
//       There must be a more concise way to make this code beautify
Deq::~Deq() {
  if (empty()) {
    delete m_head;
    return;
  }

  // Stupid
  DoublyLinkedListNode *tmp = m_head->m_next, *current{};
  while (current = tmp, m_head != tmp->m_next) {
    tmp = tmp->m_next;
    delete current;
  }

  // 2 delete commands make it Ugly.
  delete tmp;
  delete m_head;
}

//
// Queue Operations
//
void Deq::push_front(int val) {
  auto new_node = new DoublyLinkedListNode(val);

  new_node->m_prev = m_head->m_prev;
  m_head->m_prev->m_next = new_node;
  m_head->m_prev = new_node;
  new_node->m_next = m_head;

  m_size++;
}

int Deq::pop_front() {
  if (empty()) throw std::out_of_range("Queue is Empty");

  auto qued_node = m_head->m_prev;
  int val = qued_node->m_val;

  m_head->m_prev->m_prev->m_next = m_head;
  m_head->m_prev = m_head->m_prev->m_prev;

  delete qued_node;
  m_size--;

  return val;
}

int Deq::front() {
  if (empty()) throw std::out_of_range("Queue is Empty");
  return m_head->m_prev->m_val;
}

//
// Stack Operations
//
void Deq::push_back(int val) {
  auto new_node = new DoublyLinkedListNode(val);

  new_node->m_next = m_head->m_next;
  m_head->m_next->m_prev = new_node;
  m_head->m_next = new_node;
  new_node->m_prev = m_head;

  m_size++;
}

int Deq::pop_back() {
  if (empty()) throw std::out_of_range("Stack is Empty");

  auto poped_node = m_head->m_next;
  int val = poped_node->m_val;

  m_head->m_next->m_next->m_prev = m_head;
  m_head->m_next = m_head->m_next->m_next;

  delete poped_node;
  m_size--;
  return val;
}

int Deq::back() {
  if (empty()) throw std::out_of_range("Stack is Empty");
  return m_head->m_next->m_val;
}

// utils
bool Deq::empty() const {
  return m_head == m_head->m_next || m_head == m_head->m_prev;
}

int Deq::size() const {
  return m_size;
}

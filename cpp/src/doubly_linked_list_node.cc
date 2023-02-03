#include "../include/doubly_linked_list_node.hpp"

DoublyLinkedListNode::DoublyLinkedListNode(int val)
    : m_val(val), m_next(nullptr), m_prev(nullptr) {}

DoublyLinkedListNode::~DoublyLinkedListNode() {}

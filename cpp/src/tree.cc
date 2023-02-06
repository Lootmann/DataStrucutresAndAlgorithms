#include "../include/tree.hpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : m_size(0), head_(nullptr) {}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
  delete head_;
}

template <class T>
void BinarySearchTree<T>::insert(T val) {
  if (head_ == nullptr) {
    m_size++;
    head_ = new TreeNode<T>(val);
  } else {
    insert_(head_, val);
  }
}

template <class T>
void BinarySearchTree<T>::insert_(TreeNode<T> *node, T val) {
  if (node == nullptr) {
    node = new TreeNode<T>(val);
    return;
  }

  if (val < node->val_) {
    if (node->left_ == nullptr) {
      m_size++;
      node->left_ = new TreeNode<T>(val);
      return;
    } else {
      insert_(node->left_, val);
    }
  } else if (node->val_ < val) {
    if (node->right_ == nullptr) {
      m_size++;
      node->right_ = new TreeNode<T>(val);
      return;
    } else {
      insert_(node->right_, val);
    }
  }
}

template <class T>
TreeNode<T> *BinarySearchTree<T>::find(T val) {
  return find_(head_, val);
}

template <class T>
TreeNode<T> *BinarySearchTree<T>::find_(TreeNode<T> *node, T val) {
  if (node == nullptr) return nullptr;
  if (node->val_ == val) return node;

  if (val < node->val_) {
    return find_(node->left_, val);
  } else {
    return find_(node->right_, val);
  }
}

template <class T>
bool BinarySearchTree<T>::contains(T val) {
  return contains_(head_, val);
}

template <class T>
bool BinarySearchTree<T>::remove(T val) {
  return true;
}

template <class T>
bool BinarySearchTree<T>::remove_(TreeNode<T> *node, T val) {
  return true;
}

template <class T>
bool BinarySearchTree<T>::contains_(TreeNode<T> *node, T val) {
  if (node == nullptr) return false;
  if (node->val_ == val) return true;

  if (val < node->val_) {
    return contains_(node->left_, val);
  } else {
    return contains_(node->right_, val);
  }
}

template <class T>
int BinarySearchTree<T>::size() const {
  return m_size;
}

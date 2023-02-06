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
bool BinarySearchTree<T>::remove(T val) {
  std::cout << val << '\n';
  return true;
}

template <class T>
bool BinarySearchTree<T>::remove_(TreeNode<T> *node, T val) {
  std::cout << node->val_ << '\n';
  std::cout << val << '\n';
  return true;
}

//
// Traverse
//
template <class T>
void BinarySearchTree<T>::inorder() {
  if (head_ == nullptr) {
    std::cout << "empty" << '\n';
    return;
  }
  inorder_(head_);
  std::cout << '\n';
}

// NOTE:
//    std::cout is hard to test ... 🤔
// NOTE:
//    this is easy to test, see test/test_bst.cc testing::internal::Capture()
template <class T>
void BinarySearchTree<T>::inorder_(TreeNode<T> *node) {
  if (node != nullptr) {
    inorder_(node->left_);
    std::cout << node->val_ << ' ';
    inorder_(node->right_);
  }
}

template <class T>
void BinarySearchTree<T>::postorder() {
  if (head_ == nullptr) {
    std::cout << "empty" << '\n';
    return;
  }
  postorder_(head_);
  std::cout << '\n';
}

template <class T>
void BinarySearchTree<T>::postorder_(TreeNode<T> *node) {
  if (node != nullptr) {
    postorder_(node->left_);
    postorder_(node->right_);
    std::cout << node->val_ << ' ';
  }
}

template <class T>
void BinarySearchTree<T>::preorder() {
  if (head_ == nullptr) {
    std::cout << "empty" << '\n';
    return;
  }
  preorder_(head_);
  std::cout << '\n';
}

template <class T>
void BinarySearchTree<T>::preorder_(TreeNode<T> *node) {
  if (node != nullptr) {
    std::cout << node->val_ << ' ';
    preorder_(node->left_);
    preorder_(node->right_);
  }
}

template <class T>
int BinarySearchTree<T>::size() const {
  return m_size;
}

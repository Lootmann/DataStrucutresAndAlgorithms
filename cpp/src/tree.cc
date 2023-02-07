#include "../include/tree.hpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : head_(nullptr) {}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
  delete head_;
}

template <class T>
void BinarySearchTree<T>::insert(T val) {
  if (head_ == nullptr) {
    head_ = new TreeNode<T>(val);
  } else {
    insert_(head_, val);
  }
}

template <class T>
TreeNode<T> *BinarySearchTree<T>::insert_(TreeNode<T> *root, T key) {
  if (root == nullptr) {
    return new TreeNode<T>(key);
  }

  if (key < root->val_) {
    root->left_ = insert_(root->left_, key);
  }

  else {
    root->right_ = insert_(root->right_, key);
  }

  return root;
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
//    this is easy to stdout test,
//    see test/test_bst.cc testing::internal::Capture()
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

#include "../include/tree.hpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : head_(nullptr) {}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
  if (head_ == nullptr) return;
  delete head_;
}

// template <class T>
// void BinarySearchTree<T>::destructNode(TreeNode<T> *node) {
//   if (node) {
//     destructNode(node->left_);
//     destructNode(node->right_);
//     delete node;
//   }
// }

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

template <class T>
TreeNode<T> *BinarySearchTree<T>::remove_(TreeNode<T> *root, T val) {
  if (root == nullptr) return nullptr;

  if (val < root->val_) {
    root->left_ = remove_(root->left_, val);
  }

  else if (root->val_ < val) {
    root->right_ = remove_(root->right_, val);
  }

  else {
    if (root->left_ == nullptr && root->right_ == nullptr) {
      root = nullptr;
    }

    else if (root->left_ == nullptr) {
      TreeNode<T> *tmp = root;
      root = root->right_;
      tmp = nullptr;
      delete tmp;
    }

    else if (root->right_ == nullptr) {
      TreeNode<T> *tmp = root;
      root = root->left_;
      tmp = nullptr;
      delete tmp;
    }

    else {
      TreeNode<T> *tmp = findMin(root->right_);
      root->val_ = tmp->val_;
      root->right_ = remove_(root->right_, tmp->val_);
    }
  }
  return root;
}

template <class T>
void BinarySearchTree<T>::remove(T val) {
  head_ = remove_(head_, val);
}

template <class T>
TreeNode<T> *BinarySearchTree<T>::findMin(TreeNode<T> *node) {
  while (node->left_ != nullptr) node = node->left_;
  return node;
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

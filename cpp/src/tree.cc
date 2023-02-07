#include "../include/tree.hpp"

using std::cerr;
using std::cout;
using std::endl;

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

template <class T>
void BinarySearchTree<T>::remove_(TreeNode<T> *&root, T key) {
  using Node = TreeNode<T>;

  Node *parent = nullptr;
  Node *curr = root;

  findKeyNode(curr, key, parent);

  if (parent == nullptr) {
  } else {
  }

  if (curr == nullptr) {
    return;
  }

  // ケース1：削除するノードに子がない、つまりリーフノードである
  if (curr->left_ == nullptr && curr->right_ == nullptr) {
    // 削除するノードがルートノードでない場合は、
    // 親の左/右の子をnullに
    if (curr != root) {
      if (parent->left_ == curr) {
        parent->left_ = nullptr;
      } else {
        parent->right_ = nullptr;
      }
    }
    // ツリーにルートノードしかない場合は、nullに設定します
    else {
      root = nullptr;
    }

    // メモリの割り当てを解除します
    delete curr;
  }

  // ケース2：削除するノードに2つの子があります
  else if (curr->left_ && curr->right_) {
    // その順序の後続ノードを見つける
    Node *successor = successor_(curr->right_);

    // 後続の値を保存します
    int v = successor->val_;

    // サクセサを再帰的にに削除します。後継者に注意してください
    // 最大で1つの子(右の子)があります
    remove_(root, successor->val_);

    // サクセサの値を現在のノードにコピーします
    curr->val_ = v;
  }

  // ケース3：削除するノードに子が1つしかない
  else {
    // 子ノードを選択します
    Node *child = (curr->left_) ? curr->left_ : curr->right_;

    // 削除するノードがルートノードでない場合は、その親を設定します
    // その子に
    if (curr != root) {
      if (curr == parent->left_) {
        parent->left_ = child;
      } else {
        parent->right_ = child;
      }
    } else {
      // 削除するノードがルートノードの場合、ルートを子に設定します
      root = child;
    }

    // メモリの割り当てを解除します
    delete curr;
  }
}

template <class T>
bool BinarySearchTree<T>::remove(T val) {
  remove_(head_, val);
  return true;
}

template <class T>
void BinarySearchTree<T>::findKeyNode(TreeNode<T> *&curr, T key,
                                      TreeNode<T> *&parent) {
  while (curr != nullptr && curr->val_ != key) {
    parent = curr;

    if (key < curr->val_) {
      curr = curr->left_;
    } else {
      curr = curr->right_;
    }
  }
}

// find a Node within right subtree
template <class T>
TreeNode<T> *BinarySearchTree<T>::successor_(TreeNode<T> *node) {
  while (node->left_ != nullptr) {
    node = node->left_;
  }
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

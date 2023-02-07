#pragma once

#include <iostream>

template <class T>
class TreeNode {
public:
  T val_;
  TreeNode<T> *left_, *right_;

  TreeNode() : TreeNode(0) {}
  TreeNode(T val) : val_{val}, left_{nullptr}, right_{nullptr} {}
  ~TreeNode() {
    delete left_;
    delete right_;
  }
};

template <class T>
class BinarySearchTree {
private:
  TreeNode<T> *head_;
  TreeNode<T> *insert_(TreeNode<T> *, T);
  TreeNode<T> *find_(TreeNode<T> *, T);
  void remove_(TreeNode<T> *&, T);
  void findKeyNode(TreeNode<T> *&, T, TreeNode<T> *&);
  TreeNode<T> *successor_(TreeNode<T> *);

  // traverse
  void inorder_(TreeNode<T> *);
  void preorder_(TreeNode<T> *);
  void postorder_(TreeNode<T> *);

public:
  BinarySearchTree();
  ~BinarySearchTree();

  void insert(T);
  TreeNode<T> *find(T);
  bool remove(T);

  // traverse
  void inorder();
  void preorder();
  void postorder();
};

template class BinarySearchTree<int>;
template class BinarySearchTree<long>;
template class BinarySearchTree<long long>;
template class BinarySearchTree<double>;
// template class BinarySearchTree<char>; // can't compare :^)

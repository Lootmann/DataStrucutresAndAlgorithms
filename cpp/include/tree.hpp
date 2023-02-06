#pragma once

#include <iostream>
#include <string>

using std::string;

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
  int m_size;
  TreeNode<T> *head_;
  void insert_(TreeNode<T> *, T);
  TreeNode<T> *find_(TreeNode<T> *, T);
  bool remove_(TreeNode<T> *, T);
  bool contains_(TreeNode<T> *, T);

public:
  BinarySearchTree();
  ~BinarySearchTree();

  void insert(T);
  TreeNode<T> *find(T);
  bool remove(T);
  bool contains(T);

  int size() const;
};

template class BinarySearchTree<int>;
template class BinarySearchTree<long>;
template class BinarySearchTree<long long>;
template class BinarySearchTree<double>;
template class BinarySearchTree<char>;

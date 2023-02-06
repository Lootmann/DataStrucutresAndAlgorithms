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

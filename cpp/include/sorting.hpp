#pragma once

#include <iostream>
#include <vector>

// for simplicity use vector<T>
template <typename T>
class Sorting {
private:
  static void Merge(std::vector<T> &, int, int, int);

public:
  static void BubbleSort(std::vector<T> &);
  static void SelectionSort(std::vector<T> &);
  static void InsertionSort(std::vector<T> &);
  static void MergeSort(std::vector<T> &, int, int);
};

template class Sorting<int>;
template class Sorting<long>;
template class Sorting<long long>;
template class Sorting<double>;
template class Sorting<float>;
template class Sorting<char>;

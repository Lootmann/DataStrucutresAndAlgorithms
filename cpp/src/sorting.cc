#include "../include/sorting.hpp"

template <typename T>
void Sorting<T>::BubbleSort(std::vector<T> &vec) {
  for (size_t i = 1; i < vec.size(); ++i) {
    bool is_end = true;

    for (size_t j = 0; j < vec.size() - i; ++j) {
      // swap
      if (vec.at(j) > vec.at(j + 1)) {
        T tmp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = tmp;
        is_end = false;
      }
    }

    if (is_end) return;
  }
}

template <typename T>
void Sorting<T>::SelectionSort(std::vector<T> &v) {
  size_t size = v.size();

  for (size_t i = 0; i < size - 1; ++i) {
    size_t min_idx = i;

    for (size_t j = i + 1; j < size; ++j) {
      if (v[j] < v[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      T tmp = v[min_idx];
      v[min_idx] = v[i];
      v[i] = tmp;
    }
  }
}

template <typename T>
void Sorting<T>::InsertionSort(std::vector<T> &v) {
  T key;
  int size = (int)v.size();

  for (int i = 1; i < size; ++i) {
    key = v[i];
    int j = i - 1;

    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j = j - 1;
    }

    v[j + 1] = key;
  }
}

template <typename T>
void Sorting<T>::Merge(std::vector<T> &v, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<T> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = v[left + i];
  }

  for (int i = 0; i < n2; i++) {
    R[i] = v[mid + 1 + i];
  }

  int i = 0, j = 0, k = mid;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      v[k] = L[i++];
    } else {
      v[k] = R[j++];
    }
    k++;
  }

  while (i < n1) {
    v[k] = L[i];
    k++, i++;
  }

  while (j < n2) {
    v[k] = R[j];
    k++, j++;
  }
}

template <typename T>
void Sorting<T>::MergeSort(std::vector<T> &v, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    Merge(v, left, mid, right);
  }
}

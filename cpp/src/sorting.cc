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

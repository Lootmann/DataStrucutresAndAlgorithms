#pragma once

#include <cassert>
#include <iostream>

template <class Array>
struct array_iterator {
  Array &a_;
  std::size_t i_;

  array_iterator(Array &a, std::size_t i) : a_(a), i_(i) {}

  array_iterator operator++() {
    ++i_;
    return *this;
  }

  array_iterator operator++(int) {
    struct array_iterator copy = *this;
    ++*this;
    return copy;
  }

  array_iterator &operator--() {
    --i_;
    return *this;
  }

  array_iterator operator--(int) {
    struct array_iterator copy = *this;
    --*this;
    return copy;
  }

  bool operator==(array_iterator const &r) const {
    return i_ == r.i_;
  }

  bool operator!=(array_iterator const &r) const {
    return i_ != r.i_;
  }

  array_iterator &operator+=(std::size_t n) {
    i_ += n;
    return *this;
  }

  array_iterator operator+(std::size_t n) const {
    auto copy = *this;
    copy += n;
    return copy;
  }

  array_iterator &operator-=(std::size_t n) {
    i_ -= n;
    return *this;
  }

  array_iterator &operator-(std::size_t n) const {
    auto copy = *this;
    copy -= n;
    return *this;
  }

  typename Array::reference operator[](std::size_t n) const {
    return *(*this + n);
  }

  typename Array::reference operator*() {
    return a_[i_];
  }

  // comparison
  bool operator<(array_iterator const &right) const {
    return i_ < right.i_;
  }

  bool operator<=(array_iterator const &right) const {
    return i_ <= right.i_;
  }

  bool operator>(array_iterator const &right) const {
    return i_ > right.i_;
  }

  bool operator>=(array_iterator const &right) const {
    return i_ >= right.i_;
  }
};

/* template <class Array> */
/* struct array_iterator_begin { */
/*   Array &a_; */
/*   array_iterator_begin(Array &a) : a_(a) {} */
/* }; */

template <class T, size_t N>
class array {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = std::size_t;

  value_type storage[N];

  // []
  reference operator[](size_type i) {
    return storage[i];
  }

  reference operator[](size_type i) const {
    return storage[i];
  }

  reference at(size_type n) {
    if (n >= N) throw std::out_of_range("Error: out of range");
    return storage[n];
  }

  using iterator = array_iterator<array>;

  // begin
  iterator begin() {
    return array_iterator(*this, 0);
  }

  // end
  iterator end() {
    return array_iterator(*this, N);
  }

  // front
  reference front() {
    return storage[0];
  }

  const_reference front() const {
    return storage[0];
  }

  // back
  reference back() {
    return storage[N - 1];
  }

  const_reference back() const {
    return storage[N - 1];
  }

  void fill(T const &u) {
    for (size_t i = 0; i < N; ++i) {
      storage[i] = u;
    }
  }
};

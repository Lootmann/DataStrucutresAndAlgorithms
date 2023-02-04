#pragma once

//
// Separate Compile
//
template <class T>
class Foo {
private:
  int size_;

public:
  Foo();
  ~Foo();
  T add(T a, T b);
  int size() const;
};

// explicit instantiations
template class Foo<int>;
template class Foo<long int>;
template class Foo<long long int>;
template class Foo<double>;
template class Foo<float>;

//
// Definition and Implementation at same time
// I think this impl is better to read than above separting.
//
template <class T>
class Bar {
private:
  int size_;

public:
  Bar() : size_(100) {}
  ~Bar() {}

  T add(T a, T b) {
    return a + b;
  }

  T mul(T a, T b) {
    return a * b;
  }

  int size() const {
    return size_;
  }
};

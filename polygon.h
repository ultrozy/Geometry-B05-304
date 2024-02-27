#ifndef POLYGON_H_
#define POLYGON_H_

#include <cstddef>
#include <ios>
#include "point.h"
#include "vector.h"

template <class T>
class Polygon;

template <class T>
std::ostream& operator<<(std::ostream&, const Polygon<T>&);

template <class T>
class Polygon {
  Point<T>* array_;
  size_t size_;
  size_t capacity_;

 public:
  Polygon(size_t);

  Polygon(size_t, Point<T>*);

  ~Polygon();
  Polygon(const Polygon<T>&);
  Polygon<T>& operator=(const Polygon<T>&);

  Polygon(Polygon<T>&&) noexcept;
  Polygon<T>& operator=(Polygon<T>&&) noexcept;

  Point<T>& operator[](size_t index);

  friend std::ostream& operator<< <T>(std::ostream&, const Polygon<T>&);
};

template <class T>
Polygon<T>::Polygon(size_t capacity) : array_{new Point<T>[capacity]}, size_{0}, capacity_{capacity} {
}

template <class T>
Polygon<T>::Polygon(size_t size, Point<T>* array) : array_{new Point<T>[size]}, size_{size}, capacity_{size} {
  for (size_t i = 0; i < size; ++i) {
    array_[i] = array[i];
  }
}

template <class T>
Polygon<T>::Polygon(const Polygon<T>& other) : array_{new Point<T>[other.size_]}, size_{other.size}, capacity_{size_} {
  for (size_t i = 0; i < size_; ++i) {
    array_[i] = other.array_[i];
  }
}

template <class T>
Polygon<T>::Polygon(Polygon<T>&& other) noexcept
    : array_{other.array_}, size_{other.size_}, capacity_{other.capacity_} {
  other.array_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <class T>
Polygon<T>& Polygon<T>::operator=(const Polygon<T>& other) {
  if (this == &other) {
    return *this;
  }
  delete[] array_;
  size_ = other.size_;
  capacity_ = size_;
  array_ = new Point<T>[size_];
  for (size_t i = 0; i < size_; ++i) {
    array_[i] = other.array_[i];
  }
  return *this;
}

template <class T>
Polygon<T>& Polygon<T>::operator=(Polygon<T>&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  delete[] array_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  array_ = other.array_;
  other.capacity_ = other.size_ = 0;
  other.array_ = nullptr;
  return *this;
}

template <class T>
Polygon<T>::~Polygon() {
  delete[] array_;
}

template <class T>
Point<T>& Polygon<T>::operator[](size_t index) {
  return array_[index];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Polygon<T>& poly) {
  for (size_t i = 0; i < poly.size_; ++i) {
    os << poly.array_[i] << '\n';
  }
  return os;
}

#endif
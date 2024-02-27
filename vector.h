#ifndef VECTOR_H_
#define VECTOR_H_

#include "point.h"

template <class T>
struct Vector {
  T x = 0;
  T y = 0;

  explicit Vector(const Point<T>&);
  Vector(const Point<T>&, const Point<T>&);

  Vector<T> operator+() const;
  Vector<T> operator-() const;
  T Norm() const;

  Vector<T>& operator+=(const Vector<T>&);
};

template <class T>
Vector<T>::Vector(const Point<T>& p) : x{p.x}, y{p.y} {
}

template <class T>
Vector<T>::Vector(const Point<T>& a, const Point<T>& b) : x{b.x - a.x}, y{b.y - a.y} {
}

template <class T>
Vector<T> Vector<T>::operator+() const {
  return *this;
}

template <class T>
Vector<T> Vector<T>::operator-() const {
  return {-x, -y};
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
  this->x += other.x;
  y += other.y;
  return *this;
}

template <class T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) {
  return {v1.x + v2.x, v1.y + v2.y};
}

template <class T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) {
  return {v1.x - v2.x, v1.y - v2.y};
}

template <class T>
T DotProduct(const Vector<T>& a, const Vector<T>& b) {
  return a.x * b.x + a.y * b.y;
}

template <class T>
T OuterProduct(const Vector<T>& a, const Vector<T>& b) {
  return a.x * b.y - a.y * b.x;
}

template <class T>
T Vector<T>::Norm() const {
  return x * x + y * y;
}

#endif
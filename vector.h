#include <point.h>

template <class T>
struct Vector {
  T x = 0;
  T y = 0;

  Vector(Point<T>);

  Vector<T> operator+() const;
  Vector<T> operator-() const;

  Vector<T>& operator+=(const Vector<T>&);
};

template <class T>
Vector<T>::Vector(Point<T> p) : x{p.x}, y{p.y} {
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

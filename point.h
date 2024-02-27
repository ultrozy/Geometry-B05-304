#ifndef POINT_H_
#define POINT_H_

#include <ios>
template <class T>
struct Point {
  T x = 0;
  T y = 0;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
  return os << point.x << ' ' << point.y;
}

#endif
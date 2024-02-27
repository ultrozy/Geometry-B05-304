#include <iostream>
#include <algorithm>
#include "point.h"
#include "vector.h"
#include "polygon.h"

template <class T>
Polygon<T> Graham(size_t size, Point<T>* array) {
  auto stack = new Point<T>[size];
  stack[0] = array[0];
  for (size_t i = 1; i < size; ++i) {
    if (stack[0].y > array[i].y || (stack[0].y == array[i].y && stack[0].x > array[i].x)) {
      stack[0] = array[i];
    }
  }
  std::sort(array, array + size, [&stack](const Point<T>& pa, const Point<T>& pb) {
    Vector<T> a(stack[0], pa);
    Vector<T> b(stack[0], pb);
    T angle = OuterProduct(a, b);
    if (angle != 0) {
      return angle > 0;
    }
    return a.Norm() < b.Norm();
  });

  size_t stack_size = 1;
  for (size_t i = 0; i < size; ++i) {
    while (stack_size >= 2) {
      Vector<T> vec1(stack[stack_size - 2], stack[stack_size - 1]);
      Vector<T> vec2(stack[stack_size - 1], array[i]);
      if (OuterProduct(vec1, vec2) > 0) {
        break;
      } else {
        --stack_size;
      }
    }
    stack[stack_size++] = array[i];
  }
  Polygon<T> convex_hull(stack_size, stack);
  delete[] stack;
  return convex_hull;
}

int main() {
  using Pt = Point<int>;

  Pt arr[2]{{0, 0}, {0, 1}};
  auto ch = Graham(2, arr);
  std::cout << ch;
  return 0;
}
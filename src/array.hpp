#ifndef __ARRAY__
#define __ARRAY__
#include <vector>
#include <algorithm>
#include <cmath>

namespace algorithms { 
namespace array {

/**
 * Partition the elements of an array 
 * such that all elements satisfying predicate p
 * are at the left of all other elements.
 * Runtime complexity : O(n).
 */
template <typename T, typename P>
void partition(::std::vector<T> *vp, P p) {
  auto &v = *vp;
  int i1 = 0, i2 = v.size()-1;
  while (i1 <= i2) {
    if (p(v[i1])) ++i1;
    else ::std::swap(v[i1],v[i2--]);
  }
}

/**
 * 3-way-partition the elements of an array 
 * such that all elements are partitioned in 3 areas:
 * less than pivot - equal to pivot - greater than pivot.
 * Runtime complexity : O(n).
 */
template <typename T>
void partition(::std::vector<T> *vp, const T &pivot) {
  auto &v = *vp;
  int i1 = 0, i2 = 0, i3 = v.size()-1;
  while (i2 <= i3) {
    if (v[i2] == pivot) ++i2;
    else if (v[i2] < pivot) ::std::swap(v[i1++],v[i2++]);
    else ::std::swap(v[i2], v[i3--]);
  }
}

/**
 * Partition the elements of an integer array 
 * such that even elements are at the left of odd elements.
 * Runtime complexity : O(n).
 */
void even_odd(::std::vector<int> *vp);

/**
 * Increment an arbitrary-precision unsigned integer,
 * represented as a vector, where the MSB is at index 0.
 * Runtime complexity : O(n).
 */
void increment(::std::vector<int> *vp);

/**
 * Multiply two arbitrary-precision integers
 * represented as vectors a and b of integers in the range [0-9]
 * of sizes n and m respectively, with the MSB at index 0. 
 * The MSB might be negative, to represent negative numbers.
 * Runtime complexity : O(mn)
 */
::std::vector<int> multiply(const ::std::vector<int> &a, const ::std::vector<int> &b);

/**
 * Given an array of n integers a, 
 * a[i] denotes the maximum you can advance from index i. 
 * Return the minimum number of steps to advance to the last index
 * starting from the beginning of the array, or -1 if the last index is unreachable.
 * Runtime complexity : O(n)
 */
int can_reach_end(const ::std::vector<int> &a);

/**
 * Given a sorted array of n integers a,
 * remove all duplicate elements and
 * return the new length of the array.
 * Runtime complexity : O(n)
 */
int delete_dupes(::std::vector<int> *vp);

/**
 * Given an array v of n elements of type double,
 * denoting the daily stock price,
 * return the maximum profit that could be made 
 * by buying and then selling one share of that stock.
 * Runtime complexity : O(n)
 */
double buy_and_sell_stock_once(const ::std::vector<double> &v);

/**
 * Given an array v of n elements of type double,
 * denoting the daily stock price,
 * return the maximum profit that could be made 
 * by buying and then selling one share of that stock at most twice.
 * Runtime complexity : O(n)
 */
double buy_and_sell_stock_twice(const ::std::vector<double> &v);

} // array
} // algorithms

#endif
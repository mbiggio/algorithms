#ifndef _BIT_
#define _BIT_
#include <vector>
#include <algorithm>

namespace algorithms {
namespace bit {

/**
 * A Binary-Indexed Tree, useful to perform count range queries
 * on a set of pre-defined keys, whose occurrences can be
 * dynamically updated.
 * When the set of possible values over which count range queries
 * have to be performed is known in advance,
 * it is an easier-to.implement alternative to BSTs with order statistics.
 * It can answer to queries like:
 *  - how many keys smaller than (or equal to) a given value are there in the set?
 *  - how many keys in the range [low,high] are there in the set?
 * Keys can be repeated.
 */
template<typename T>
class bit {
public:    
    bit(const ::std::vector<T> &ref);
    int countSmaller(const T &val);
    int countSmallerOrEqual(const T &val);
    void update(const T &val);

protected:
    int _count(int idx);
    void _update(int idx);

private:
    const ::std::vector<T> &_ref;
    ::std::vector<int> _bit;
};

template <typename T>
bit<T>::bit(const ::std::vector<T> &ref) :
  _ref(ref), 
  _bit(ref.size()+1) 
{};

/*********** bit *************/
template<typename T>
int bit<T>::countSmaller(const T &val) {
  int idx=lower_bound(_ref.begin(),_ref.end(),val)-_ref.begin();
  return _count(idx);
}

template<typename T>
int bit<T>::countSmallerOrEqual(const T &val) {
  int idx=upper_bound(_ref.begin(),_ref.end(),val)-_ref.begin();
  return _count(idx);
}

template<typename T>
void bit<T>::update(const T &val) {
  int idx=upper_bound(_ref.begin(),_ref.end(),val)-_ref.begin();
  _update(idx);
}

template<typename T>
int bit<T>::_count(int idx) {
  int c=0;
  while (idx>0) {
    c+=_bit[idx];
    idx-=idx&-idx;
  }
  return c;                
}

template<typename T>
void bit<T>::_update(int idx) {
  while (idx<_bit.size()) {
    _bit[idx]+=1;
    idx+=idx&-idx;
  }            
}    

/**
 * You are given an integer array nums 
 * and you have to return a new counts array. 
 * The counts array has the property where counts[i] 
 * is the number of smaller elements to the right of nums[i].
 * Runtime complexity : O(nlogn)
 */
::std::vector<int> count_smaller(const ::std::vector<int>& nums);

/**
 * Given an integer array nums, 
 * return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements 
 * in nums between indices i and j (i ≤ j), inclusive.
 * Runtime complexity : O(nlogn)
 */
int count_range_sum(const ::std::vector<int>& nums, int lower, int upper);

} // bit
} // algorithms

#endif


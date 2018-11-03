#include "array.hpp"
#include <algorithm>

namespace algorithms {
namespace array {

/*********** even_odd *************/
void even_odd(::std::vector<int> *vp) {
  partition(vp, [](int x){return (x%2)==0;});
}

/*********** increment *************/
void increment(::std::vector<int> *vp) {
  auto &v = *vp;
  ::std::reverse(v.begin(),v.end());
  int carry = 1;
  for (int i=0; carry!=0 && i<v.size(); ++i) {
    v[i] += carry;
    carry = v[i]/10;
    v[i] %= 10;
  }
  if (carry) v.emplace_back(carry);
  ::std::reverse(v.begin(),v.end());
}

/*********** multiply *************/
::std::vector<int> multiply(const ::std::vector<int> &a, const ::std::vector<int> &b) {
  if (a.empty() || b.empty()) return {0};
  int sign = (a.front()*b.front()<0)?-1:1;

  ::std::vector<int> result(a.size()+b.size(),0);
  for (int i=a.size()-1; i>=0; --i) {
    int carry = 0;
    for (int j=b.size()-1; j>=0; --j) {
      result[i+j+1] += abs(a[i])*abs(b[j]) + carry;
      carry = result[i+j+1]/10;
      result[i+j+1] %= 10;
    }
    if (carry) result[i] += carry;
  }

  result = ::std::vector<int>(::std::find_if(result.begin(), result.end(), [](int n){ return n;}),result.end());
  if (result.empty()) return {0}; // this check is necessary for handling the case a = {0} or b = {0} correctly
  result.front() *= sign;
  return result;
}

/*********** can_reach_end *************/
int can_reach_end(const ::std::vector<int> &a) {
  int b = 0;
  /**
   * s[i] denotes the minimum number of steps 
   * necessary to reach index i.
   * Note that s is non-decreasing (i<j implies s[i]<=s[j]).
   * Indeed, if i<j but s[i]>s[j], that would mean 
   * that we could reach j using less steps than the ones necessary to reach i,
   * but this is a contradiction, since if we are able
   * to reach j with s[j] steps, then also i is reachable
   * with at most s[j] steps.
   */
  ::std::vector<int> s(a.size(),-1);
  s.front() = 0;
  for (int i=0; i<=b && b<a.size()-1 && i<a.size(); ++i) {
    for (int j=b+1; j <= ::std::min((int)(s.size()-1),i+a[i]); ++j) 
      /**
       * as soon as we discover a new element j to be within the new boundary,
       * we can set the minimum number of steps 
       * necessary to reach that element to s[i]+1,
       * where i is the minimum index from which index j is reachable.
       * Indeed, for each k<i, j is not reachable,
       * and for each k>i we have s[k] >= s[i].
       */
      s[j] = s[i]+1; 
    b = ::std::max(b, i+a[i]);
  }
  return s.back();
}

/*********** delete_dupes *************/
int delete_dupes(::std::vector<int> *vp) {
  auto &v = *vp;
  int read = 0, write = 0;
  while (read < v.size()) {
    int cur = v[read];
    while (read < v.size() && v[read] == cur) ++read;
    v[write++] = cur;
  }
  v.erase(v.begin()+write,v.end());
  return write;
}

/*********** buy_and_sell_stock_once *************/
double buy_and_sell_stock_once(const ::std::vector<double> &v) {
  if (v.size() <= 1) return 0.0;
  double max_profit = 0.0;
  double cur_min = v[0];
  for (int i=1; i<v.size(); ++i) {
    max_profit = ::std::max(max_profit, v[i]-cur_min);
    cur_min = ::std::min(cur_min,v[i]);
  }
  return max_profit;
}

/*********** buy_and_sell_stock_twice *************/
double buy_and_sell_stock_twice(const ::std::vector<double> &v) {
  if (v.size() <= 1) return 0.0;
  
  ::std::vector<double> max_profit_suffix(v.size());
  max_profit_suffix.back() = 0.0;
  double cur_max = v.back();
  for (int i = v.size()-2; i>=0; --i) {
    max_profit_suffix[i] = ::std::max(max_profit_suffix[i+1],cur_max-v[i]);
    cur_max = ::std::max(cur_max, v[i]);
  }

  double max_profit = max_profit_suffix[0];
  double cur_min = v[0];
  for (int i=1; i<v.size()-1; ++i) {
    max_profit = ::std::max(max_profit, v[i]-cur_min + max_profit_suffix[i+1]);
    cur_min = ::std::min(cur_min, v[i]);
  }

  return max_profit;
}

/*********** beautiful_arrangement_ii *************/
::std::vector<int> beautiful_arrangement_ii(int n, int k) {
  /**
   * The idea here is that we can always construct
   * a permutation of 1..n such that, taking the
   * absolute difference of consecutive elements,
   * we have a number h of 1s ranging from 1 to n-1,
   * while the remaining n-h differences
   * are the numbers 2,3,...,n-h occurring 
   * exacly once.
   * We can achieve this by ordering the elements
   * from 1 to h in the first part of the array,
   * and then alternating the residual max and 
   * the residual min in the second part of the array.
   * Fo example, for n = 5, we get:
   *
   * h = 4 : v = [1 - 2 - 3 - 4 - 5]
   *                1   1   1   1
   * h = 3 : v = [1 - 2 - 3 - 5 - 4]
   *                1   1   2   1
   * h = 2 : v = [1 - 2 - 5 - 3 - 4]
   *                1   3   2   1
   * h = 1 : v = [1 - 5 - 2 - 4 - 3]
   *                4   3   2   1
   *
   * The problem is solved by constructing the 
   * sequence corresponding to h = n-k.
   */
  ::std::vector<int> result(n);
  for (int i=0; i<n-k; ++i) result[i] = i+1;
  for (int i=n-k, cur=n; i<n; i+=2, --cur) result[i]=cur;
  for (int i=n-k+1, cur=n-k+1; i<n; i+=2, ++cur) result[i]=cur;
  return result;
}

} // array
} // algorithms

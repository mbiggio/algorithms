#include "dp.hpp"
#include <algorithm>

namespace algorithms {
namespace dp {

/*********** cheapest_jump *************/
::std::vector<int> cheapest_jump(const ::std::vector<int>& a, const int b) {
  ::std::vector<int> c(a.size(),-1);
  ::std::vector<int> n(a.size(),-1);
  c.back()=a.back();
  for (int i=a.size()-2; i>=0; --i) {
    if (a[i]==-1) continue;            
    for (int j=i+1; j<::std::min((int)(a.size()),i+b+1); ++j) {       
      if (c[j]!=-1 && (c[i]==-1 || c[i]>a[i]+c[j])) {
	c[i] = a[i]+c[j];
	n[i] = j;
      }
    }
  }                    
  if (c[0]==-1) return {};
  ::std::vector<int> result;
  int idx = 0;
  while(idx != -1) {
    result.push_back(idx);
    idx = n[idx];
  }
  return result;  
}

/*********** egg_drop *************/
int egg_drop(int n) {

  /**
   * Suppose you know that from floors 0..i-1
   * the egg won't break, and suppose you want to 
   * compute the minimum number of trials necessary to
   * determine the critical floor among floors [i..n-1] with 2 eggs.
   * One possibility is to use a single egg. This would cost
   * in the worst case n-i drops (when the egg never breaks).
   * On the other hand, we might try a drop from floor k,
   * where k is in [i..n-1].
   * If the egg breaks, the only way is to do an 
   * exhaustive search in [i..k-1] that will cost 
   * k-i drops in the worst case.
   * If the egg does not break, then we can use the two
   * eggs on subarray [k+1..n-1], that will cost us
   * p[k+1,j] in the worst case.
   * So the recursion ends up being:
   *
   * p[i]   = 1 + min_{k=i..n} max{k-i,p[k+1]}
   * p[n+1] = 0
   */

  ::std::vector<int> p(n+1);
  for (int i=n-1; i>=0; --i) {
    p[i] = ::std::numeric_limits<int>::max();
    for (int k=i; k<n; ++k) {
      p[i] = ::std::min(p[i],::std::max(k-i,p[k+1])+1);
    }
  }
  return p[0];
}

} // namespace dp
} // namespace algorithms


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
  ::std::vector<int> p(n);
  p.back()=1;
  for (int i=n-2; i>=0; --i) {
    p[i] = n-i; // use one egg
    for (int k=i; k<n-1; ++k) {
      p[i] = ::std::min(p[i],::std::max(k-i,p[k+1])+1);
    }
  }
  return p[0];
}

} // namespace dp
} // namespace algorithms


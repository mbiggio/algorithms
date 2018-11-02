#include "string.hpp"

namespace algorithms {
namespace string {

/*********** count_substrings *************/
int count_substrings(const ::std::string &s) {
  int n = s.size(), count = 0;
  for (int center = 0; center<2*n; ++center) {
    int left = center/2;
    int right = left + center%2;
    while (left >=0 && right < n && s[left] == s[right]) {
      ++count;
      --left;
      ++right;
    }
  }
  return count;  
}

} // string
} // algorithms

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

/*********** find_lus_length *************/
bool is_subsequence(const ::std::string &s1, int idx1, const ::std::string &s2, int idx2) {
  if (s1.size() - idx1 > s2.size() - idx2) return false;
  if (s1.size() - idx1 == 0) return true;
  if (s1[idx1] == s2[idx2]) return is_subsequence(s1,idx1+1,s2,idx2+1);
  return is_subsequence(s1,idx1,s2,idx2+1);
}

int find_lus_length(const ::std::vector<::std::string> &s) {
  /**
   * The idea of the algorithm is that 
   * the longest uncommon substring, if it exists,
   * must be one of the input strings.
   * Indeed, assume the contrary is true.
   * Let the longest uncommon substring lus 
   * be a substring of s1, so that it's not
   * a substring of si for i = 2...n.
   * This means that there is some ci in lus that
   * is not in si, for i = 2...n.
   * But each of these ci is in s1 as well,
   * so this means lus must be equal to s1.
   */
  int longest = -1;
  for (int i=0; i<s.size(); ++i) {
    bool found = false;
    for (int j=0; !found && j<s.size(); ++j) {
      if (i!=j && is_subsequence(s[i],0,s[j],0)) found = true;
    }
    if (!found) longest = ::std::max(longest,(int)s[i].size());
  }
  return longest;
}

} // string
} // algorithms

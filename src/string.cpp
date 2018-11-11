#include "string.hpp"
#include<algorithm>

namespace algorithms {
namespace string {

/*********** is_palyndrome *************/
bool is_palyndrome(const ::std::string &s) {
  for (int i=0; i<s.size()/2; ++i) {
    if (s[i] != s[s.size()-1-i]) return false;
  }
  return true;
}

/*********** string_to_int *************/
int string_to_int(const ::std::string &s) {
  int result = 0;
  if (s.empty()) return result;
  bool is_neg = s.front()=='-';
  for (int i=is_neg?1:0; i<s.size(); ++i) {
    result = result*10 + static_cast<int>(s[i]-'0');
  }
  return is_neg?-result:result; 
}

/*********** int_to_string *************/
::std::string int_to_string(const int k) {
  if (k==0) return "0";
  ::std::string result;
  for (int i = abs(k); i>0; i/=10) {
    result.push_back(static_cast<char>(i%10)+'0');
  }
  if (k<0) result.push_back('-');
  ::std::reverse(result.begin(),result.end());
  return result;
}

/*********** count_substrings *************/
void reverse_words(::std::string *sp) {
  ::std::string &s = *sp;
  for (int i=0; i<s.size();) {
    int j = i;
    while(j<s.size() && s[j]!=' ') ++j;
    ::std::reverse(s.begin()+i,s.begin()+j);
    i=j+1;
  }
  ::std::reverse(s.begin(),s.end());
}

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
   * Indeed, once an uncommon substring is found,
   * extending it to the containing string again 
   * results in an uncommon substring.
   * To prove this, imagine u is an uncommon 
   * substring, that is a subsequence
   * of, say, string s1, which is not 
   * a subsequence of any string si, i!=1.
   * Suppose s1 is on the other hand a subsequence x
   * of some input string sj, j!=1.
   * But then also u, being a subsequence of s1 == x,
   * must be a subsequence of sj, hence a contradiction.
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

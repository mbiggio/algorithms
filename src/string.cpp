#include "string.hpp"
#include<algorithm>
#include<unordered_map>
#include<sstream>

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

/*********** look_and_say *************/
::std::string look_and_say(int n) {
  ::std::string current("1");
  for (int i=2; i<=n; ++i) {
    ::std::string next;
    for (int j=0; j<current.size();) {      
      char curchar=current[j];
      int count=0;
      while (j<current.size() && current[j]==curchar) {++j; ++count;};
      next.append(::std::to_string(count)).push_back(curchar);
    }
    current = ::std::move(next);
  }    
  return current;
}

/*********** roman_to_integer *************/
int roman_to_integer(const ::std::string &s) {
  static ::std::unordered_map<char,int> m
    = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
  int result = 0;
  for (int i=0; i<s.size(); ++i) {
    if (i<s.size()-1 && m[s[i]]<m[s[i+1]]) result-=m[s[i]];
    else result+=m[s[i]];
  }
  return result;
}

/*********** search *************/
int search(const ::std::string &t, const ::std::string &s) {
  static const long long kWidth = 256;
  if (s.size()>t.size()) return -1;
  long long hs=0, hw=0, power=1;
  for (int i=0; i<s.size(); ++i) {
    hs=kWidth*hs+s[i];
    hw=kWidth*hw+t[i];
    power*=kWidth;
  }
  if (hw==hs && !t.compare(0,s.size(),s)) return 0;
  for (int j=1; j<=t.size()-s.size(); ++j) {
    hw = kWidth*hw - power*t[j-1] + t[j+s.size()-1];
    if (hw==hs && !t.compare(j,s.size(),s)) return j;
  }
  return -1;
}

/*********** word_distance *************/
word_distance::word_distance(const ::std::string &text) : _text(text) {
  ::std::istringstream iss(text);
  for (int idx=0; iss; ++idx) {
    ::std::string w;
    iss >> w;
    _m[w].emplace_back(idx);
  }
}

int word_distance::distance(const ::std::string &w1, const ::std::string &w2) const {
  auto it1 = _m.find(w1), it2 = _m.find(w2);
  if (it1 == _m.end() || it2 == _m.end()) return -1;

  const auto &l1 = it1->second, &l2 = it2->second;
  int idx1 = 0, idx2 = 0;
  int min_dist = ::std::numeric_limits<int>::max();
  while (idx1 < l1.size() && idx2 < l2.size()) {
    min_dist = ::std::min(min_dist, ::std::abs(l1[idx1]-l2[idx2]));
    if (l1[idx1] < l2[idx2]) ++idx1;
    else ++idx2;
  }
  return min_dist;
}

} // string
} // algorithms

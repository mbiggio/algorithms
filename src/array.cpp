#include "array.hpp"
#include <algorithm>
#include <stack>
#include <random>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>

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

/*********** generate_primes *************/
::std::vector<int> generate_primes(int n) {
  ::std::vector<bool> isCandidate(n+1,true);
  isCandidate[0] = isCandidate[1] = false;
  ::std::vector<int> primes;
  primes.reserve(n/2);

  for (int i=2; i<=n; ++i) {
    if (isCandidate[i]) {
      int factor = 2;
      while (factor*i <= n) {
	isCandidate[factor*i] = false;
	++factor;
      }
      primes.push_back(i);
    }
  }
  return primes;

}

/*********** apply_permutation *************/
void apply_permutation(::std::vector<int> *pp, ::std::vector<int> *vp) {
  auto &v = *vp;
  auto &p = *pp;
  for (int i=0; i<v.size(); ++i) {
    if (p[i] >= 0) {
      int cur = v[i], j = i;
      while (p[j] >= 0) {
	::std::swap(cur,v[p[j]]);
	p[j] -= v.size();
	j = p[j] + v.size();
      }
    }
  }
  ::std::for_each(p.begin(),p.end(),[&v](int &i){i+=v.size();});
}

/*********** next_permutation *************/
void next_permutation(::std::vector<int> *vp) {
  auto &v = *vp;
  int i = v.size()-2;
  while (i>=0 && v[i]>v[i+1]) --i;
  if (i<0) return;
  auto it = ::std::find_if(v.rbegin(),v.rend(),
      [&](const int vv){return vv>v[i];});
  ::std::swap(*it,v[i]);
  ::std::reverse(v.begin()+i+1,v.end());
}

/*********** random_sampling *************/
::std::vector<int> random_sampling(::std::vector<int> *vp, int k) {
  auto &v = *vp;
  ::std::vector<int> result(k);
  ::std::default_random_engine en((::std::random_device())());
  for (int i=0; i<k; ++i) {
    ::std::swap(v[i],v[::std::uniform_int_distribution<int>{i,static_cast<int>(v.size()-1)}(en)]);
    result[i]=v[i];
  }
  return result;
}

/*********** online_random_sampler *************/
void online_random_sampler::read() {
  int el;
  *in >> el;
  ++n;
  if (set.size() < k) {
    set.push_back(el);
    return;
  }
  int idx = ::std::uniform_int_distribution<int>{0,n-1}(en);
  if (idx < k) set[idx]=el;
}

/*********** generate_permutation *************/
::std::vector<int> generate_permutation(int n) {
  ::std::vector<int> p(n);
  ::std::iota(p.begin(),p.end(),0);
  ::std::default_random_engine en(::std::random_device{}());
  for (int i=0; i<n-1; ++i) ::std::swap(p[i],p[::std::uniform_int_distribution<int>{i,n-1}(en)]);
  return p;
} 

/*********** increasing_triplet *************/
bool increasing_triplet(const ::std::vector<int> &v) {
  if (v.empty()) return false;

  /**
   * idea: maintain two quantities for each
   * subarray v[i..n-1], while decreasing i to 0:
   *  1 - the current maximum element index "m"
   *  2 - a pair "p" of indices such that 
   *      2.a   - i <= p.first < p.second <= n-1
   *      2.b   - v[p.first] < v[p.second]
   *      2.c   - among pairs of indices satisfying 2.a and 2.b,
   *              p is one with maximum p.first.
   */
  int m = v.size()-1;
  ::std::pair<int,int> p{-1,-1};
  for (int i=v.size()-2; i>=0; --i) {
    if (p.first<0 || v[i]>v[p.first]) {
      if (v[i]<v[m]) p={i,m};
      else m=i;      
    }
    else if (v[i]<v[p.first]) return true;
  }        
  return false;
}

/*********** find_123_pattern *************/
bool find_123_pattern(const ::std::vector<int> &v) {
  if (v.empty()) return false;

  /**
   * Idea for the algorithm: 
   * 1 - for each subarray v[i..n-1], keep a pair of indices (j_i, k_i) such that:
   *   1.a - i <= j_i < k_i < n
   *   1.b - v[ji] > v[ki]
   *   1.c - among the set of all couples (l,m) satisfying properties 1.a and 1.b,
   *         (j_i, k_i) is one with maximal v[k_i]
   *
   * 2 - maintain a stack s of indices such that:
   *   2.a - s contains all indices l such that i <= l < n and v[l] > v[k_i]
   *   2.b - the indices l in s are ordered in ascending order of l and v[l] from the top to the 
   *         bottom of the stack
   *
   * When examining a new element v[i-1], if v[i-1] > v[k_i], then we can always
   * find an index l in range i..n-1 such that couple (i-1,l) can be chosen as (j_{i-1}, k_{i-1});
   * it's sufficient to choose as k_{i-1} the biggest index l among {k_i} U s such that v[i-1] > v[l].
   * So start by putting (j_{i-1}, k_{i-1}) = (i,k_i), keep popping from s and set k_{i-1} to 
   * the popped index as long as v[i-1] > v[popped index].
   * After the pops, all indices in s will satisfy property 2.b.
   * To make propery 2.a true for the new stack, add i to the top of the stack.
   */

  ::std::stack<int> s;
  ::std::pair<int,int> p{-1,-1};
  for (int i=v.size()-1; i>=0; --i) {
    if (p.second<0 || v[i]>v[p.second]) {
      p = {i,p.second};
      while (!s.empty() && v[i] > v[s.top()]) {
	p.second = s.top();
	s.pop();
      }
      s.push(i);
    }
    else if (v[i]<v[p.second]) return true;
  }
  return false;
}

/*********** min_total_distance *************/
int min_total_distance(const ::std::vector<::std::vector<int>> &grid) {
  ::std::vector<int> x,y;
  for (int i=0; i<grid.size(); ++i) {
    for (int j=0; j<grid[0].size(); ++j) {
      if (grid[i][j]) {x.push_back(i); y.push_back(j);};
    }
  }
  ::std::nth_element(x.begin(), x.begin() + x.size()/2, x.end());
  ::std::nth_element(y.begin(), y.begin() + y.size()/2, y.end());
  int mx = x[x.size()/2], my = y[y.size()/2], d = 0;
  ::std::for_each(x.begin(),x.end(),[&](const int xx){d += abs(xx-mx);});
  ::std::for_each(y.begin(),y.end(),[&](const int yy){d += abs(yy-my);});
  return d;  
}

/*********** search_rotated *************/
int search_rotated(const ::std::vector<int> &v, int t) {

  /**
   * We do a pseudo binary search,
   * comparing target t with the middle element a[m]
   * and with the extreme elements a[s] and a[e].
   * We make sure the array has at least length 3
   * so that s < m < e.
   * As long as a[s] != a[m] or a[e] != a[m],
   * we can always recurse on one of the two halves,
   * otherwise we need to do a linear scan.
   * Here are all the possible cases:
   *
   *  * t = a[m] --> return true
   *  * a[s] = a[m] = a[e] --> full search;
   *  * a[s] < a[m]
   *    * t >= a[s] && t < a[m] --> e=m-1
   *    * t > a[m] || t < a[s] --> s=m+1  
   *  * a[s] > a[m]
   *    * t >= a[s] || t < a[m] --> e=m-1
   *    * t > a[m] && t < a[s] --> s=m+1
   *  * a[e] > a[m]
   *    * t > a[m] && t <= a[e] --> s=m+1
   *    * t < a[m] || t > a[e] --> e=m-1
   *  * a[e] < a[m]
   *    * t > a[m] || t <= a[e] --> s=m+1
   *    * t < a[m] && t > a[e] --> e=m-1  
   */
  int s=0, e=v.size()-1;
  while(e-s+1>=3) {
    int m=s+(e-s)/2;
    if (t==v[m]) return m;

    if (v[s]==v[m] && v[m]==v[e]) break; // linear search needed
    else if (v[s]<v[m]) {
      if (t>=v[s] && t<v[m]) e=m-1;
      else s=m+1;
    }
    else if(v[s]>v[m]) {
      if (t>=v[s] || t<v[m]) e=m-1;
      else s=m+1;
    }
    else if (v[e]>v[m]) {
      if (t>v[m] && t<=v[e]) s=m+1;
      else e=m-1;
    }
    else if(v[e]<v[m]) {
      if (t>v[m] || t<=v[e]) s=m+1;
      else e=m-1;
    }            
  }

  // if we ended up here, we need a linear search
  for (int i=s; i<=e; ++i) {
    if (v[i]==t) return i;
  }
  return -1;
}  

/*********** find_longest_subarray *************/
::std::pair<int,int> find_longest_subarray(const ::std::vector<char> &v) {
  ::std::unordered_map<int,int> m{{0,-1}};
  int sum = 0;
  ::std::pair<int,int> max_so_far{0,-1};
  for (int i=0; i<v.size(); ++i) {
    sum+=::std::isdigit(v[i])?1:-1;
    auto it = m.find(sum);
    if (it!=m.end() && i-it->second > max_so_far.second-max_so_far.first+1) {
      max_so_far={it->second+1,i};
    }
    else m[sum]=i;
  }
  return max_so_far;
}

/*********** circus_tower *************/
::std::vector<::std::pair<int,int>> circus_tower(::std::vector<::std::pair<int,int>> *vp) {
  auto &v = *vp;
  if (v.empty()) return {};

  /**
   * Idea: sort v by height first, and resolve ties by weight.
   * The sequence we are looking for must be a subsequence of 
   * the so-sorted sequence, and more precisely the maximum increasing subsequence.
   */
  ::std::sort(v.begin(), v.end(), [](const ::std::pair<int,int> &p1, const ::std::pair<int,int> &p2) {
      if (p1.first == p2.first && p1.second < p2.second) return true;
      if (p1.first < p2.first) return true;
      return false;
  });

  struct item {    
    int prev;
    int length;
  };

  ::std::vector<item> m(v.size(),{-1,1});
  int maxidx = 0;
  for (int i=0; i<v.size(); ++i) {
    for (int j=0; j<i; ++j) {
      if (v[j].second < v[i].second && m[i].length < m[j].length+1) {
	m[i]={j,m[j].length+1};	
      }
    }
    maxidx=m[i].length>m[maxidx].length?i:maxidx;
  }

 ::std::vector<::std::pair<int,int>> result(m[maxidx].length);
 for (int i=result.size()-1, j=maxidx; i>=0; --i, j=m[j].prev) result[i]=v[j];
 return result;
}

/*********** total_fruit *************/
int total_fruit(const ::std::vector<int> &v) {
  if (v.empty()) return 0;
  int tot=1, idx=0, ret=1;
  ::std::unordered_set<int> s{v[0]};
  for (int i=1; i<v.size(); ++i) {
    if (v[i]!=v[i-1]) {
      if (s.count(v[i])) ++tot;
      else if (s.size()==1) {s.insert(v[i]); ++tot;}
      else {s={v[i],v[i-1]}; tot=i-idx+1;}
      idx=i;
    }
    else ++tot;
    ret=::std::max(ret,tot);
  }
  return ret;  
}

/*********** majority_element *************/
int majority_element(const ::std::vector<int> &v) {

  /*
   * Let x be the majority element, 
   * and let i and j two indices in v such that v[i]!=v[j].
   * Then x is also the majority element of vector w, 
   * obtained from v by removing indices i and j.
   * The algorithm is keeps annihilating different 
   * elements as we see them, keeping the candidate
   * to be the majority element. 
   * It then verifies that it is indeed the majority element.
   * Example: [1,2,5,9,5,9,5,5,5]
   *
   *  | | | | | | | | |5|
   *  | | | | | | | |5|5|
   *  |1|_|5|_|5|_|5|5|5|
   *
   * Result = 5
   *
   */

  ::std::stack<::std::pair<int,int>> s;
  for (int i=0; i<v.size(); ++i) {
    if(s.empty()) s.emplace(v[i],1);
    else if(s.top().first==v[i]) ++s.top().second;
    else if(--s.top().second==0) s.pop();
  }

  if (s.empty()) return -1;
  int cand = s.top().first;
  int count = 0;
  ::std::for_each(v.begin(),v.end(),[&](int i){if(i==cand) ++count;});
  return count>v.size()/2?cand:-1;
}

/*********** majority_element_ii *************/
::std::vector<int> majority_element_ii(const ::std::vector<int> &v) {

  /*
   * There can be at most 2 elements
   * occurring more than n/3 times.
   * Removing 3 distinct elements from v
   * won't change these majority elements, if there
   * are some. So the approach is similar to 
   * majority_element.
   * Example: [1,2,1,2,2,1,5,2,1]
   *
   *   |   |   |   |   |  2|1 2|   |  2|1 2|
   *   |   |   |1  |1 2|1 2|1 2|1 2|1 2|1 2|
   *   |1,_|1,2|1,2|1,2|1,2|1,2|1,2|1,2|1,2|
   *
   * Result = {1,2}
   */

  ::std::unordered_map<int,int> m;
  for (int i=0; i<v.size(); ++i) {
    if (m.size()<=1 || m.count(v[i])) ++m[v[i]];
    else {
      for (auto it=m.begin(); it!=m.end();) {
	if(--it->second==0) it=m.erase(it);
	else ++it;
      }
    }
  }

  ::std::unordered_map<int,int> c;
  for (auto n:v) if (m.count(n)) ++c[n];
  ::std::vector<int> result;
  for (auto p:c) if (p.second>v.size()/3) result.emplace_back(p.first);
  return result;
}

} // array
} // algorithms

#include "math.hpp"
#include <algorithm>
#include <cmath>

namespace algorithms {
namespace math {

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

/*********** n_lockers *************/
int n_lockers(int n) {
  /**
   * The only slots being open/closed an odd number of times
   * are the ones that can be decomposed as a product of 
   * a factor by itself, that is, the perfect squares.
   * There are precisely floor(sqrt(n)) of them in the range 1..n
   */
  return ::std::floor(::std::sqrt(n));
}

/*********** add_without_plus *************/
int add_without_plus(int a, int b) {
  /**
   * The idea is that add(a,b) = add(a^b,(a&b)<<1),
   * where a^b represents the addition of a and b
   * without considering the carries,
   * and (a&b)<<1 represents the carries.
   */
  while(b) {
    int tmp = a;
    a ^= b;
    b = (tmp&b)<<1;
  }
  return a;
}

/*********** number_of_twos *************/
int number_of_twos(int n) {
  int count=0;
  //TODO
  return count;
}

} // math
} // algorithms

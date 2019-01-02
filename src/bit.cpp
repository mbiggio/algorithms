#include "bit.hpp"

namespace algorithms {
namespace bit {

/*********** count_smaller *************/
::std::vector<int> count_smaller(const ::std::vector<int>& nums) {
  auto snums=nums;
  sort(snums.begin(),snums.end());
  snums.erase(unique(snums.begin(),snums.end()),snums.end());
  bit<int> tree(snums);

  ::std::vector<int> result(nums.size());
  for (int i=nums.size()-1; i>=0; --i) {
    result[i]=tree.countSmaller(nums[i]);
    tree.update(nums[i]);
  }
  return result;
}

/*********** count_range_sums *************/
int count_range_sum(const ::std::vector<int>& nums, int lower, int upper) {
  ::std::vector<long long> sums(nums.size()+1);
  for (int i=1; i<sums.size(); ++i) sums[i]=sums[i-1]+nums[i-1];
  auto ssums = sums;
  sort(ssums.begin(),ssums.end());
  ssums.erase(unique(ssums.begin(),ssums.end()),ssums.end());        
  bit<long long> tree(ssums);                

  int count=0;
  for (auto s : sums) {
    count += tree.countSmallerOrEqual(s-lower)-tree.countSmaller(s-upper);
    tree.update(s);
  }
  return count;

}
  
} // bit
} // algorithms

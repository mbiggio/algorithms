#ifndef _DP_
#define _DP_
#include <vector>

namespace algorithms { 
namespace dp {

/**
 * Given an array a consisting of n integers
 * and an integer b. The integer b denotes 
 * that from any place (suppose the index is i) 
 * in the array A, you can jump to any one of 
 * the places in the array A indexed i+1, i+2, ..., i+B
 * if this place can be jumped to. 
 * Also, if you step on the index i, 
 * you have to pay a[i] coins. 
 * If a[i] is -1, it means you can’t jump 
 * to the place indexed i in the array.
 * Now, you start from the place indexed 0 in the array a,
 * and your aim is to reach the place indexed n-1 
 * using the minimum coins. 
 * You need to return the path of indexes 
 * (starting from 0 to n-1) in the array 
 * you should take to get to the place indexed n-1 
 * using minimum coins.
 * If there are multiple paths with the same cost, 
 * return the lexicographically smallest such path.
 * If it's not possible to reach the place indexed n-1 
 * then you need to return an empty array.
 * Runtime complexity : O(n*b) * 
 */
::std::vector<int> cheapest_jump(const ::std::vector<int>& a, const int b);

/**
 * There is a building of n floors.
 * If an egg drops from the mth floor of above, it will break.
 * If it's dropped from any floor below, it will not break.
 * You're given two eggs.
 * Find m while minimizing the number of drops for the worst case.
 * Runtime complexity : O(n2)
 */
int egg_drop(int n);

} // namespace dp
} // namespace algorithms
#endif

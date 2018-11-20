#ifndef _ALGOMATH_
#define _ALGOMATH_
#include <vector>

namespace algorithms {
namespace math {

/**
 * A group of two or more people wants to meet 
 * and minimize the total travel distance. 
 * You are given a 2D grid of values 0 or 1, 
 * where each 1 marks the home of someone in the group. 
 * The distance is calculated using Manhattan Distance, 
 * where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
 * Runtime complexity : O(n)
 */
int min_total_distance(const ::std::vector<::std::vector<int>> &grid);

/**
 * There are n lockers in a hallway. 
 * A man begins by opening all 100 lockers.
 * Next, he closes every second locker.
 * Then, on his third pass, he toggles every third locker
 * (closes it if it is open or opens it if it is closed).
 * This process continues for n passes, such that on each pass i,
 * the man toggles every ith locker.
 * Aften his nth pass in the hallway, in which he toggles
 * only locker number n, how many lockers are open?
 * Runtime complexity : O(sqrt(n))
 */
int n_lockers(int n);

/**
 * Write a function that adds two numbers.
 * You should not use + or any other arithmetic operator.
 */
int add_without_plus(int a, int b);

} // math
} // algorithms
#endif

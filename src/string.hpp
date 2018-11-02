#ifndef __STRING__
#define __STRING__
#include <string>

namespace algorithms {
namespace string {

/**
 * Given a string s of n characters, 
 * count how many palindromic there are substrings in this string.
 * A substring has to be a contiguous subset of s.
 * The substrings with different start indexes or end indexes
 * are counted as different substrings even if 
 * they consist of same characters.
 * Runtime complexity : O(n2) - expansion around center
 *                      O(n)  - Manacher's algorithm
 */

int count_substrings(const ::std::string &s);

} // string
} // algorithms

#endif

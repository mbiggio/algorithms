#ifndef __STRING__
#define __STRING__
#include <string>
#include <vector>

namespace algorithms {
namespace string {

/**
 * Given a string s of n characters, 
 * count how many palindromic substrings there are in this string.
 * A substring has to be a contiguous subset of s.
 * The substrings with different start indexes or end indexes
 * are counted as different substrings even if 
 * they consist of same characters.
 * Runtime complexity : O(n2) - expansion around center
 *                      O(n)  - Manacher's algorithm - TODO
 */

int count_substrings(const ::std::string &s);

/**
 * Given a list of n strings, each of maximum length x,
 * find the length of the longest uncommon subsequence 
 * among them, if it exists.
 * The longest uncommon subsequence is defined as 
 * the longest subsequence of one of these strings 
 * that is not a subsequence of the other strings.
 * A subsequence is a sequence that can be derived 
 * from one sequence by deleting some characters 
 * without changing the order of the remaining elements. 
 * Runtime complexity : O(x*n2)
 */
int find_lus_length(const ::std::vector<::std::string> &s);

} // string
} // algorithms

#endif

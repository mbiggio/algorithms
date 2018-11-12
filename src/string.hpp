#ifndef _STRING_
#define _STRING_
#include <string>
#include <vector>

namespace algorithms {
namespace string {

/**
 * Check if a string s of n characters
 * is a palyndrome or not.
 * Runtime complexity : O(n)
 */
bool is_palyndrome(const ::std::string &s);

/**
 * Convert a string s of n characters
 * representing an integer fitting in a int 
 * to its numeric value.
 * Runtime complexity : O(n)
 */
int string_to_int(const ::std::string &s);

/**
 * Convert an integer k of n digit
 * to its decimal representation as a string.
 * Runtime complexity : O(n)
 */
::std::string int_to_string(const int k);

/**
 * Reverse the order of the words
 * in a string s of n characters.
 * Runtime complexity : O(n)
 */
void reverse_words(::std::string *sp);

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

/**
 * The look-and-say sequence starts with 1.
 * Subsequent numbers are derived by describing the 
 * previous number in terms of consecutive digits.
 * Specifically, to generate an entry of the sequence 
 * from the previous entry, read off the digits of the
 * previous entry, counting the number of digits
 * in groups of the same digit.
 * For example: 
 * 1; one 1; two 1s; one 2 and then one 1; ...
 * Write a program that takes as input an integer n
 * and returns the nth integer in the look-and-say sequence.
 */
::std::string look_and_say(int n);

} // string
} // algorithms

#endif

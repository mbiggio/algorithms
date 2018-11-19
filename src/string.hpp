#ifndef _STRING_
#define _STRING_
#include <string>
#include <vector>
#include <unordered_map>

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
 * and returns the nth integer in the look-and-say sequence.a
 * Runtime complexity : O(n2^n)
 */
::std::string look_and_say(int n);

/**
 * The Roman numeral representation of positive integers
 * uses the symbols {I=1,V=5,X=10,L=50,C=100,D=500,M=1000}.
 * We define a string over the Roman number symbols to be valid
 * if symbols appear in non-decreasing order,
 * with the following exceptions allowed:
 *   * I can immediately precede V and X 
 *   * X can immediately precede L and C
 *   * C can immediately precede D and M
 * Back-to-back exceptions are not allowed, e.g. IXC and CDM are not valid.
 * A valid Roman number string represents the integer
 * which is the sum of the symbols that do not correspond
 * to the exceptions. For the exceptions, 
 * add the difference of the larger symbol and the smaller symbol.
 * Take as input a valid Roman number string s 
 * and return the integer it corresponds to.
 */
int roman_to_integer(const ::std::string &s);

/**
 * Given two strings s (the "search string", length m)
 * and t (the "text string", length n),
 * find the first occurrence of s in t.
 * Runtime complexity : O(m+n) expected - Rabin-Karp algorithm
 */
int search(const ::std::string &t, const ::std::string &s);

/**
 * You have a large text file containing n words.
 * Given any two words, find the shortest distance 
 * (in terms of number of words) between them in the file.
 * If the operation will be repeated many times for the same 
 * file (but different pairs of words), can you optimize your
 * solution?
 * Runtime complexity : O(n*w) - constructor
 *                      O(n1 + n2) - distance
 */
class word_distance {
public:
  word_distance(const ::std::string &text);
  int distance(const ::std::string &w1, const ::std::string &w2) const;

private:
  const std::string &_text;
  ::std::unordered_map<::std::string, ::std::vector<int>> _m;
};

} // string
} // algorithms

#endif

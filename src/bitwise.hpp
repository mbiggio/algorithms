#ifndef __BITWISE__
#define __BITWISE__

namespace algorithms { 
namespace bitwise {

/**
 * Count the bits set to 1 in the n-bit number x.
 * Runtime complexity : O(k), where k is the number 
 * of bits set to 1.
 */
short count_bits(unsigned x);

/**
 * Compute the parity of the n-bit number x.
 * Runtime complexity : O(logn).
 */
short parity(unsigned x);

/**
 * Swap the ith and jth bits of the n-bit number x.
 * Runtime complexity : O(1). 
 */
unsigned swap_bits(unsigned x, int i, int j);

/**
 * Reverse the bits of the n-bit number x.
 * Runtime complexity : O(n).
 */
unsigned reverse_bits(unsigned x);

/**
 * Find the closest integer with the same parity
 * as the n-bit number x.
 * Runtime complexity : O(n)
 */
unsigned closest(unsigned x);

/**
 * Multiply two n-bit numbers a and b.
 * Runtime complexity : O(n2)
 */
unsigned multiply(unsigned a, unsigned b);

/**
 * Divide two n-bit numbers a and b.
 * Runtime complexity : O(n2).
 */
unsigned divide(unsigned a, unsigned b);

/**
 * Reverse the decimal digits of n-bit number x.
 * Runtime complexity : O(n).
 */
unsigned reverse_digits(unsigned x);

/**
 * Compute the m-th power of double x.
 * Runtime complexity : O(logm).
 */
double power(double x, int m);

/**
 * Check if a decimal integer is a palyndrome.
 * Runtime complexity : O(n).
 */
bool is_palyndrome(unsigned x);


} // bitwise
} // algorithms

#endif

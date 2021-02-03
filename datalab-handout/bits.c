/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include <stdio.h>
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int one_if_both_one  = x & y;
  int zero_if_both_one = ~one_if_both_one;
  int one_if_contain_one = ~( (~x) & (~y));

  return one_if_contain_one & zero_if_both_one;
  
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
  //return 2;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // x1 = 0x0111...111 x2 = 0x1111...111
  // x1 + 1 =  
  int reversed  = !!(~x);

  // 2x+2 = 0 for both 0x0111...111 and 0x1111...111
  int res = !(x + x + 1 + reversed);
  return res;
  //int lshift = plus1 << 1;
  //return plus1 ^ lshift;
}


/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // 170 = 128 + 32 + 8 + 2
  //  10101010 8bits
  int odd_bits_1 = 170;
  int shift1 = (odd_bits_1 << 8) + odd_bits_1;
  int shitf2 =  (shift1 << 8) + odd_bits_1;
  int shift3 = (shitf2 << 8) + odd_bits_1;
  int res = !(shift3 ^ x);
  return res;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  int res = ~x + 1;
  return res;//res;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */

 // 48 = 32 + 16 = 110000
 // 57 = 32 + 16 + 8 + 1 = 111001
int isAsciiDigit(int x) {
  int diffsum = (x << 1) + (~105 + 1);
  //x + x - 48 - 57;
  return !(x >> 6 | (~diffsum + 10) >> 31 | (diffsum + 9) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //printf("x, y, z: %d, %d, %d\n", x, y, z);
  x = ~(!!(x)) + 1;
  // printf("x:%d\n", x);
  y = x & y;
  // printf("y:%d\n",y);
  z = (~x) & z;
  // printf("z:%d\n", z);
  // printf("y|z: %d\n", y | z);
  return y | z; 
  //return 2;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int xsign = (x >> 31) & 1;
  int ysign = (y >> 31) & 1;
  int x_negative_y_positive = xsign & (~ysign);

  // same sign
  int diff = x + ~y + 1;
  int diffsign = (diff >> 31) & 1;
  int samesign = !(xsign ^ ysign);
  int x_less_equal_y = samesign & (diffsign | ~(!!diff));

  return (x_negative_y_positive | x_less_equal_y);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int smeard = x;
  smeard = smeard |  smeard >> 16;
  smeard = smeard | smeard >> 8; 
  smeard = smeard | smeard >> 4;
  smeard = smeard | smeard >> 2;
  smeard = smeard | smeard >> 1;
  return (~smeard & 1);
  //return 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int y, result, mask1, mask2, mask4, mask8, mask16;
  int bitnum;
  result = 1;

  mask1 = 0x2;
  mask2 = 0xC;
  mask4 = 0xF0;
  mask8 = 0xFF << 8; //number can't be larger than 255
  mask16 = (mask8 | 0xFF) << 16;

  y = x ^ (x >> 31); // turn negative number to positve with the same result.
  bitnum = !!(y & mask16) << 4; //16 or 0
  result += bitnum;
  y = y >> bitnum;

  bitnum = !!( y & mask8) << 3; // 8 or 0
  result += bitnum;
  y =y >>bitnum;

  bitnum = !!(y & mask4) << 2; // 4 or 0
  result += bitnum;
  y =y >> bitnum;

  bitnum = !!( y & mask2) << 1; // 2 or 0
  result += bitnum;
  y = y >> bitnum;

  bitnum = !!(y & mask1); // 1 or 0
  result += bitnum;
  y = y >> bitnum;
  // printf("mask1 bit num %d\n", bitnum);

  // printf("result is %d\n", result);
  // printf("%d\n", result +(y & 1));
  
  // why (y & 1), because we have highest bit remaining to count.
  return result + (y & 1);
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 3 situations.
  // 1. normalized. if (E + 1) > 0xFF, then f * 2 will overflow return inifite. else (E+ 1)
  // 2. denormalized. if zero return uf. else M << 1, if M exceeds, rounding.
  // 3. infinite or NaN return uf
  unsigned signbit = (uf >> 31) & 1;
  unsigned exp_mask = 0xFF; // 1111 1111
  unsigned exp_bits = (uf >> 23) & exp_mask;
  unsigned M_bits = (uf << 9) >> 9;
  
  unsigned expAllZero = !exp_bits;
  unsigned expAllOne = !(exp_bits ^ exp_mask);
  unsigned MbitsAllZero = ! M_bits;

  unsigned signBitMask = 0x80000000;
  unsigned signExpBitsMask = 0xFF800000;
  unsigned oneExp = 0x00800000;

  if(expAllOne) {
    return uf;
  } else if(expAllZero) {
    if(MbitsAllZero) {

    } else {
      unsigned onlySignedBit = signBitMask & uf;
      uf = onlySignedBit | (uf << 1);
    }

  } else {
    // normalized floating point number 
    if( !((exp_bits + 1) ^ exp_mask)) {
      uf = uf + oneExp;
      uf = uf & signExpBitsMask;
    } else {
      uf = uf + oneExp;
    }
  }
  return uf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  if(!(uf << 1)) return 0;
  unsigned exp_mask = 0x7F800000;
  unsigned exp_bits = uf & exp_mask;
  unsigned mbits = (uf << 9) >> 9;

  unsigned out_of_range = 0x80000000u;

  // denormalized
  if(!exp_bits) return 0;
  // NaN or infinite
  if( !(exp_bits ^ exp_mask) ) return out_of_range;

  //normalized
  unsigned exp = exp_bits >> 23;
  int bias = 0x7F;
  int E = exp - bias;
  if(E < 0) return 0; //0.xxxxx -> (int)0
  if(E > 30) return out_of_range; // larger than INT_MAX

  unsigned sign_bit_mask = 0x80000000;
  unsigned sign_bit = uf & sign_bit_mask;

  unsigned hidden_one_bit = 0x00800000;
  int M = mbits | hidden_one_bit;
  if(E > 23) {
    M = M << (E - 23);
  } else if(E < 23) {
    M = M >> (23 - E);
  }

  int res = M;
  if(sign_bit) res = -res;
  return res;
  //return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    
    return 2;
}

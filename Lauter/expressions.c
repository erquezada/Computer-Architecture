
/* FIRST NAME OF STUDENT: Eric
 LAST NAME OF STUDENT: Quezada
 UTEP STUDENT ID: 80532860

*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#define BUFFER_SIZE (4096)

/* Before you start working, do the following:

 + Understand what a signed integer and an unsigned integer are.

 + Understand that integers have a certain size and that they can
 overflow.

 + Understand what is meant by the types int32_t, int64_t, uint32_t
 and uint64_t

 + Understand what a structure, defined using the struct keyword, is
 and how pointers to structures work.

 + Understand what a typedef does.

 + Understand that pointers are often used to avoid copying data
 around, in particular when the data sit in structures.

 + Try to approximately understand what the const keyword does.

*/

/* YOU MUST ****NOT****

 + Modify the types or signatures of functions.

 + Use any other functions than the ones indicated in each
 specification comment.

 + Use dynamic memory allocation or statically sized arrays. (There
 are some functions using some memory usage tricks but they are
 marked "NOTHING TO BE MODIFIED")

 YOU MUST

 + Thoroughly test your code.

 CODE THAT DOES NOT EVEN COMPILE WILL NOT BE LOOKED AT. IT WILL
 IMMEDIATELY RECEIVE A GRADE OF 0 (ZERO) POINTS OUT OF 100.

*/

/* A structure typedef to talk about rational numbers
 with a signed numerator and an unsigned denominator
*/
typedef struct {
  int32_t num;   // numerator
  uint32_t den;  // denominator
} ratio_t;       // ratio structure

/* A function to get the user to input a string, with a maximum length
 of the string buffer of n bytes.

 Uses no other function besides scanf().

 NOTHING IS TO BE MODIFIED HERE.

*/
void input_string(char *str, size_t n) {
  char c;
  size_t i;

  if (n < ((size_t)1)) return;                     // base case
  for (i = (size_t)0; i < n - ((size_t)1); i++) {  // else iterate through input
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  }
  str[i] = '\0';
}

/* A function to compute the greatest common divisor of two uint32_t

 Uses the modular division variant of Euclid's algorithm.

 Uses no other function.

*/
uint32_t gcd(uint32_t m, uint32_t n) {
  if (n == 0)
    return m;  // no division allowed here
  else {
    return (uint32_t)gcd(n, m % n);  // compute greatest common divisor
  }
}
/* A function to return the absolute value of an int32_t as
 a uint32_t.

 NOTHING TO BE MODIFIED HERE.

*/
uint32_t abs(int32_t a) {
  if (a >= ((int32_t)0)) return (uint32_t)a;
  return ((uint32_t)(-(a + ((int32_t)1)))) + ((uint32_t)1);
}

/* A function to check if a int64_t a fits on an int32_t
 Returns a boolean. The boolean is "true" iff a fits on an int32_t
 variable.

 NOTHING TO BE MODIFIED HERE.

*/
int fits_int32(int64_t a) {
  int32_t t;
  int64_t tt;

  t = (int32_t)a;
  tt = (int64_t)t;
  return (a == tt);
}

/* A function to check if a uint64_t a fits on a uint32_t.

 Returns a boolean. The boolean is "true" iff
 a fits on a uint32_t variable.

 NOTHING TO BE MODIFIED HERE.

*/
int fits_uint32(uint64_t a) {
  uint32_t t;
  uint64_t tt;

  t = (uint32_t)a;
  tt = (uint64_t)t;
  return (a == tt);
}

/* A function to create a reduced fraction res out of an int32_t
 a and a uint32_t b.

 The fraction that is created and written into res satisfies

 res.num / res.den = a / b

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when b is zero.

 Uses the functions abs() and gcd().

 CAUTION: The fraction must be REDUCED. The gcd() function works
 on unsigned variables, hence the sign of a must be stripped using
 abs().

*/
int create_fraction_unsigned_denominator(ratio_t *res, int32_t a, uint32_t b) {
  // res.num / res.den = a / b
  if (b == 0) return 0;  // Fail when b is zero

  uint32_t abs_a = abs(a);            // abs(a) for numerator
  uint32_t gcdValue = gcd(abs_a, b);  // gcd(a) for denominator

  res->num = a / gcdValue;
  res->den = b / gcdValue;
  return 1;
}

/* A function to create a reduced fraction res out of an int32_t
 a and an int32_t b.

 The fraction that is created and written into res satisfies

 res.num / res.den = a / b

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function uses the create_fraction_unsigned_denominator()
 function, the abs() function and the fits_int32() to do its
 job.

 The function fails when:

 + b is zero
 + b is negative and -a does not fit on an int32_t.

*/
int create_fraction(ratio_t *res, int32_t a, int32_t b) {
  if (b == 0) return 0;  // check if zero

  // check if b is negative
  if (b < 0) {
    // check if -a fits on an int32_t
    if (!fits_int32(-a)) return 0;  // failed. Overflow

    a = -a;
    b = -b;
  }
  return create_fraction_unsigned_denominator(res, a, (uint32_t)b);
}

/* Negates a rational number a

 The value written to res will satisfy

 res.num / res.den = - a.num / a.den

 Uses the functions:

 + fits_int32()
 + create_fraction_unsigned_denominator()

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when

 + -a.num does not fit on a signed integer
 + create_fraction_unsigned_denominator() fails.

*/
int ratio_neg(ratio_t *res, const ratio_t *a) {
  if (!fits_int32(-(a->num))) {  // if overflow
    return 0;
  }

  if (!create_fraction_unsigned_denominator(
          res, -(a->num), a->den)) {  // if fraction fails to create fraction
    return 0;
  }

  return 1;
}

/* Computes the reciprocal of a rational number a

 The value written to res will satisfy

 res.num / res.den = a.den / a.num

 Uses the functions:

 + fits_int32()
 + fits_uint32()
 + create_fraction_unsigned_denominator()

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when

 + a.den does not fit on a signed integer
 + a.num does not fit on an unsigned integer
 + create_fraction_unsigned_denominator() fails.

*/
int ratio_rcp(ratio_t *res, const ratio_t *a) {
  if (a->num == 0) return 0;  // check if undefined

  if (!fits_int32(a->den)) return 0;  // check if fits on a signed integer

  if (!fits_uint32(a->num)) return 0;  // check if fits on a unsigned integer

  if (!create_fraction_unsigned_denominator(res, a->den, (uint32_t)a->num))
    return 0;  // Helper function for fractions

  return 1;  // success
}

/* Add a rational number a to a rational number b

 The value written to res will satisfy

 res.num / res.den = a.num / a.den + b.num / b.den

 Uses the functions:

 + fits_int32()
 + fits_uint32()
 + create_fraction_unsigned_denominator()

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when the sum fraction cannot be written
 as a rational number with a signed int numerator and a non-zero
 uint32_t denominator.

*/
int ratio_add(ratio_t *res, const ratio_t *a, const ratio_t *b) {
  uint64_t denom = (uint64_t)a->den * (uint64_t)b->den;
  int64_t anum = (int64_t)a->num * (uint64_t)b->den;
  int64_t bnum = (int64_t)b->num * (int64_t)a->den;

  int64_t numSum = anum + bnum;

  if (!fits_int32(numSum)) return 0;

  if (!fits_uint32(denom)) return 0;

  if (!create_fraction_unsigned_denominator(res, (int32_t)numSum,
                                            (uint32_t)denom))
    return 0;

  return 1;
}

/* Subtract a rational number b from a rational number a

 The value written to res will satisfy

 res.num / res.den = a.num / a.den - b.num / b.den

 Uses the functions:

 + ratio_neg()
 + ratio_add()

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when the difference fraction cannot be written
 as a rational number with a signed int numerator and a non-zero
 uint32_t denominator.

*/
int ratio_sub(ratio_t *res, const ratio_t *a, const ratio_t *b) {
  ratio_t neg_b;

  if (!ratio_neg(&neg_b, b)) return 0;

  if (!ratio_add(res, a, &neg_b)) return 0;

  return 1;
}

/* Multiply a rational number a by a rational number b

 The value written to res will satisfy

 res.num / res.den = a.num / a.den * b.num / b.den

 Uses the functions:

 + fits_int32()
 + fits_uint32()
 + create_fraction_unsigned_denominator()

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when the sum fraction cannot be written
 as a rational number with a signed int numerator and a non-zero
 uint32_t denominator.

*/
int ratio_mul(ratio_t *res, const ratio_t *a, const ratio_t *b) {
  int64_t numerator = (int64_t)(a->num) * (int64_t)(b->num);
  uint64_t denominator = (uint64_t)(a->den) * (uint64_t)(b->den);

  if (!fits_int32(numerator) || !fits_uint32(denominator)) return 0;

  // This should return 1 for success, not 0.
  if (!create_fraction_unsigned_denominator(res, (int32_t)numerator,
                                            (uint32_t)denominator))
    return 0;

  return 1;
}

/* Divide a rational number a by a rational number b

 The value written to res will satisfy

 res.num / res.den = a.num / a.den / b.num / b.den

 Uses the functions:

 + ratio_rcp()
 + ratio_mul()

 In the case the function works, it returns the boolean value
 "true".

 In the case the function fails, it does not touch the pointer res
 and returns "false".

 The function fails when the quotient fraction cannot be written
 as a rational number with a signed int numerator and a non-zero
 uint32_t denominator.

*/
int ratio_div(ratio_t *res, const ratio_t *a, const ratio_t *b) {
  ratio_t rcb_b;

  if (!ratio_rcp(&rcb_b, b)) return 0;

  if (!ratio_mul(res, a, &rcb_b)) return 0;

  return 1;
}

/* Returns a double precision floating-point approximation to a
 rational number a
*/
double ratio_approx(const ratio_t *a) {
  if (a->den == 0) {
    return (a->num >= 0) ? 1e308 : -1e308;
  }
  return (double)a->num / (double)a->den;
}

/* Converts the decimal integer number given by str to a uint32_t.

 Writes the result to the variable pointed to by res.

 Returns a boolean indicating success or failure.

 If the function fails, returning "false", it does not touch the
 variable pointed to by res.

 The function fails when:
 + The string is empty
 + The string contains characters other than the digit 0 through 9
 + The result would not fit on a uint32_t.

 The function needs to check at each multiply-and-add step if the
 result would overflow a uint32_t.

 The function uses fits_uint32() and no other function.

*/
int convert_string_to_uint32(uint32_t *res, const char *str) {
  if (str == NULL || *str == '\0') {
    return 0;  // Fail: String is empty
  }

  uint32_t result = 0;

  while (*str) {
    if (*str < '0' || *str > '9') {
      return 0;  // Fail: Invalid character
    }

    uint32_t digit = *str - '0';

    // Check for overflow before multiplying and adding
    if (result > (UINT32_MAX / 10) ||
        (result == (UINT32_MAX / 10) && digit > (UINT32_MAX % 10))) {
      return 0;  // Fail: Overflow detected
    }

    result = result * 10 + digit;
    str++;
  }
  *res = result;
  return 1;  // Success
}

/* Converts the substring of the string str, delimited by l and r, to
 a uint32_t.

 The function "extracts" the substring with characters with indices
 i such that l <= i < r from str and uses the
 convert_string_to_uint32() function defined above to convert it
 to a uint32_t.

 Uses convert_string_to_uint32().

 The function returns a boolean indicating success or failure.

 The function fails when:
 + The substring would be empty because r <= l
 + The function convert_string_to_uint32() fails.

 The function may assume that all indices i satisfying l <= i < r
 are valid indices into the array of characters formed by str.

 NOTHING IS TO BE MODIFIED HERE.

*/
int convert_substring_to_uint32(uint32_t *res, const char *str, int l, int r) {
  if (r <= l) return 0;
  char substr[((size_t)(r - l)) + ((size_t)1)];
  int i;
  size_t k;
  for (i = l, k = (size_t)0; i < r; i++, k++) {
    substr[k] = str[i];
  }
  substr[k] = '\0';
  return convert_string_to_uint32(res, substr);
}

/* Returns the length of the string str as a signed int.

 May assume that the string is short enough that its length holds on
 a signed int.

*/
int string_length(const char *str) {
  int length = 0;

  while (str[length] != '\0') {
    length++;
  }
  return length;
}

/* Removes all occurrences of the character c in the string str.

 The function modifies str in place.

 Does not call any (other) functions.

 The function must have complexity O(n) where n is the length of the
 string.

 A modified (shorter) string must be terminated by a NUL character
 '\0'.

*/
void remove_character(char *str, char c) {
  size_t i = 0, j = 0;

  // Iterate through each character in the string
  while (str[i] != '\0') {
    // If the current character is not 'c', we keep it in the string
    if (str[i] != c) {
      str[j++] = str[i];
    }
    // Move to the next character in the input string
    i++;
  }

  // Terminate the modified string with a null character
  str[j] = '\0';
}

/* Finds the index of the character in the substring of str delimited
 by l and r that corresponds to the closing parenthesis that matches
 the opening parenthesis at index l.

 The function considers only the substring formed by the characters
 of str whose indices i satisfy l <= i < r.

 In case of failure, the function returns a negative value,
 typically -1.

 The function may assume that all indices i satisfying l <= i < r
 are valid indices into the array of characters formed by str.

 The function fails when:
 + The substring would be empty, i.e. if r <= l
 + The substring does not start with an open parenthesis, i.e. if
 str[l] is not equal to '('
 + No matching close parenthesis is found for any index i
 satisfying l <= i < r.

 CAUTION:

 The function does NOT return the index of the first occurrence
 of a ')' character after index l. It returns the index
 of the first occurrence of a close parenthesis that matches
 the opening parenthesis at index l.

 Example: Let str be "(2+3*(4+5))/(3+3)", l = 0 and r = 17. The
 function returns 10 because at index 10, the *matching* close
 parenthesis can be found for the open parenthesis at index 0:

 (2+3*(4+5))/(3+3)
 ^ ^
 0 10

 The first close parenthesis would be at 9, but it does not
 match the one opening at index 0 but the one opening at index 5:

 (2+3*(4+5))/(3+3)
 ^ ^
 5 9

 The function does not use any (other) function.

*/
int find_first_matching_close_parenthesis(const char *str, int l, int r) {
  // Failure if r <= l or the substring does not start with an opening
  // parenthesis
  if (r <= l || str[l] != '(') {
    return -1;
  }

  int open_parens = 1;  // Starts with 1 because str[l] is '('

  for (int i = l + 1; i < r; ++i) {
    if (str[i] == '(') {
      open_parens++;  // Another opening parenthesis
    } else if (str[i] == ')') {
      open_parens--;  // Closing parenthesis

      // If we have balanced the opening parenthesis at index l
      if (open_parens == 0) {
        return i;
      }
    }
  }

  // If no matching close parenthesis is found
  return -1;
}

/* Finds the index of the character c in the substring of str delimited
 by l and r that corresponds to an infix operator in that substring,
 disregarding all infix operators in parentheses opened (and closed)
 in the substring.

 The function considers only the substring formed by the characters
 of str whose indices i satisfy l <= i < r.

 In case of failure, the function returns a negative value,
 typically -1.

 The function may assume that all indices i satisfying l <= i < r
 are valid indices into the array of characters formed by str.

 The function fails when:
 + The substring would be empty, i.e. if r <= l
 + The infix operator given by c is not found for any index i
 satisfying l <= i < r.

 Example: Let str be "(2+3*(4/5))/(3+3)", c = '/', l = 0 and r = 17.
 The function returns 11 because at index 11 the character c can be
 found and that occurrence is not within parentheses:

 (2+3*(4/5))/(3+3)
 ^
 11

 CAUTION: this is not the first occurrence of the character c. The
 first occurrence would be at index 7, but that use is protected by
 parentheses:

 (2+3*(4/5))/(3+3)
 ^ ^ ^ ^^
 7

 The function does not use any other function.

*/
int find_particular_infix_operator(char c, const char *str, int l, int r) {
  if (r <= l) {
    return -1;  // Substring is empty
  }

  int parentheses = 0;  // Counter for parentheses depth

  for (int i = l; i < r; i++) {
    if (str[i] == '(') {
      parentheses++;  // Entering a new parenthesis level
    } else if (str[i] == ')') {
      parentheses--;  // Exiting a parenthesis level
    } else if (str[i] == c && parentheses == 0) {
      return i;  // Found the character outside of parentheses
    }
  }

  return -1;  // Character not found outside of parentheses
}

/* Uses the find_particular_infix_operator() to find the
 first occurrence of the first infix operator in the
 list '+', '-', '*' and '/'.

 The function loops over the characters in the string formed by the
 for characters '+', '-', '*' and '/' (in this order), calling
 find_particular_infix_operator() for each character. As soon as
 find_particular_infix_operator() returns a value m satisfying
 m >= l, the function returns that value m.

 In the case when none of the calls to
 find_particular_infix_operator() yields a value m satisfying m >=
 l, the function returns a negative value, typically -1.

*/

int find_infix_operator(const char *str, int l, int r) {
  // List of operators to check, in the given order
  const char operators[] = {'+', '-', '*', '/'};
  int result;

  // Loop through each operator and check
  for (int i = 0; i < 4; i++) {
    result = find_particular_infix_operator(operators[i], str, l, r);

    // If a valid index is found, return it
    if (result >= l) {
      return result;
    }
  }

  // If no operator is found, return -1
  return -1;
}

/* Evaluates the arithmetical expression in the substring of str
 formed by the characters whose indices i satisfy l <= i < r
 to a rational number, putting the result into the variable
 pointed to by res and returning a boolean.

 The returned boolean indicates success (with "true") or failure
 (with "false").

 The function is recursive and calls itself on the same string str
 but with smaller ranges of indices i satisfying l <= i < r, hence
 considering shorter and shorter substrings.

 The function may fail for various reasons:
 + The substring would be empty, i.e. r <= l.
 + The substring starts with an open parenthesis but no
 matching close parenthesis can be found.
 + The substring does not start with an open parenthesis but no
 infix operator is found and the expression in the substring is not
 just a leaf node containing a decimal number.
 + A recursive call fails.

 The function proceeds as follows:

 (i) It starts by testing if r <= l. This is one of the recursion
 base cases.

 (ii) It checks if the substring starts with an open parenthesis.
 If it does, the function does the following:
 (a) It tries to find the matching close parenthesis
 (b) If none is found it fails
 (c) If the matching close parenthesis is found on the
 last character in the substring (i.e. if that close
 parenthesis has index r-1), the function calls itself
 on the substring with indices i between l+1 and r-1.
 It returns what that recursive call returns.
 (d) Otherwise, an infix operator must be present at the
 character following the close parenthesis. The function
 hence calls itself twice on the substring before that
 infix operator and on the substring after that infix
 operator, failing if one of the recursive calls fails,
 and keeping the rational numbers for the left and right
 subexpressions in two variables. It then applies the
 infix operator at the character following the close
 parenthesis, failing if that character is not an infix
 operator out of '+', '-', '*' and '/'. The function uses
 the ratio_add(), ratio_sub(), ratio_mul() and ratio_div()
 functions for this step. The function fails if
 one of the calls to ratio_add()... fails.
 (iii) If the substring does not start with an open parenthesis,
 the function uses the find_infix_operator() function to
 find the first infix operator in the expression formed by the
 substring.
 (a) If an infix operator is found at the first
 position in the substring (i.e. at index l) and at that
 position a '-' character is found, the function calls
 itself recursively on the substring starting after that
 '-', delimited on the right by the same r. It takes that
 result and negates it using ratio_neg(). It fails if the
 recursive call or the call to ratio_neg() fails.
 (b) If an infix operator is found but it is not at the
 first position in the substring, the function calls
 itself twice, to the left and to the right of the infix
 operator. It then performs an evaluation similar to
 the one described in case (ii) (d) above.

 (iv) If no starting parenthesis nor infix operator is found, the
 function tries to convert the substring to a uint32_t, using
 convert_substring_to_uint32(). If that function fails, it
 fails. It then checks if that uint32_t also fits a signed
 int, using fits_int32(). If it does not fit, the function
 fails. Otherwise the function converts the signed int to a
 fraction, using create_fraction_unsigned_denominator() with a
 denominator argument of 1. If that function fails, the
 function fails.

 The function __evaluate_expression_aux() calls the following
 functions:

 + itself
 + find_first_matching_close_parenthesis()
 + ratio_add()
 + ratio_sub()
 + ratio_mul()
 + ratio_div()
 + find_infix_operator()
 + ratio_neg()
 + convert_substring_to_uint32()
 + fits_int32()
 + create_fraction_unsigned_denominator()

 The function __evaluate_expression_aux() must not call any other
 functions.

 The function __evaluate_expression_aux() must not allocate any
 dynamic memory and must not use statically sized arrays of any
 kind.

*/
static int __evaluate_expression_aux(ratio_t *res, const char *str, int l,
                                     int r) {
  // Step (i): Base case, check if the substring is empty
  if (r <= l) {
    return 0;  // Fail: Substring is empty
  }

  // Step (ii): Handle parentheses
  if (str[l] == '(') {
    // Find the matching closing parenthesis
    int close_idx = find_first_matching_close_parenthesis(str, l, r);
    if (close_idx < 0) {
      return 0;  // Fail: No matching parenthesis found
    }

    if (close_idx == r - 1) {
      // Entire expression is inside parentheses
      return __evaluate_expression_aux(res, str, l + 1, r - 1);
    } else {
      // There's an infix operator after the closing parenthesis
      int infix_idx = close_idx + 1;
      if (str[infix_idx] != '+' && str[infix_idx] != '-' &&
          str[infix_idx] != '*' && str[infix_idx] != '/') {
        return 0;  // Fail: Invalid infix operator
      }

      // Recursively evaluate left and right sides
      ratio_t left_res, right_res;
      if (!__evaluate_expression_aux(&left_res, str, l + 1, close_idx) ||
          !__evaluate_expression_aux(&right_res, str, infix_idx + 1, r)) {
        return 0;  // Fail: Recursive evaluation failed
      }

      // Apply the operator
      switch (str[infix_idx]) {
        case '+':
          return ratio_add(res, &left_res, &right_res);
        case '-':
          return ratio_sub(res, &left_res, &right_res);
        case '*':
          return ratio_mul(res, &left_res, &right_res);
        case '/':
          return ratio_div(res, &left_res, &right_res);
      }
    }
  }

  // Step (iii): Handle infix operators without parentheses
  int infix_idx = find_infix_operator(str, l, r);
  if (infix_idx >= l) {
    // If infix operator is at the first position, handle unary negation
    if (infix_idx == l && str[infix_idx] == '-') {
      ratio_t temp_res;
      if (!__evaluate_expression_aux(&temp_res, str, l + 1, r)) {
        return 0;  // Fail: Recursive evaluation failed
      }
      return ratio_neg(res, &temp_res);  // Apply negation
    }

    // Otherwise, it's a binary operator
    ratio_t left_res, right_res;
    if (!__evaluate_expression_aux(&left_res, str, l, infix_idx) ||
        !__evaluate_expression_aux(&right_res, str, infix_idx + 1, r)) {
      return 0;  // Fail: Recursive evaluation failed
    }

    // Apply the operator
    switch (str[infix_idx]) {
      case '+':
        return ratio_add(res, &left_res, &right_res);
      case '-':
        return ratio_sub(res, &left_res, &right_res);
      case '*':
        return ratio_mul(res, &left_res, &right_res);
      case '/':
        return ratio_div(res, &left_res, &right_res);
    }
  }

  // Step (iv): Leaf node, no parentheses or infix operator
  uint32_t number;
  if (!convert_substring_to_uint32(&number, str, l, r) || !fits_int32(number)) {
    return 0;  // Fail: Conversion failed
  }
  return create_fraction_unsigned_denominator(res, number, 1);
}

/* Evaluates the arithmetical expression formed by the string str to a
 rational number, putting the result into the variable pointed to by
 res.

 Returns a boolean indicating success or failure.

 Uses the __evaluate_expression_aux() function to do the bulk of the
 work and fails when __evaluate_expression_aux() fails.

 Uses the remove_character() function to remove all occurrences
 of the space character (' ') in the string. Uses string_length()
 to bootstrap the recursive process in __evaluate_expression_aux(),
 setting r to the length of the (modified) string.

 NOTHING TO BE MODIFIED HERE.

*/
int evaluate_expression(ratio_t *res, const char *str) {
  int len;

  len = string_length(str);
  if (len <= 0) return 0;

  char workstr[((size_t)len) + ((size_t)1)];
  char *dst;
  const char *src;

  for (dst = workstr, src = str; *src != '\0'; dst++, src++) {
    *dst = *src;
  }
  *dst = '\0';

  remove_character(workstr, ' ');

  int r;
  r = string_length(workstr);
  if (r <= 0) return 0;
  return __evaluate_expression_aux(res, workstr, 0, r);
}

/* Uses the above functions to have the user enter an
 arithmetical expression, evaluate it to a rational number
 and print the results.

 NOTHING TO BE MODIFIED HERE.

 HOWEVER: STUDENTS MUST TEST THEIR CODE ON AT LEAST THE
 FOLLOWING EXAMPLE RUNS.

 Example runs:

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 2 / 4
 You entered:
 2 / 4
 The expression you entered evaluates to 1 / 2, or, approx. 0.50000000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 1000000
 You entered:
 1000000
 The expression you entered evaluates to 1000000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 1000000*42
 You entered:
 1000000*42
 The expression you entered evaluates to 42000000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 1000000*1000000
 You entered:
 1000000*1000000
 Could not evaluate the string to a rational number.

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 -1000000*42
 You entered:
 -1000000*42
 The expression you entered evaluates to -42000000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 (((42*17)))
 You entered:
 (((42*17)))
 The expression you entered evaluates to 714

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 (((42*17))
 You entered:
 (((42*17))
 Could not evaluate the string to a rational number.

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 (((42*17)))/8
 You entered:
 (((42*17)))/8
 The expression you entered evaluates to 357 / 4, or, approx. 89.25000000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 2+3*4
 You entered:
 2+3*4
 The expression you entered evaluates to 14
 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 (2+3)*4
 You entered:
 (2+3)*4
 The expression you entered evaluates to 20

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 (1/9+1/6)*17/18
 You entered:
 (1/9+1/6)*17/18
 The expression you entered evaluates to 85 / 324, or, approx. 0.26234568

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 1/3 + 1 / 6
 You entered:
 1/3 + 1 / 6
 The expression you entered evaluates to 1 / 2, or, approx. 0.50000000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 1000000/(2*50001)
 You entered:
 1000000/(2*50001)
 The expression you entered evaluates to 500000 / 50001, or, approx. 9.99980000

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 2*4/7*(42+16*(3/7+1/11))/(11/33+8/13)+42
 You entered:
 2*4/7*(42+16*(3/7+1/11))/(11/33+8/13)+42
 The expression you entered evaluates to 2046294 / 19943, or, approx.
 102.60713032

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 9999999999999999999999999
 You entered:
 9999999999999999999999999
 Could not evaluate the string to a rational number.

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 (-2147483647)-1
 You entered:
 (-2147483647)-1
 The expression you entered evaluates to -2147483648

 $ ./expressions
 Please enter a mathematical expression
 with decimal integers, parentheses '(' and ')'
 and mathematical operators '+', '-', '*' and '/'
 -((-2147483647)-1)
 You entered:
 -((-2147483647)-1)
 Could not evaluate the string to a rational number.

*/
int main(int argc, char **argv) {
  while (1) {
    char str[BUFFER_SIZE];
    ratio_t res;

    printf(
        "Please enter a mathematical expression\n"
        "with decimal integers, parentheses '(' and ')'\n"
        "and mathematical operators '+', '-', '*' and '/'\n");
    input_string(str, sizeof(str));

    printf("You entered:\n%s\n", str);

    if (evaluate_expression(&res, str)) {
      if (res.den == ((uint32_t)1)) {
        printf("The expression you entered evaluates to %d\n", res.num);
      } else {
        printf(
            "The expression you entered evaluates to %d / %u, or, approx. "
            "%.8f\n",
            res.num, res.den, ratio_approx(&res));
      }
    } else {
      printf("Could not evaluate the string to a rational number.\n");
    }

    return 0;
  }
}
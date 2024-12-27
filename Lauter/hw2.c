/*
First Name: Eric
Last Name: Quezada
Student ID: 80532860
*/

#include <stdint.h>
#include <stdio.h>

/* This function does a bitwise multiplication of two variables a and b and
 * returns the result to user */
uint32_t multiply(uint32_t x, uint32_t y) {
  uint32_t a = x;
  uint32_t b = y;
  uint32_t res = 0;
  uint32_t t;
  int i = 0;

loop_start:
  if (i >= 32)
    goto loop_end;

  t = a & 1;
  if (t != 0) {
    res += b;
  }
  a >>= 1;
  b <<= 1;
  i++;
  goto loop_start;

loop_end:
  return res;
}

/* This function does a division of two variables a and b and returns the result
   to user in the form of: Quotient of x / y = result, Remainder =
   result_of_remainder
  */
void divide(uint32_t *quot, uint32_t *rem, uint32_t a, uint32_t b) {
  int i;
  uint32_t q, r;

  q = (uint32_t) 0;
  r = (uint32_t) 0;
  i = 32 - 1;

start_loop:
  if (i < 0) goto end_loop;
  r = r << 1;
  uint32_t shifted_a = a >> i;
  uint32_t isolated_bit = shifted_a & ((uint32_t) 1);
  r = r | isolated_bit;
  if (r >= b) goto subtract;
  goto next_iteration;

subtract:
  r = r - b;
  q = q | (((uint32_t) 1) << i);

next_iteration:
  i = i -1;
  goto start_loop;

end_loop:
  *quot = q;
  *rem = r;
}

void convert(char *str, uint32_t a) {
  uint32_t t, r;
  char *curr;
  char *i, *d;
  char c;

  t = a;
  if (t == ((uint32_t) 0)) goto zero_case;

  curr = str;

convert_loop:
  if (t == ((uint32_t) 0)) goto end_convert_loop;
  r = t % ((uint32_t) 10);
  t = t / ((uint32_t) 10);
  *curr = r + '0';
  curr = curr + 1;
  goto convert_loop;

end_convert_loop:
  *curr = '\0'; // Null-terminate the string
  curr = curr - 1;

  i = str;
  d = curr;

reverse_loop:
  if (i >= d) goto end_reverse_loop;
  c = *i;
  *i = *d;
  *d = c;
  i = i + 1;
  d = d - 1;
  goto reverse_loop;

end_reverse_loop:
  return;

zero_case:
  curr = str;
  *curr = '0';
  curr = curr + 1;
  *curr = '\0';
  return;
}


// Main function
int main() {
  int i;

  uint32_t a[] = {2, 3, 5, 7, 9, 11, 25, 100, 200};
  uint32_t b[] = {4, 3, 3, 2, 9, 12, 4, 1, 0};
  
  printf("Multiplication results using multiply():\n");
  printf("----------------------------------------------\n");
  for (i = 0; i < 9; i++) {
    printf("%d * %d = %d\n", a[i], b[i], multiply(a[i], b[i]));
  }
  printf("----------------------------------------------\n\n");


  printf("Division results using divide():\n");
  printf("----------------------------------------------\n");
  for (i = 0; i < 9; i++) {
    uint32_t q, r;
    divide(&q, &r, a[i], b[i]);
    printf("%d / %d = %d, remainder = %d\n", a[i], b[i], q, r);
  }
  printf("----------------------------------------------\n\n");


  printf("Conversion results using convert():\n");
  printf("----------------------------------------------\n");
  char buffer[10];
  uint32_t nums[] = {0, 4294967295, 1234, 982, 42, 17, 624, 978, 16791};
  for (i = 0; i < 9; i++) {
    convert(buffer, nums[i]);
    printf("convert(%u) = %s\n", nums[i], buffer);
  }
  printf("----------------------------------------------\n\n");
  return 0;
}

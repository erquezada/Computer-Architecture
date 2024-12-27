#include <stdio.h>
#include <stdint.h>

uint32_t multiply(uint32_t x, uint32_t y) {
  uint32_t a;
  uint32_t b;
  uint32_t res;
  uint32_t t;
  int i;

  a = x;
  b = y;
  res = (uint32_t) 0;
  i = 0;
  start:
    if (i>=32) goto end;
        t = a & ((uint32_t) 1);
        if (t == 0) goto shift; 
            res = res + b;
            goto shift;
  shift:
    a = a >> 1;
    b = b << 1;
    i = i + 1;
    goto start;
  end:
    return res;
}

void divide(uint32_t *quot, uint32_t *rem, uint32_t a, uint32_t b) {
    int i = 32 - 1;
    uint32_t q = 0;
    uint32_t r = 0;

start_loop:
    if (i < 0)
        goto end_loop;

    // Shift r left by 1, breaking down the operation
    r = r * 2;

    // Extract the i-th bit of a
    uint32_t temp = a >> i;
    temp = temp & 1;

    // Set the least significant bit of r
    r = r + temp;

    if (r >= b)
        r = r - b; // Subtract b from r if r is greater or equal
        // Set the i-th bit of q by breaking down q | (1 << i)
        uint32_t shift = 1;
        shift = shift << i;
        q = q + shift;

    // Decrement i
    i = i - 1;

    goto start_loop;

end_loop:
    *quot = q; // Store quotient
    *rem = r;  // Store remainder
}

void convert(char *str, uint32_t a) {
  uint32_t t, r;
  char *curr;
  char *i, *d;
  char c;

  t = a;
  if (t == ((uint32_t) 0)) {
    curr = str;
    *curr = '0';
    curr++;
    *curr = '\0';
    return;
  }

  curr = str;
  while (t != ((uint32_t) 0)) {
    r = t % ((uint32_t) 10);
    t /= (uint32_t) 10;
    *curr = r + '0';
    curr++;
  }
  *curr = '\0';
  curr--;

  i = str;
  d = curr;
  while (i < d) {
    c = *i;
    *i = *d;
    *d = c;
    i++;
    d--;
  }
}

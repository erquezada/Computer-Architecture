
#include <stdio.h>

int convert_string_to_unsigned_integer(unsigned int *res, char *str) {
  unsigned int acc, d;
  char *curr;
  
  if (str == NULL) return 0;
  if (*str == '\0') return 0;

  acc = (unsigned int) 0;
  for (curr=str;*curr!='\0';curr++) {
    if (*curr < '0') return 0;
    if (*curr > '9') return 0;
    d = (unsigned int) (*curr - '0');
    acc = acc * ((unsigned int) 10) + d;
  }
  *res = acc;
  return 1;
}

void convert_unsigned_integer_to_string(char *str, unsigned int a) {
  unsigned int acc, d;
  int i, l, r;
  char t;
  
  if (a == ((unsigned int) 0)) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  i = 0;
  acc = a;
  while (acc != ((unsigned int) 0)) {
    d = acc % 10;
    acc = acc / 10;
    str[i] = ((char) d) + '0';
    i++;
  }
  str[i] = '\0';

  l = 0;
  r = i - 1;
  while (l < r) {
    t = str[l];
    str[l] = str[r];
    str[r] = t;
    l++;
    r--;
  }
}

int main(int argc, char **argv) {
  unsigned int a, b;
  char str[65];
  
  printf("Please enter an unsigned integer: ");
  scanf("%u", &a);

  convert_unsigned_integer_to_string(str, a);

  printf("Your integer converted to a string is \"%s\"\n", str);

  if (convert_string_to_unsigned_integer(&b, str)) {
    printf("The string converted back to an integer is %u\n", b);
  } else {
    printf("Could not convert that string back to an integer\n");
  }
      
  return 0;
}

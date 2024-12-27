#include <stdio.h>

int main(int argc, char **argv)
{

  int a;
  int *aPtr;

  a = 9;
  aPtr = &a;
  printf("The value of a is %d\n",a);
  printf("The value of aPtr is %p\n",aPtr);
}

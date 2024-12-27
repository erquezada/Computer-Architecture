#include <stdio.h>

void cubeByReference(int *nPtr);

int main(int argc, char **argv)
{
  int num;
  num = 11;
  printf("The original value of the number is: %d\n", num);

  cubeByReference(&num);
  printf("The new value of the number is: %d\n", num);
  return 0;
}

void cubeByReference(int *nPtr)
{
  *nPtr = (*nPtr * *nPtr * *nPtr);
  
} 

# include <stdio.h>

int cubeByValue(int n);

int main(int argc, int **argv)
{
  int num;
  num = 11;

  printf("The original value of number is %d", num);
  num = cubeByValue(num);
  return 0;
}

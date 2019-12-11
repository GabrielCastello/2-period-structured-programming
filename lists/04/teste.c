#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int calculateSum(int n, int i, int sum)
{
  // printf("N: %i\n", n);
  printf("I: %i\n", i);
  printf("Sum: %i\n", sum);
  if (i <= n)
  {
    sum += i;
    i++;
    return calculateSum(n, i, sum);
  }
  else
  {
    return sum;
  }
}

int main()
{
  int n = 5;
  printf("sum: %i", calculateSum(n, 0, 0));

  printf("\n\n");
  return 0;
}
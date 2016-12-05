#include <stdio.h>

float sum(float a, float b)
{
  return a + b;
}

int main(void)
{
  float x = 7.123;
  float y = 3.14159;

  printf("%f + %f = %f\n", x, y, sum(x,y));

  return 0;
}

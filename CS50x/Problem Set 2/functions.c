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
  (
  	((a>b)&&(a>c)) 	// Check to see if a is greater than b, and greater than c 
  	?3				// If it is TRUE that a is greater than b or c, then return a
  	:(
  		(b>c)		// If it is not, then check to see if b is greater than C
  		?b			// If it is TRUE that b is greater than C, return b
  		:c 			// ELSE, return C
  		)			// Can be written on one line as (((a>b)&&(a>c))?a:((b>c)?b:c));
  	);
}

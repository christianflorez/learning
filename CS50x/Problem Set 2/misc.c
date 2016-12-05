#include<stdio.h>

int add_two_ints(int x, int y); // Lets compiler know to look for a function later on 
bool valid_triangle(int a, int b, int c);

int main(int argc, string argv)
{
	int a = strtol(argv[1], NULL, 10);
	int b = strtol(argv[2], NULL, 10);
	int c = strtol(argv[3], NULL, 10);
	int lar;
	lar = (((a>b)&&(a>c))?a:((b>c)?b:c)); 	// Example of a ternary operator ? is IF TRUE, : is ELSE (if false)
											// Stuff on left is the condition to evaluate.
	printf(“largest is %d”, lar);

// If I had more than three arguments and I wanted to count them, you could do an argc for loop
	return 0;
}

int add_two_ints(int x, int y)
{
	return x + y;
}

bool valid_triangle(int x, int y, int z);
{
	if (x < 1 || y < 1 || z < 1)
	{
		return false
	}
	else if ((x + y < z) || (x + z < y) || (y + z < x))
	{
		return false
	}
	else 
	{
		return true
	}
}
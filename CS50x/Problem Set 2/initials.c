#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
	// Asks user for input
	string name = GetString();

	// Loop to create initials
	for (int i = 0; i < strlen(name); i++)
	{
		int current = name[i];
		int next = name[i+1];

		// Prints the first initial, making sure that user entered an alphanumeric character
		if ((i == 0) && isalpha(current))
		{
			printf("%c", toupper(current));
		}

		// Otherwise, program looks to print the letter after a space, as long as it is not another space
		else if (isblank(current) && isalpha(next))
		{
			printf("%c", toupper(next));
		}
	}

	printf("\n");
}
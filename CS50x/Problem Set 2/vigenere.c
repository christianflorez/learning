#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Function declarations
void alphawrap(string x, int y, int i);

// Main program
int main(int argc, string argv[])
{
    // Checks to make sure there is only one command line argument after program name
	if (argc != 2)
  	{
    	printf("Usage: ./vigenere <key>\n");
    	return 1;
  	}
  	
	// Checks for digits in argv[1]
  string key = argv[1];

  for (int i = 0; i < strlen(key); i++)
      if (isalpha(key[i]) == false)
      {
          printf("Error: Please input a single alphanumeric key.\n");
          return 1;
      }
        
  // Prompts user for input
  string message = GetString();


  // Main encryption loop
  int shiftkey;
  for (int i = 0, j = 0; i < strlen(message); i++)
	{
		if (j >= strlen(key))
		{
			j = 0;
		}

    // Creates shift values while discarding differences in case
    shiftkey = toupper(key[j]) - 'A';

    // Checks for upper case + wrap
    if ((isupper(message[i])) && (message[i] + shiftkey > 'Z'))
    {
      alphawrap(message, shiftkey, i);
      j++;
    }

    // Checks for lower case + wrap
    else if ((islower(message[i])) && (message[i] + shiftkey > 'z'))
    {
      alphawrap(message, shiftkey, i);
      j++;
    }

    // Otherwise, prints alpha and shifts cipher
    else if (isalpha(message[i]))
    {
      printf("%c", message[i] + shiftkey);
      j++;
    }

    // Else prints non-alpha characters without returning j which shifts cipher
    else 
    {
      printf("%c", message[i]);
    }

	}
	printf("\n");
	return 0;
}

// Function definitions
void alphawrap(string x, int y, int i)
{
  x[i] = x[i] + (y - 26);
  printf("%c", x[i]);
}
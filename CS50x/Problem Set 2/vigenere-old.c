#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Ideas for cleaning up:
// 1. Write a function that does the key's math for you.
// 2. Rewrite non-alpha print with !
// 3. ??? Watch Zamyla's video


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
  		// Resets key to wrap around message
  		if (j >= strlen(key))
  		{
  			j = 0;
  		}

    	// Encrypts Message if upper case
  		if (isupper(message[i]))
  		{
        shiftkey = toupper(key[j]) - 'A';
			  if (message[i] + shiftkey > 'Z')
        {
					message[i] = message[i] + (shiftkey - 26);
					printf("%c", message[i]);
					j++;
				}

				else
				{
					printf("%c", message[i] + shiftkey);
					j++;
				}
		  }

      // Encrypts Message if lower case
  		else if (islower(message[i]))
  		{
        shiftkey = toupper(key[j]) - 'A';
        if (message[i] + shiftkey > 'z')
  			{
  				message[i] = message[i] + (shiftkey - 26);
  				printf("%c", message[i]);
  				j++;
  			}

  			else
  			{
  				printf("%c", message[i] + shiftkey);
  				j++;
  			}
  		}

      // Prints non-alphanumeric characters
		  else if (!isalpha(message[i]))
		  {
			printf("%c", message[i]);
		  }
  	}
  	printf("\n");
  	return 0;
}
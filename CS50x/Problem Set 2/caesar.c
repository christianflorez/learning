#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


// *********************
// Function Declarations
// *********************

void encryptupper(string x, int y, int i);
void encryptlower(string x, int y, int i);
void printpunct(string x, int i);


// *********************
// Main Program
// *********************

int main (int argc, string argv[])
{
  // Determines if user entered only one non-negative integer or more than one argument
  if (argc != 2)
  {
    printf("Usage: ./caesar <key>\n");
    return 1;
  }
  else if (atoi(argv[1]) < 1)
  {
      printf("Error: Please input only one non-negative integer.\n");
      return 1;
  }
  
  // Wraps key around number of letters in alphabet
  int key = strtol(argv[1], NULL, 10);
  key = key % 26;
  
  // Prompts user for a message to encrypt
  string message = GetString();
  
  for (int i = 0; i < strlen(message); i++)
  {
    // Encrypts message
      encryptupper(message, key, i); 
      encryptlower(message, key, i);
      printpunct(message, i);
  }
  
  printf("\n");
  
  return 0;
}


// *********************
// Function Definitions
// *********************

// Encrypts upper case letters
void encryptupper(string x, int y, int i)
{
  if (isupper(x[i]))
  {
      if (x[i] + y > 90)
      {
          x[i] = x[i] + (y - 26);
          printf("%c", x[i]);
      }

      else
      {
          printf("%c", x[i] + y);
      }
  }
}

// Encrypts lower case letters
void encryptlower(string x, int y, int i)
{
  if (islower(x[i]))
    {
       if (x[i] + y > 122)
       {
           x[i] = x[i] + (y - 26);
           printf("%c", x[i]);
       }

       else
       {
           printf("%c", x[i] + y);
       }

    }
}

// Prints non-alphanumeric characters
void printpunct(string x, int i)
{
  if (isalpha(x[i]) == false)
  {
    printf("%c", x[i]);
  }
}
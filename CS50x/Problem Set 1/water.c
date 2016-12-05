#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompts the user for minutes spent showering
    int minutes = 0;
    do {
        printf("Please type in the number of minutes you spend showering:\n");
        minutes = GetInt();
    }
    while (minutes < 1);
    
    //calculates and prints amount of bottles of water used per minutes showered
    printf("minutes: %i\n", minutes);
    printf("bottles: %i\n", minutes * 12);
}
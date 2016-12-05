#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompt user for float change
    float change = 0.00;
    do {
        printf("Please type in the amount of change owed:\n");
        change = GetFloat();
    }
    while (change <= 0);
    
    // multiplies by 100 to get rid of decimal so we can cast to int
    change = change * 100;
    
    // rounds change first before casting to int
    float roundf(float change);
    change = roundf(change);
    
    // truncates change by casting to int
    change = (int)change;
    
    // evaluate amount of quarters
    int quarters = 0;
    while ((int)change >= 25)
    {
        change = change - 25;
        quarters++;
    }
    
    // evaluate dimes
    int dimes = 0;
    while ((int)change >= 10)
    {
        change = change - 10;
        dimes++;
    }
    
    // evalute nickels
    int nickels = 0;
    while ((int)change >= 5)
    {
        change = change - 5;
        nickels++;
    }
    
    // evaluate pennies
    int pennies = 0;
    while ((int)change >= 1)
    {
        change = change - 1;
        pennies++;
    }
    
    // calculate number of coins total
    printf("%i\n", quarters + dimes + nickels + pennies);
}
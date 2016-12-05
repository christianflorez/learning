#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompts the user for the height of the pyramid, limiting between 1 and 23
    int height = 0;
    do {
        printf("Please give me the height of Mario's pyramid: \n");
        height = GetInt();
    }
    while ( (height < 0) || (height > 23));
    
    int count = height;
    int hashes = 2;
    
    while (count > 0)
    {
        // this prints spaces related to count's value
        for(int i = 0; i < count - 1; i = i + 1 )
        {
            printf (" ");
        }
        
        // this prints hashes
        for(int i = 0; i < hashes; i = i + 1 )
        {
            printf ("#");
        }
        printf("\n");
        
        count--;
        hashes++;
    }
}
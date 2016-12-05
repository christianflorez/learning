#include <stdio.h>
#include <math.h>
 
int main (void) 
{
    for (int i = 2; i < 100; i++)          // set i to 2. As long as i is less than 100, add 1 to i
        for (int j = 2; j * j <= i; j++)     // set j to 2. As long as j*j* is <= i, count j

        {
            if (i % j == 0)                  // if i modulo j is equal to 0, break out of loop
                break;
            else if (j+1 > sqrt(i)) {
                cout << i << " ";

            }

        }   

    return 0;
}

/* Let's run through a few numbers.
i is 2. j is 2. j*j is 4, which is NOT <=4. break out of loop
i is 3. j is 2. j*j is 4
i is 4. j is 2. j*j is 4. 4/4 is 0, so BREAK
i is 5. j is 2. j*j is 4, which is less than 5. 4/5 is not 0. j+1 = 5. 5 > sqrt(5), so print 5. 
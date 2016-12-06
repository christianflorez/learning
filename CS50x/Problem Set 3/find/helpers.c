/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * DEPRECATED LINEAR SEARCH
 */
// bool search(int value, int values[], int n)
// {
//     if (n < 0)
//     {
//         return false;
//     }

    
//     for (int i = 0; i < n; i++)
//     {
//         if (value == values[i])
//         {
//             return true;
//         }
//     }
//     return false;
// }



/**
 * Uses binary search to find values
 */
bool search(int value, int values[], int n)
{

    if (n < 0)
    {
        return false;
    }
    
    int min = 0;
    
    int midpoint = find_midpoint(min, n - 1);
    
    if (values[midpoint] < value)
    {
        return binarysearch(value, values, n, midpoint + 1);
    }
    else if (values[midpoint] > value)
    {
        return binarysearch(value, values, midpoint - 1, min);
    }
    else if (values[midpoint] == value)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

/* 
 * Recursive binary search
 */
bool binarysearch(int value, int values[], int max, int min)
{
    if (max < min)
    {
        return false;
    }
    
    int midpoint = find_midpoint(min, max);
    
    if (values[midpoint] < value)
    {
        return binarysearch(value, values, max, midpoint + 1);
    }
    else if (values[midpoint] > value)
    {
        return binarysearch(value, values, midpoint - 1, min);
    }
    else if (values[midpoint] == value)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}


int find_midpoint(int min, int max)
{
    return ((max-min)/2) + min;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    // Implementation of bubble sort
    int count = 0;
    do {
        count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                int bubble = values[i + 1];
                values[i + 1] = values[i];
                values[i] = bubble;
                count++;
            }
        }
    }
    while (count > 0);
    
    return;
}
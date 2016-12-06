/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Recursive binary search
 */
bool binarysearch(int value, int values[], int max, int min);

/**
 * Formula to find midpoints
 */ 
int find_midpoint(int min, int max);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);
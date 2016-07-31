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

bool binary_search(int value, int values[], int start, int length);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start = 0;
    
    bool result = binary_search(value, values, start, n-1);
    if (result == 0) { return true; } else { return false; }
} 

bool binary_search(int value, int values[], int start, int length)
{
    if (length >= start)
    {
        int middle = start + (length - start) / 2;
        
        if (values[middle] == value) { return 0; }
        
        if (values[middle] > value) { return binary_search(value, values, start, middle-1); }
        
        return binary_search(value, values, middle+1, length);
    }
    return -1;
}

// bool linear_search(int value, int values[], int n)
// {
//     // implement a searching algorithm -> linear search
//     for (int i = 0; i < n; i++)
//         if (values[i] == value) { return true; }
    
//     return false;
// }

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i=1; i< n; i++)
    {
        int current = values[i];
        int previous = i-1;
        
        while (previous >= 0 && values[previous] > current)
        {
            values[previous+1] = values[previous];
            previous = previous - 1;
        }
        
        values[previous+1] = current;
    }
} 

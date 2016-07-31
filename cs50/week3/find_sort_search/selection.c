#include <stdio.h>

// selection sort: find the smallest unsorted element in an array 
// and swap it with the first unsorted element in that array

int main(void)
{
    int array[] = { 5, 1, 6, 4, 2, 3 };
    int ar_size = 6;
    
    for (int i = 0; i < (ar_size-1); i++)
    {
        int position = i;
        
        for(int j = i+1; j < ar_size; j++)
            if (array[position] > array[j]) { position = j; }
        
        if (position != i)
        {
            int swap = array[i];
            array[i] = array[position];
            array[position] = swap;
        }
    }
    
    for(int i=0; i< ar_size; i++)
        printf("%i", array[i]);
}
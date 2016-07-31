#include <stdio.h>

// insertion sort -> proceed once thougth the array from left-to-right,
// shifting elements as necessary to insert each element into its correct place

int main(void)
{
    int array[] = { 5, 1, 6, 4, 2, 3 };  // 1 5 6 4 2 3
    int ar_size = 6;
    
    for (int i=1; i< ar_size; i++)
    {
        int current = array[i];
        int previous = i-1;
        
        while (previous >= 0 && array[previous] > current)
        {
            array[previous+1] = array[previous];
            previous = previous - 1;
        }
        
        array[previous+1] = current;
    }
    
    for(int i=0; i< ar_size; i++)
        printf("%i", array[i]);
}
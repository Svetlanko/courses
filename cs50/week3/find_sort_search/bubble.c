#include <stdio.h>

// bubble sort -> swap ajacent pairs of elements if they are out of order.
// effectively bubbling larger elements to the right and smaller to the end

int main(void)
{
    int array[] = { 5, 1, 6, 4, 2, 3 };
    int ar_size = 6;
    
    // 5, 1, 6, 4, 2, 3
    for (int i = 0; i < ar_size-1; i++)
    {
        for (int j = i+1; j < ar_size; j++)
        {
            if (array[i] > array[j])
            {
                int swap = array[i];
                array[i] = array[j];
                array[j] = swap;
            }
        }
    }
    
    for (int i = 0; i < ar_size; i++)
        printf("%i", array[i]);
}
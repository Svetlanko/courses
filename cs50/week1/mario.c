#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("height:");
        height = GetInt();
        
    } while (23 < height || height < 0);
    
    for(int i=0; i < height; i++)
    {
        for(int spaces = (height-1); spaces > i; spaces--) 
        {
            printf(" ");
        }
        for(int blocks = 0; blocks <= (i+1); blocks++)
        {
            printf("#");
        }
        printf("\n");
    }
}
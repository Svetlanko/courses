#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    const int quater = 25;
    const int dime   = 10;
    const int nickel =  5;
    const int penny  =  1;
    
    int num_of_quaters  = 0;
    int num_of_dimes    = 0;
    int num_of_nickels  = 0;
    int num_of_pennies  = 0;
     
    float input = 0.00;
    
    while (input <= 0)
    {
        printf("O hai! How much change is owed?\n");
        input = GetFloat();  
    }

    int change = roundf(input * 100);
    
    while(change != 0)
    {
        if (change/quater >= 1)
        {
            float quater_division = change/quater;
            num_of_quaters = (int) quater_division;
            change = change - num_of_quaters * quater;
        }
        
        if (change/dime >= 1)
        {
            float dime_division = change/dime;
            num_of_dimes = (int) dime_division;
            change = change - num_of_dimes * dime;
        }
        
        if (change/nickel >= 1)
        {
            float nickel_division = change/nickel;
            num_of_nickels = (int) nickel_division;
            change = change - num_of_nickels * nickel;
        }
        
        if (change/penny >= 1)
        {
            float pennie_division = change/penny;
            num_of_pennies = (int) pennie_division;
            change = change - num_of_pennies * penny;
        }
    }
    
    printf("%i\n", num_of_quaters + num_of_dimes + num_of_nickels + num_of_pennies);
}
#include <stdio.h>

int main(void)
{
    const float GALLON_PER_MINUTE = 1.5;
    const int OUNCES_IN_GALLON = 128;
    const int OUNCES_IN_BOTTLE = 16;
    
    int minutes;
    printf("minutes: ");
    scanf("%i", &minutes);
    
    int bottles = ( GALLON_PER_MINUTE * OUNCES_IN_GALLON * minutes ) / OUNCES_IN_BOTTLE;
    printf("bottles: %i\n", bottles);
}
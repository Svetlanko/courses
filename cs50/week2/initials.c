#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    string full_name = GetString();
    char *names = strtok(full_name, " ");
    
    while( names != NULL) 
    {
        printf("%c", toupper(names[0]));
        names = strtok(NULL, " ");
    }
    
    printf("\n");
}
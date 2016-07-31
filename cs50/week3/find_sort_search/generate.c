/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // check if no parameters are passed. it expectes to have 2 or 3 parameters;
    // if it is not the case then print a message and return an error
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // convert argv[1], which is first parameter, to an integer
    int n = atoi(argv[1]);

    // check if 3 parameters are passed then call srand48 function before calling drand48 
    // to initialize random seedval with a value passed by user
    // otherwise use current time(with seconds) as a randomized seedvalue
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // iterate thru 'n' which is the first parameter
    // and for every 'n' create a pseudoramdom number
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0; 
}
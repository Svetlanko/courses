#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define ALPHABET_SIZE      26
#define UPPER_ASCII_START  65
#define UPPER_ASCII_END    90
#define LOWER_ASCII_START  97
#define LOWER_ASCII_END    122

char encrypt(char letter, int key);
int loop_alphabet(int key);
bool invalid(int argc);
int error();

int main(int argc, string argv[])
{
    if (invalid(argc)) { return error(); }
    
    int cipher_key = atoi(argv[1]);
    string sentence = GetString();
    int length = strlen(sentence);
    char encypted_sentence[length];
    
    for(int i = 0; i < length; i++) 
    {
        char letter = sentence[i];
        encypted_sentence[i] = ( isalpha(letter) ? encrypt(letter, cipher_key) : letter );
    }

    printf("%s\n", encypted_sentence);
    return 0;
}

bool invalid(int argc)
{
    int number_of_params = argc - 1;
    return (number_of_params > 1 || number_of_params == 0);
}

int error()
{
    printf("Error\n");
    return 1;
}

char encrypt(char letter, int key) 
{
    char result;

    key = (key > ALPHABET_SIZE) ? loop_alphabet(key) : key;
    
    int encrypted_char = (int) letter + key;
    int ascii_start = ( isupper(letter) ? UPPER_ASCII_START : LOWER_ASCII_START );
    int ascii_end = ( isupper(letter) ? UPPER_ASCII_END : LOWER_ASCII_END);
    
    if (encrypted_char <= ascii_end)
    {
        result = encrypted_char;
    }
    else
    {
        //need to do (-1) as we should treat alphabet as 0..25 instead of 1..26
        result = ascii_start - 1 + (encrypted_char - ascii_end);
    }
    
    return result;
}

int loop_alphabet(int key)
{
    int times = (int) key / ALPHABET_SIZE;
    return key - ALPHABET_SIZE * times;
}
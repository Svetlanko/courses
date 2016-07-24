#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define ALPHABET_SIZE      26
#define UPPER_ASCII_START  65
#define LOWER_ASCII_START  97

bool invalid(int argc);
int error();
bool all_alpha(string cipher);
char encrypt(char plain_text_char, char cipher_char);
int calculate_shift(int text_position, int cipher_char_position);
int ascii_start(char letter);
int char_position(char letter);

int main(int argc, string argv[])
{
    if (invalid(argc)) { return error(); }
    
    string cipher = argv[1];
    if (all_alpha(cipher) == false) { return error(); }

    string plain_text = GetString();
    int plain_text_length = strlen(plain_text) + 1;
    char encrypted_text[plain_text_length];

    int j = 0;
    for(int i = 0; i <= plain_text_length; i++)
    {
        if isalpha(plain_text[i])
        {
            encrypted_text[i] = encrypt(plain_text[i], cipher[j]);
            j = ( (j == (strlen(cipher) - 1)) ? 0 : j+1 );
        }
        else 
        {
            encrypted_text[i] = plain_text[i];
        }
    }
    
    printf("%s\n", encrypted_text);
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

bool all_alpha(string cipher)
{
    int length = strlen(cipher);
    
    for(int i = 0; i < length; i++)
    {
        if (isalpha(cipher[i]) == false) { return false; }
    };
    return true;
}

char encrypt(char plain_text_char, char cipher_char)
{
    char encrypted_char;
    int plain_text_ascii_start = ascii_start(plain_text_char);
    int plain_text_char_position = char_position(plain_text_char);
    int cipher_char_position = char_position(cipher_char);
    
    int shift = calculate_shift(plain_text_char_position, cipher_char_position);

    encrypted_char = plain_text_ascii_start + shift;
    return encrypted_char;
}

int calculate_shift(int plain_text_char_position, int cipher_char_position)
{
    int shift = plain_text_char_position + cipher_char_position;
                    
    if (shift > ALPHABET_SIZE)
    {
        shift = plain_text_char_position + cipher_char_position - ALPHABET_SIZE;
    }
    return shift;
}

int ascii_start(char letter)
{
    return (isupper(letter)) ? UPPER_ASCII_START : LOWER_ASCII_START;
}

int char_position(char letter) 
{
    return ((int) letter) - ascii_start(letter);
}
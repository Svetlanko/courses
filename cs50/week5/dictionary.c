/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define SIZE 1000000

// define node for linked list
typedef struct node {
    char word[LENGTH+1];
    struct node* next;
} node;

node* hashtable[SIZE] = { NULL }; 
int dictionary_size = 0; 

unsigned hash(char *s) {
    unsigned hashval;
    
    for (hashval = 0; *s!= '\0'; s++) 
        hashval = *s + 31 * hashval;
    return hashval % SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int word_length = strlen(word);
    char* copy_of_word = malloc(sizeof(word_length + 1));
    
    for (int i = 0; i < word_length; i++) {
        copy_of_word[i] = tolower(word[i]);
    }
    
    copy_of_word[word_length] = '\0';
    
    int index = hash(copy_of_word);
    node* result = hashtable[index];
    
    if (result) {
        node* current = result;
        while (current != NULL) {
            if (strcmp(copy_of_word, current->word) == 0) {
                return true;
            }
            current = current->next;
        }
    } 
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL) {
        printf("Couldn't read input file\n");
        return false;
    }
    
    char word[LENGTH+1]; //initialize an array to store a word from a dictionary
    
    while (fscanf(dictionary_file, "%s\n", word) != EOF) {
        dictionary_size++;
        node* new_word = malloc(sizeof(node));
        
        strcpy(new_word->word, word);
        new_word->next = NULL;
        
        int index = hash(word);
        
        if (hashtable[index] == NULL) {
            hashtable[index] = new_word;
            new_word->next = NULL;
        } else {
            new_word->next = hashtable[index];
            hashtable[index] = new_word;
        }
    }
    fclose(dictionary_file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionary_size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < SIZE; i++) {
        node* current_node = hashtable[i];
        if (current_node) {
            node* temp_node = current_node->next;
            free(current_node);
            current_node = temp_node;
        }
    }
    
    return true;
}

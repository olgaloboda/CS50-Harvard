/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
 
#define SIZE 26
 
#include "dictionary.h"
 
typedef struct node {
     
    char word[LENGTH+1];
    struct node *next;
 
} node;
 
node *head[26];
int counter = 0;
int x = 0;
 
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int hash = toupper(word[0]) - 'A';
    x = hash % SIZE;
    int len = strlen(word);
    char new_word [len + 1];
    strcpy(new_word, word);
    node *cursor = NULL;
    cursor = head[x];
    for (int j = 0; j < len; j++) {
        if (isupper(new_word[j])){
            new_word[j] = tolower(new_word[j]);
        }
    }
    while (cursor != NULL) {
        if (strcmp(new_word, cursor->word) == 0) { 
            return true;
        }
        else {
            cursor = cursor->next;
        } 
    }
    return false;
}
 
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
 
    FILE* file = fopen(dictionary, "r");
     
    // check for successful open
     
    if (file == NULL) {
         
        printf("Could not open a file\n");
        return 2;    
    }
    
    char newWord[LENGTH+1];
     
    while (fscanf(file, "%s", newWord) == 1) {
      
        node *new_node = malloc(sizeof(node));
      
        strcpy(new_node->word, newWord);
         
        int hash = toupper(new_node->word[0]) - 'A';
        x = hash % SIZE;
         
        if (head[x] != NULL) {
            new_node->next = head[x];
            head[x] = new_node;
        }
        else {
            head[x] = new_node;
            new_node->next = NULL;
        }
        counter++;
    }
     
    fclose(file);
    //printf("dictionary is loaded!");
    return true;
}
 
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    //printf("all words are checked!\n");
    if (counter > 0) {
        return counter;
    }
    else {
        return false;
    }
}
 
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    //printf("issue is here!\n");
    for (int i = 0; i < 26; i++) {
        node* cursor = head[i];
            while (cursor != NULL) {
                node* temp = cursor;
                cursor = cursor->next;
                free(temp);
            }
          
        free(cursor);
    }
    return true;
}
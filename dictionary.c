// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 100000;

// Hash table
node *table[N];

// declaring word counter in dictionary
unsigned int word_counter = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get the hash key of word by using hash function
    unsigned int hash_index = hash(word);

    // creating copy of word and making it lowercase
    char  target_word [LENGTH + 1];
    strcpy(target_word, word);

    for (int i = 0; target_word[i] != '\0'; i++)
        {
            target_word[i] = tolower(target_word[i]);
        }

    // create a pointer that points at the node with the same key value
    node *current_node = table[hash_index];

    // loop through nodes until node is empty
    while (current_node != NULL)
    {
        // check if the word in node is the same as target word
        if (strcmp(current_node->word, target_word) == 0)
        {
            return true;
        }

        // move to the next node
        current_node = current_node->next;
    }

    // if there is no match found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = hash * 33 + c;
    }

    return hash % N; // number of buckets
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // opening the file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //creating buffer for word
    char current_word [LENGTH + 1];

    // looping through each word in file
    while (fscanf(file, "%s", current_word) != EOF)
    {
        // allocating memory for new node
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // making word lowercase and copying current word into new node
        for (int i = 0; current_word[i] != '\0'; i++)
        {
            current_word[i] = tolower(current_word[i]);
        }

        strcpy(new_node->word, current_word);

        // using hash function to generate key for current word
        unsigned int hash_index = hash(new_node->word);

        // putting the new node in the bucket at generated index
        new_node->next = table[hash_index];
        table[hash_index] = new_node;

        // keeping th e count of the words
        word_counter += 1;
    }

    fclose(file);

    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // create pointer to the node
        node* current_node = table[i];

        // go through each node in bucket
        while (current_node != NULL)
        {
            // free current node and go to next one
            node* temp_node = current_node;
            current_node = current_node->next;
            free(temp_node);
        }
    }
    return true;

}

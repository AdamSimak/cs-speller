# CS50 Speller - Dictionary Implementation (C)
This project is part of CS50's problem set and focuses on implementing a spell checker in C. The main task I completed was implementing the dictionary functionality (`dictionary.c`, `dictionary.h`),
including loading words, checking spelling, and managing memory efficiently using a hash table with linked lists.

The rest of the project, including `speller.c`, `Makefile`, and input folders, was provided as distribution code by CS50.

## Features (Implemented by Me)
- Load a dictionary of words into memory.
- Check if a word exists in the dictionary (case-insensitive).
- Count the total number of words in the dictionary.
- Unload the dictionary from memory safely, freeing all allocated memory.
- Implement a hash table with linked lists to allow fast lookups.

## How to Compile and Run
1. Compile the program using the provided Makefile.
   ```bash
   make speller
   ```
2. Run the program:
   ```bash
   ./speller dictionaries/small texts/lalaland.txt
   ```
   - `dictionaries/small` - dictionary file to load (can be replaced with `dictionaries/large`)
   - `texts/lalaland.txt` - text file to spell-check

Note: Only `dictionary.c` was implemented by me. The rest of the files (e.g., `speller.c`, folders) were provided as distribution code.

## Project &structure
speller/

├─ dictionaries/    (Contains dictionary files with word lists used for spell-checking)

├─ keys/           (Test or helper files, e.g., smaller dictionaries for testing)

├─ texts/          (Sample text files to run spell-checking on)

├─ dictionary.c    (Implemented by me: contains the dictionary functions (load, check, hash, size, unload))

├─ dictionary.h    (Header file declaring dictionary functions and constants)

├─ speller.c       (Distribution code: main program that loads dictionary and checks text)

├─ Makefile        (Build instructions for compiling speller and dictionary)

## `dictionary.c` (Implemented by me)
Contains the core dictionary functionality:
- `load(const char *dictionary)` - Loads all words from a dictionary file into memory using a hash table.
- `check(const char *word)` – Returns `true` if a given word exists in the dictionary, `false` otherwise. Case-insensitive.
- `hash(const char *word)` – Hashes a word to a number corresponding to a bucket in the hash table.
- `size(void)` – Returns the number of words loaded into the dictionary.
- `unload(void)` – Frees all memory used by the dictionary.

## Example Output
```bash
./speller dictionaries/small texts/lalaland.txt
MISSPELLED WORDS
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
Shangri
fianc
Sebastian's
...

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```

## Skills Demonstarted
 - Dynamic memory management with malloc and free.
 - Designing and using hash table with linked lists.
 - Implementing efficient string operations and case-sensitive operations.
 - Understanding and implementing core algorithms to optimize speed for large datasets
 - reading and understanding existing code and extending it.

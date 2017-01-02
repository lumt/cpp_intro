#ifndef SHRINK_H
#define SHRINK_H

#include <iostream>

// function to return integer indexed in the dictionary,
// returns -1 if not in dictionary
int lookup(const char* word,const char** dictionary);

// function to encode -> use lookup as helper function
void encode(const char* word, char* compressed,const char** dictionary);

#endif

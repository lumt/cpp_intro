#ifndef PIGGY_H
#define PIGGY_H

#include <iostream>
#include <fstream>

using namespace std;

int findFirstVowel(const char* word);

bool isVowel(char ch);

void translateWord(const char* english, char* piglatin);

void translateStream(istream& in, ostream& out);


#endif
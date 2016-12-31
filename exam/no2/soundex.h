#ifndef SOUNDEX_H
#define SOUNDEX_H

void encode(const char* surname, char* soundex);

int compare(const char* s1, const char* s2);

int count(const char* surname, const char* sentence);

bool letterIn(const char letter, const char* phrase);

#endif
#ifndef BRAILLE_H
#define BRAILLE_H value

#include <fstream>

using namespace std;

int encode_character(char ch, char* braille);

void encode_alpha(char ch, char* braille);

void encode(const char* text, char* braille);
void encodeR(const char* text, char* braille);
bool encodable(const char* text, char* buffer);

void print_braille(const char* text, ostream& out);
void print_row(const char* braille, int row, ostream& o);

#endif
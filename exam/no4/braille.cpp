#include <iostream>
#include <cctype>
#include "braille.h"

// function to encode given character to braille
int encode_character(char ch, char* braille) {

	char alpha[] = "......";

	// determine type of ch
	if (isalpha(ch)) {

		if (isupper(ch)) {
			strcpy(braille, ".....0");		// add capital sign
			encode_alpha(ch, alpha);		// encode letter
			strcat(braille, alpha);			// append to braille
		} else {
			encode_alpha(ch, alpha);
			strcpy(braille, alpha);
		}
	}

	if (isdigit(ch)) {
		// add nmber sign
		strcpy(braille, "..0000");

		// convert to char
		ch = ch - '1' + 'a';
		encode_alpha(ch, alpha);
		strcat(braille, alpha);
	}

	if (ispunct(ch)) {
		// encode each individually
		if (ch == '.')
			strcpy(braille, ".0..00");
		if (ch == ',')
			strcpy(braille, ".0....");
		if (ch == ';')
			strcpy(braille, ".00...");
		if (ch == '-')
			strcpy(braille, "..0..0");
		if (ch == '!')
			strcpy(braille, ".00.0.");
		if (ch == '?')
			strcpy(braille, ".00..0");
		if (ch == '(' || ch == ')' )
			strcpy(braille, "..00.00");
	}

	return strlen(braille);
}

// function to encode given alphabetical char to braille
void encode_alpha(char ch, char* braille) {

	ch = tolower(ch);

	switch (ch) {
		case 'a': strcpy(braille, "0....."); break;
		case 'b': strcpy(braille, "00...."); break;
		case 'c': strcpy(braille, "0..0.."); break;		
		case 'd': strcpy(braille, "0..00."); break;
		case 'e': strcpy(braille, "0...0."); break;
		case 'f': strcpy(braille, "00.0.."); break;
		case 'g': strcpy(braille, "00.00."); break;
		case 'h': strcpy(braille, "00..0."); break;
		case 'i': strcpy(braille, ".0.0.."); break;
		case 'j': strcpy(braille, ".0.00."); break;
		case 'k': strcpy(braille, "0.0..."); break;
		case 'l': strcpy(braille, "000..."); break;
		case 'm': strcpy(braille, "0.00.."); break;
		case 'n': strcpy(braille, "0.000."); break;		
		case 'o': strcpy(braille, "0.0.0."); break;
		case 'p': strcpy(braille, "0000.."); break;
		case 'q': strcpy(braille, "00000."); break;
		case 'r': strcpy(braille, "000.0."); break;
		case 's': strcpy(braille, ".000.."); break;
		case 't': strcpy(braille, ".0000."); break;
		case 'u': strcpy(braille, "0.0..0"); break;
		case 'v': strcpy(braille, "000..0"); break;
		case 'w': strcpy(braille, ".0.000"); break;
		case 'x': strcpy(braille, "0.00.0"); break;
		case 'y': strcpy(braille, "0.0000"); break;
		case 'z': strcpy(braille, "0.0.00"); break;
		default: strcpy(braille, "ERROR"); break;
	}
}

// function to encode string of text to braille (iterative)
void encode(const char* text, char* braille) {

	char buffer[] = "............";
		
	for (int i = 0; i < strlen(text); i++) {
		encode_character(text[i], buffer);
		i == 0 ? (strcpy(braille, buffer)) : strcat(braille, buffer);
	}
}

// function to encode string of text to braille (recursive)
// doesn't 'clear' braille though...
void encodeR(const char* text, char* braille) {

	char buffer[] = "............";
	// const char* pass = &text[0];
	// cout << pass << endl;
	// cout << (int*)&text[0] << " ";

	// // if starting
	// if ((int*)&text[0] == (int*)&text[0]) {
	// 	cout << "resetting braille" << endl;
	// 	braille[0] = '\0';
	// }

	if (text[0]) {
		encode_character(text[0], buffer);
		if (braille[0] == '\0') {
			strcpy(braille, buffer);
		} else {
			strcat(braille, buffer);
		}
		encodeR(&text[1], braille);
	}
}

// bool encodeR(const char* text, char* braille) {

// 	if (text[0] == '\0')
// 		return true;

// 	char buffer[13];

// 	encode_character(text[0], buffer);
// 	strcat(braille, buffer);

// 	if (encodeR(text+1, braille))
// 		return true;

// 	return false;
// }


// function to print braille to output stream
void print_braille(const char* text, ostream& out) {
	// store braille encoding in buffer
	char braille[512];
	encode(text, braille);

	// print braille for each row
	for (int row = 0; row < 3; row++)
		print_row(braille, row, out);

	// print plain text
	for (int i = 0; i < strlen(text); i++) {
		if (isupper(text[i]) || isdigit(text[i]))
			out << "   ";
		out << text[i] << "  "; 
	}

	out << endl;
}

// function to print row of braille encoding
void print_row(const char* braille, int row, ostream& o) {
	
	int it = row;
	while(it < strlen(braille)) {
		o << braille[it];
		it = it + 3;
		o << braille[it] << " ";
		it = it + 3;
	}
	o << endl;
}

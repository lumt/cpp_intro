#include "piglatin.h"

using namespace std;

// function to find first occurence of vowel
int findFirstVowel(const char* word) {
	for (int i = 0; i < strlen(word); i++)
		if (isVowel(word[i]))
			if (!((i == 0 || i == strlen(word)-1) &&
				tolower(word[i]) == 'y'))
				return i;
	return -1;
}

// checks if is vowel
bool isVowel(char ch) {
	
	ch = tolower(ch);
	if (ch == 'a' ||
		ch == 'e' ||
		ch == 'i' ||
		ch == 'o' ||
		ch == 'u' ||
		ch == 'y')
		return true;

	return false;
}


// function to translate english word into pig latin
void translateWord(const char* english, char* piglatin) {

	int vowelPos = findFirstVowel(english);

	// make a copy
	char engCopy[strlen(english)+1];
	strcpy(engCopy, english);

	// check if last char is punct
	char punctEnd = '\0';
	if (ispunct(engCopy[strlen(engCopy)-1])) {
		// store it
		punctEnd = engCopy[strlen(engCopy)-1];
		engCopy[strlen(engCopy)-1] = '\0';
	}
	
	if (vowelPos == 0) {
		// if begins with a vowel, add way to it
		strcpy(piglatin, engCopy);
		strcat(piglatin, "way");

	} else if (vowelPos > 0) {
		// does not begin with vowel
		// copy substring using strncpy
		int len = strlen(engCopy) - vowelPos;
		strncpy(piglatin, engCopy + vowelPos, len);
		piglatin[len] = '\0';

		// store front part of word
		char buffer[100];
		strncpy(buffer, engCopy, vowelPos);
		buffer[vowelPos] = '\0';

		// cat front of it
		strcat(piglatin, buffer);
		strcat(piglatin, "ay");
	} else {
		// contains no vowels
		strcpy(piglatin, engCopy);
		if (isalpha(engCopy[0]))
			strcat(piglatin, "ay");
	}

	int strlenPig = strlen(piglatin);

	// capitalize and lower rest
	if (isupper(engCopy[0])) {
		piglatin[0] = toupper(piglatin[0]);
		for (int i = 1; i < strlenPig; i++)
			piglatin[i] = tolower(piglatin[i]);
	}

	// restore punctuation
	if (punctEnd) {
		piglatin[strlenPig] = punctEnd;
		piglatin[strlenPig+1] = '\0';
	}
}

// recursive version
void translateStream(istream& in, ostream& out) {

	char english[65], piglatin[65];
	char ch;

	if (in.get(ch)) {

		if (isalnum(ch)) {
			in.putback(ch);
			in >> english;
			translateWord(english, piglatin);
			out << piglatin;
		} else {
			out << ch;
		}

		translateStream(in, out);
	} else {
		out << endl;
	}
}

// iterative version
// void translateStream(istream& in, ostream& out) {
// 	char english[65], piglatin[65];
// 	char ch;
// 	while (in.get(ch)) {
// 		if (isalnum(ch)) {
// 			in.putback(ch);
// 			in >> english;
// 			translateWord(english, piglatin);
// 			out << piglatin;
// 		} else {
// 			out << ch;
// 		}
// 	}
// 	out << endl;
// }


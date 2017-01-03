#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include <map>
#include <string>
#include <fstream>

using namespace std;

#include "sonnet.h"

/* PRE-SUPPLIED HELPER FUNCTIONS START HERE */

/* NOTE: It is much more important to understand the interface to and
	 the "black-box" operation of these functions (in terms of inputs and
	 outputs) than it is to understand the details of their inner working. */

/* get_word(...) retrieves a word from the input string input_line
	 based on its word number. If the word number is valid, the function
	 places an uppercase version of the word in the output parameter
	 output_word, and the function returns true. Otherwise the function
	 returns false. */

bool get_word(const char *input_line, int word_number, char *output_word) {
	char *output_start = output_word;
	int words = 0;

	if (word_number < 1) {
		*output_word = '\0';
		return false;
	}
	
	do {
		while (*input_line && !isalnum(*input_line))
			input_line++;

		if (*input_line == '\0')
			break;

		output_word = output_start;
		while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
			*output_word = toupper(*input_line);
			output_word++;
			input_line++;
		}
		*output_word = '\0';

		if (++words == word_number)
			return true;

	} while (*input_line);

	*output_start = '\0';
	return false;
}

/* char rhyming_letter(const char *ending) generates the rhyme scheme
	 letter (starting with 'a') that corresponds to a given line ending
	 (specified as the parameter). The function remembers its state
	 between calls using an internal lookup table, such that subsequents
	 calls with different endings will generate new letters.  The state
	 can be reset (e.g. to start issuing rhyme scheme letters for a new
	 poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending) {

	// the next rhyming letter to be issued (persists between calls)
	static char next = 'a';
	// the table which maps endings to letters (persists between calls)
	static map<string, char> lookup;

	// providing a way to reset the table between poems
	if (ending == RESET) {
		lookup.clear();
		next = 'a';
		return '\0';
	}

	string end(ending);

	// if the ending doesn't exist, add it, and issue a new letter
	if (lookup.count(end) == 0) {
		lookup[end]=next;
		assert(next <= 'z');
		return next++;
	}

	// otherwise return the letter corresponding to the existing ending
	return lookup[end];
}

/* START WRITING YOUR FUNCTION BODIES HERE */

// function to count words given in string line
int count_words(const char* line) {
	int count = 1;
	char wordbuffer[100];

	while(get_word(line, count, wordbuffer))
		count++;

	return count - 1;
}

// function to find phonetic ending and puts in 'ending'
// constructed by concatenating last phoneme of the word
// which contains a vowel
bool find_phonetic_ending(const char *word, char *ending) {

	ifstream in("dictionary.txt");
	if (!in) {
		cerr << "dictionary.txt failed to load" << endl;
		return false;
	}

	// assumes length of line and wordbuffer
	char line[200], wordbuffer[50];

	// uses linear search so may take some time
	while(in.getline(line, 200)) {
		// gets first word in line and store in wordbuffer
		get_word(line, 1, wordbuffer);

		// compare buffer to word
		if (!strcmp(wordbuffer, word)) {
			// count words given in string line
			int linecount = count_words(line);

			// find first phoneme of word starting with vowel
			int idx = linecount;
			while(get_word(line, idx, wordbuffer)) {
				if (isVowel(wordbuffer[0])) {
					strcpy(ending, wordbuffer);
					idx++;

					// concat the rest
					while(get_word(line, idx, wordbuffer)) {
						strcat(ending, wordbuffer);
						idx++;
					}
					break;
				} else {
					idx--;
				}
			}
			break;
		}
	}
	in.close();
	return false;
}

// helper function to check if character is a vowel
bool isVowel(char ch) {
	ch = tolower(ch);
	switch(ch) {
		case 'a': 
		case 'e': 
		case 'i': 
		case 'o': 
		case 'u': return true;
		default: return false;
	}
}


// function to find rhyme scheme of given sonnet
bool find_rhyme_scheme(const char* filename, char* scheme) {
	
	ifstream in(filename);
	if (!in) {
		cerr << filename << " could not be opened" << endl;
		return false;
	}

	char line[200], word[50], ending[20], letter[2];
	letter[1] = '\0';
	int linecount;

	// reset rhyme sceme
	rhyming_letter(RESET);
	strcpy(scheme, "\0");

	while(in.getline(line, 200)) {
		// get last word and get ending
		linecount = count_words(line);
		get_word(line, linecount, word);
		find_phonetic_ending(word, ending);
		letter[0] = rhyming_letter(ending);
		strcat(scheme, letter);	
	}

	in.close();
	if (scheme)
		return true;
	return false;
}


char* identify_sonnet(const char* filename) {
	char* type = new char[20];
	char scheme[20];
	strcpy(type, "Unknown");

	if (find_rhyme_scheme(filename, scheme)) {
		if (strcmp(scheme, "ababcdcdefefgg") == 0)
			strcpy(type, "Shakespearean");
		if (strcmp(scheme, "abbaabbacdcdcd") == 0)
			strcpy(type, "Petrarchan");
		if (strcmp(scheme, "ababbcbccdcdee") == 0)
			strcpy(type, "Spenserian");
		return type;
	}

	return type;
}




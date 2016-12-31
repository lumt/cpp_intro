#include <iostream>
#include <cctype>
#include "soundex.h"

using namespace std;


// func to encode surname into soundex coding system
void encode(const char* surname, char* soundex){
	// First letter
	soundex[0] = surname[0];

	// iterators
	int surname_it = 1, soundex_it = 1;

	while (surname[surname_it] != '\0' && soundex_it < 4)
	{
		if (letterIn(surname[surname_it], "bfpv")) {
			if (soundex[soundex_it -1] != '1') {
				soundex[soundex_it] = '1';
				soundex_it++;
			}
		} else if (letterIn(surname[surname_it], "cgjkqsxz")) {
			if (soundex[soundex_it -1] != '2') {
				soundex[soundex_it] = '2';
				soundex_it++;
			}
		} else if (letterIn(surname[surname_it], "dt")) {
			if (soundex[soundex_it -1] != '3') {
				soundex[soundex_it] = '3';
				soundex_it++;
			}
		} else if (surname[surname_it]== 'l') {
			if (soundex[soundex_it -1] != '4') {
				soundex[soundex_it] = '4';
				soundex_it++;
			}
		} else if (letterIn(surname[surname_it], "mn")) {
			if (soundex[soundex_it -1] != '5') {
				soundex[soundex_it] = '5';
				soundex_it++;
			}
		} else if (surname[surname_it]== 'l') {
			if (soundex[soundex_it -1] != '6') {
				soundex[soundex_it] = '6';
				soundex_it++;
			}
		}

		surname_it++;
	}

	while (soundex_it < 4) {
		soundex[soundex_it] = '0';
		soundex_it++;
	}

	soundex[4] = '\0';

}

// returns true if char letter within string "phrase"
bool letterIn(const char letter, const char* phrase) {
	int it = 0;
	while (phrase[it] != '\0') {
		if (letter == phrase[it])
			return true;
		it++;
	}
	return false;
}

int compare(const char* s1, const char* s2){
	// assumes only valid soundex code passed in
	if (strcmp(s1, "") == 0 && strcmp(s2, "") == 0)
		return 1;

	// recursive case, if same char
	if (s1[0] == s2[0])
		return compare(&s1[1], &s2[1]);		// pass from [1] onwards

	// if first char is different
	return 0;
}

// function to count number of same soundex occurences
// int count(const char* surname, const char* sentence)
// {
// 	int count = 0, sen_ptr = 0, buffer_ptr = 0;
// 	char name_buffer[25], soundex[5], buffer_soundex[5];
// 	bool copying = false;

// 	// encode original
// 	encode(surname, soundex);

// 	while(sentence[sen_ptr] != '\0') {
// 		// if name, starts with uppercase letter
// 		if(isupper(sentence[sen_ptr]) && !copying) {
// 			// copy name into name_buffer
// 			buffer_ptr = 0;
// 			name_buffer[buffer_ptr] = sentence[sen_ptr];
// 			buffer_ptr++;
// 			copying = true;
// 		} else if (copying) {
// 			// continue copying if alpha
// 			if (isalpha(sentence[sen_ptr])) {
// 				name_buffer[buffer_ptr] = sentence[sen_ptr];
// 				buffer_ptr++;
// 			} else {
// 				// word ending
// 				// stop copying and compare
// 				name_buffer[buffer_ptr] = '\0';
// 				copying = false;
// 				encode(name_buffer, buffer_soundex);
// 				if (compare(soundex, buffer_soundex))
// 					count++;
// 			}
// 		}

// 		sen_ptr++;
// 	}

// 	return count;
// }


// same function using strtok
int count(const char* surname, const char* sentence) {
	char sentence_cpy[100], *sptr, soundex[5], soundex_buffer[5];
	int count = 0;

	// creates copy of the sentence
	strcpy(sentence_cpy, sentence);
	// encode given surname
	encode(surname, soundex);

	// iterates and splits string into tokens
	for (sptr = strtok(sentence_cpy, ", .!"); sptr != NULL; sptr = strtok(NULL, ", .!")) {
		encode(sptr, soundex_buffer);
		if (compare(soundex, soundex_buffer))
			count++;
	}

	return count;
}






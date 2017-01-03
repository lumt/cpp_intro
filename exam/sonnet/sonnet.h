#ifndef SONNET_H
#define SONNET_H

// RESET is a constant used by function rhyming_letter(...)
#define RESET NULL

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int number, char *output_word);

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending);

/* Own function starts here */

// function to count words given in a given input string line
int count_words(const char* line);

bool find_phonetic_ending(const char *word, char *ending);

bool isVowel(char ch);

bool find_rhyme_scheme(const char* filename, char* scheme);

char* identify_sonnet(const char* filename);


#endif

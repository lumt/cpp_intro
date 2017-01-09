#include <iostream>
#include "words.h"

using namespace std;

void reverse(const char* word, char* rev) {

	int length = strlen(word);

	for(int i = 0; i <= length; i++)
		rev[i] = word[length - 1 - i];

	rev[length] = '\0';
}


int compare(const char* str1, const char* str2) {
	// base case, both strings have ended
	if (strcmp(str1, "") == 0 && strcmp(str2, "") == 0) {
		return 1;
	}

	if (str1[0]) {
		if (str2[0]) {
			if (isalpha(str1[0]) && isalpha(str2[0])) {
				// both are alphas
				if (toupper(str1[0]) == toupper(str2[0]))
					return compare(&str1[1], &str2[1]);
				else
					return 0;
			} else {
				// not both are alpha
				if (isalpha(str1[0])) {
					if (!isalpha(str2[0]))
						return compare(&str1[0], &str2[1]);
				} else {
					if (isalpha(str2[0]))
						return compare(&str1[1], &str2[0]);
					else
						return compare(&str1[1], &str2[1]);
				}
			}
		} else {
			// string2 has ended
			if (isalpha(str1[0]))
				return 0;
			else
				return compare(&str1[1], "");
		}
	} else {
		// string1 has ended but not str2
		if (str2[0]) {
			if (isalpha(str2[0]))
				return 0;
			else
				return compare("", &str2[1]);
		}
	}

	return 0;
}


int palindrome(const char* sentence) {
	char buffer[strlen(sentence)+1];
	reverse(sentence,buffer);
	return compare(sentence, buffer);
}


int anagram(const char* str1, const char* str2) {
	// make copies of each
	char str1_cpy[strlen(str1)+1], str2_cpy[strlen(str2)+1];
	strcpy(str1_cpy, str1);
	strcpy(str2_cpy, str2);
		
	// sort both
	selSort(str1_cpy);
	selSort(str2_cpy);

	// do the magic
	if (compare(str1_cpy, str2_cpy))
		return 1;
	else
		return 0;
}

// function to implement selection sort
void selSort(char* str) {

	char temp;
	int i, j, n = strlen(str);
	int currentMin;

	// convert all to upper case
	for (i = 0; i < n; i++) {
		str[i] = toupper(str[i]);
	}

	// selection sort algorithmm
	for (i = 0; i < n - 1; i++) {
		currentMin = i;

		for (j = i + 1; j < n; j++) {
			if (str[j] < str[currentMin])
				currentMin = j;
		}

		// swap places
		if (str[currentMin] != str[i]) {
			temp = str[i];
			str[i] = str[currentMin];
			str[currentMin] = temp;
		}
	}
}
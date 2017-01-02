#include <cctype>
#include <cstring>
#include "multitap.h"

// function to produce multitap encoding of given character
int encode_character(char ch, char* multitap) {

	if (isalpha(ch)) {
		ch = tolower(ch);
		switch(ch) {
			case 'a': strcpy(multitap, "2"); break;
			case 'b': strcpy(multitap, "22"); break;
			case 'c': strcpy(multitap, "222"); break;
			case 'd': strcpy(multitap, "3"); break;
			case 'e': strcpy(multitap, "33"); break;
			case 'f': strcpy(multitap, "333"); break;			
			case 'g': strcpy(multitap, "4"); break;
			case 'h': strcpy(multitap, "44"); break;
			case 'i': strcpy(multitap, "444"); break;
			case 'j': strcpy(multitap, "5"); break;
			case 'k': strcpy(multitap, "55"); break;
			case 'l': strcpy(multitap, "555"); break;
			case 'm': strcpy(multitap, "6"); break;
			case 'n': strcpy(multitap, "66"); break;
			case 'o': strcpy(multitap, "666"); break;
			case 'p': strcpy(multitap, "7"); break;
			case 'q': strcpy(multitap, "77"); break;
			case 'r': strcpy(multitap, "777"); break;			
			case 's': strcpy(multitap, "7777"); break;
			case 't': strcpy(multitap, "8"); break;
			case 'u': strcpy(multitap, "88"); break;
			case 'v': strcpy(multitap, "888"); break;
			case 'w': strcpy(multitap, "9"); break;			
			case 'x': strcpy(multitap, "99"); break;
			case 'y': strcpy(multitap, "999"); break;
			case 'z': strcpy(multitap, "9999"); break;
		}
	}

	// if number
	if (isdigit(ch)) {
		strcpy(multitap, "*");
		multitap[1] = ch;
		multitap[2] = '\0';
	}

	// if punctuation
	if (ispunct(ch)) {
		if (ch == '.')
			strcpy(multitap, "1");
		if (ch == ',')
			strcpy(multitap, "11");
		if (ch == '!')
			strcpy(multitap, "111");
		if (ch == '?')
			strcpy(multitap, "1111");
	}

	// if space
	if (ch == ' ') {
		multitap[0] = '0';
		multitap[1] = '\0';
	}

	return strlen(multitap);
}


// function to encode plaintext as multitap
void encode(const char* text, char* multitap) {
	
	int multilen;
	char buffer[4+1];
	bool capslock = false;

	// check upper case
	if (isupper(text[0])) {
		strcpy(multitap, "#");
		capslock = true;
	}

	// encode first character
	encode_character(text[0], buffer);
	strcat(multitap, buffer);

	// encode rest
	for (int i = 1, n = strlen(text); i < n; i++) {

		encode_character(text[i], buffer);

		// check if upper and capslock off
		if (isupper(text[i]) && !capslock) {
			strcat(multitap, "#");
			capslock = true;
		}
		// check if lower and capslock on
		if (islower(text[i]) && capslock) {
			strcat(multitap, "#");
			capslock = false;
		}

		// check previous & add pipe character for pause
		multilen = strlen(multitap);
		if (buffer[0] == multitap[multilen - 1])
			strcat(multitap, "|");

		strcat(multitap, buffer);
	}
}

// function to decode single character
char decode_character(const char* multitap) {

	char buffer[4+1];
	// try all ch and if multicode match return ch
	for (int i = 'a'; i <= 'z'; i++) {
		encode_character((char) i, buffer);
		if (strcmp(buffer, multitap) == 0) {
			return (char) i;
		}
	}

	// punct
	if (strcmp("1", multitap) == 0)
		return '.';
	if (strcmp("11", multitap) == 0)
		return ',';
	if (strcmp("111", multitap) == 0)
		return '!';
	if (strcmp("1111", multitap) == 0)
		return '?';
	if (strcmp("0", multitap) == 0)
		return ' ';

	return '$';
}

void print_decode(const char* buffer, ostream& out, bool caps) {
	char ch = decode_character(buffer);

	if (isalpha(ch) && caps)
		ch = toupper(ch);
	out << ch;
}

// function to decode message from given istream to ostream
// assumes no digit (ie no *)
void decode(istream& in, ostream& out) {
	
	char ch, decoded, buffer[4+1];
	bool capslock = false;
	int buflen;
	buffer[0] = '\0';

	while (!in.eof()) {
		in.get(ch);
		// check if capslock # (word ended)
		if (ch == '#') {

			if (buffer[0]) {
				print_decode(buffer, out, capslock);
			}
			buffer[0] = '\0';
			if (capslock) {
				capslock = false;
			}
			else {
				capslock = true;
			}
			continue;
		}

		// check if pause character (word ended)
		if (ch == '|') {
			print_decode(buffer, out, capslock);
			buffer[0] = '\0';
			continue;
		}

		if (ch == '*') {
			in.get(ch);
			print_decode(buffer, out, capslock);
			out << ch;
			buffer[0] = '\0';
			continue;
		}

		// store buffer only if num
		if (isdigit(ch)) {
			// out << ch << " " ;
			buflen = strlen(buffer);

			if (buflen == 0) {
				buffer[0] = ch;
				buffer[1] = '\0';
			} else if (ch == buffer[buflen -1]) {
				buffer[buflen] = ch;
				buffer[buflen + 1] = '\0';
			} else {
				print_decode(buffer, out, capslock);
				buffer[0] = ch;
				buffer[1] = '\0';
			}
		}

	}
	// last word
	buflen = strlen(buffer);
	if (buflen > 1)
		buffer[buflen-1] = '\0';
	print_decode(buffer, out, capslock);

	cout << endl;
}
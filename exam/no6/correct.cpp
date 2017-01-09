#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary) {
	for (int n = 128; n; n >>= 1) 
		*binary++ = (ch & n) ? '1' : '0';
	*binary = '\0';
}

char binary_to_ascii(char *binary) {
	int ch = 0;
	for (int n=0, slide=128; n<8; n++, slide >>= 1) {
		if (binary[n] == '1')
			ch = ch | slide;
	}
	return ch;
}

/* now add your own functions here */

// function to convert text str to binary
void text_to_binary(const char* str, char* binary) {

	char buffer[8 + 1];
	ascii_to_binary(str[0], buffer);
	strcpy(binary, buffer);

	for (int i = 1, n = strlen(str); i < n; i++) {
		ascii_to_binary(str[i], buffer);
		strcat(binary, buffer);
	}
}

// function to convert binary to text str (recursive)
// this function does not 'clear' str array
// void binary_to_text(const char* binary, char* str) {

// 	char buffer[8 + 1], ch;

// 	// if there are binary
// 	if (binary[0]) {
// 		strncpy(buffer, binary, 8);
// 		ch = binary_to_ascii(buffer);
		
// 		// if just started
// 		if (str[0] == '\0') {
// 			str[0] = ch;
// 		} else {
// 			int len = strlen(str);
// 			str[len] = ch;
// 			str[len + 1] = '\0';
// 		}

// 		binary_to_text(&binary[8], str);
// 	}
// }

// function to convert binary to text str (iterative)
void binary_to_text(const char* binary, char* str) {

	char buffer[8 + 1], ch;
	strncpy(buffer, binary, 8);
	ch = binary_to_ascii(buffer);
	str[0] = ch;
	str[1] = '\0';

	for (int i = 1, n = strlen(binary)/8; i < n; i++) {
		strncpy(buffer, binary + (i*8), 8);
		ch = binary_to_ascii(buffer);
		int len = strlen(str);
		str[len] = ch;
		str[len+1] = '\0';
	}
}

// function to convert binary to corrected parity format
void add_error_correction(const char* binary, char* corrected) {
	
	char bit_buffer[4 + 1];
	char err_corrected[7 + 1];
	int c;
	// c1, c2, d1, c3, d2, d3, d4;

	for (int i = 0, n = strlen(binary)/4 ; i < n; i++) {
		strncpy(bit_buffer, binary + (i * 4), 4);

		// calculate c1
		c = bit_buffer[0] + bit_buffer[1] + bit_buffer[3];
		c % 2 == 0 ? c = 0 : c = 1;
		err_corrected[0] = c + '0';		// c1

		// c2
		c = bit_buffer[0] + bit_buffer[2] + bit_buffer[3];
		c % 2 == 0 ? c = 0 : c = 1;
		err_corrected[1] = c + '0';		// c2

		// c3
		c = bit_buffer[1] + bit_buffer[2] + bit_buffer[3];
		c % 2 == 0 ? c = 0 : c = 1;
		err_corrected[3] = c + '0';		// c3

		// fill in digit bits
		err_corrected[2] = bit_buffer[0]; 		// d1
		err_corrected[4] = bit_buffer[1];		// d2
		err_corrected[5] = bit_buffer[2];		// d3
		err_corrected[6] = bit_buffer[3];		// d4
		err_corrected[7] = '\0';

		if (i == 0)
			strcpy(corrected, err_corrected);
		else
			strcat(corrected, err_corrected);
	}
}


// function to decode received message
int decode(const char* received, char* decoded) {

	char buffer[7 + 1];
	char extract[4 + 1];	// b3, b5, b6, b7
	int p1, p2, p3, errors = 0;

	for (int i = 0, n = strlen(received)/7; i < n; i++) {
		strncpy(buffer, received + (i*7), 7);
		buffer[7] = '\0';

		// p1
		p1 = buffer[3] + buffer[4] + buffer[5] + buffer[6];
		p1 % 2 == 0? p1 = 0 : p1 = 1;

		// p2
		p2 = buffer[1] + buffer[2] + buffer[5] + buffer[6];
		p2 % 2 == 0? p2 = 0 : p2 = 1;

		// p3
		p3 = buffer[0] + buffer[2] + buffer[4] + buffer[6];
		p3 % 2 == 0? p3 = 0 : p3 = 1;

		// error found
		if (!(p1 == 0 && p2 == 0 && p3 == 0)) {
			// increase error count and flip
			errors++;
			int flip = p1 * 4 + p2 * 2 + p3;
			if (buffer[flip-1] == '1')
				buffer[flip-1] = '0';
			else
				buffer[flip-1] = '1';
		}

		// get extracted bits
		extract[0] = buffer[2];		// b3
		extract[1] = buffer[4];		// b5
		extract[2] = buffer[5];		// b6
		extract[3] = buffer[6];		// b7
		extract[4] = '\0';

		// decode extract to 4 bit
		if (i == 0)
			strcpy(decoded, extract);
		else
			strcat(decoded, extract);
	}

	return errors;
}

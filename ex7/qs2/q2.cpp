/* write boolean function
 * returns true if first string argument is alphabetically smaller
 * than its second string argument
 * lower case only
 * no blanks or funny characters
 * then convert to pointer arithmetic
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 50;

bool string_smaller(char string1[], char string2[]);
bool string_smaller2(char *string1, char *string2);


int main()
{
	char string1[MAX];
	char string2[MAX];

	// prompt string 1
	cout << "Enter first word: ";
	cin >> string1;
	cout << endl;

	// prompt string 2
	cout << "Enter second word: ";
	cin >> string2;
	cout << endl;

	// call function
	cout << "Normal function call: " << endl;
	cout << string1 << " is ";
	if (!string_smaller(string1, string2)) {
		// if string1 not smaller prints not;
		cout << "not ";
	}
	cout << "smaller than " << string2 << ".";
	cout << endl << endl;

	// call function pointer
	cout << "Pointer arithmetic function: " << endl;
	cout << string1 << " is ";
	if (!string_smaller2(string1, string2)) {
		// if string1 not smaller prints not;
		cout << "not ";
	}
	cout << "smaller than " << string2 << ".";
	cout << endl << endl;


	return 0;
}

bool string_smaller(char string1[], char string2[])
{
	int count = 0;

	while (string1[count] != '\0' && string2[count] != '\0') {
		if (string1[count] < string2[count])
			return true;
		else
			return false;
		count++;
	}

	if (string1[0] == '\0' && string2[count] != '\0')
		return true;
	else
		return false;
}

bool string_smaller2(char *string1, char *string2)
{
	int count = 0;

	while (*string1 != '\0' && *string2 != '\0') {
		if (*(string1 + count) < *(string2 + count))
			return true;
		else
			return false;
		count++;
	}

	if (*string1 == '\0' && *string2 != '\0')
		return true;
	else
		return false;
}

/* this program prints out the number of occurences
 * of characters between lower-case 'a' to 'z'
 * in this source code file.
 * Constraints:
 * one ifstream
 * one char
 * two int
 */

#include <iostream>
#include <fstream>

using namespace std;

/* FUNCTION PROTOTYPES */
void print_header();
int run_file(int character);


/* START MAIN */
int main()
{
	int character;

	print_header();

	for (character = 97 ; character <= 122; character++)
	{
		cout.width(17);
		cout << static_cast<char>(character);
		cout << run_file(character) << endl;
	}
	cout << endl;

	return 0;
}
/* END MAIN */

/* FUNCTION TO PRINT PROMPT AND HEADER */
void print_header()
{
	cout << "This program prints out blah blah zxc" << endl;

	cout.width(17);
	cout.setf(ios::left);
	cout << "CHARACTERS";
	cout << "OCCURENCES" << endl << endl;
}

/* FUNCTION TO OPEN FILE AND COUNT CURRENT CHARACTER */
int run_file(int character)
{
	ifstream input;
	input.open("q5.cpp");

	char buffer;
	int counter = 0;

	input.get(buffer);
	while (!input.eof())
	{
		if (buffer == static_cast<char>(character))
			counter++;
		input.get(buffer);
	}

	input.close();
	return counter;
}

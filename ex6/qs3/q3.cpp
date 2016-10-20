/* write no_reps(..)
 * which removes all repititions of chars
 * from a string
 * easy
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 50;

void no_reps(const char array[], int size, char result[]);
bool unique(char character, char result[], int resultsize);

int main()
{
	char string[MAX];   // input string
	char result[MAX];   // output string

	// 1 prompt
	cout << "Type in a string: ";
	cin.getline(string, MAX);

	// 2 call function no_reps()
	no_reps(string, strlen(string), result);

	// 3 ???
	cout << "String with no reps: ";
	cout << result << endl << endl;

	// 4 profit
	return 0;
}


/* function to 'remove' duplicates from input string */
void no_reps(const char array[], int size, char result[])
{
	int resultsize = 0;

	cout << result << endl;
	for (int count = 0; count < size; count++)
		if (unique(array[count], result, resultsize)) {
			result[resultsize] = array[count];
			result[resultsize + 1] = '\0';
			resultsize++;
		}
	cout << endl;
}

/* Function to check if character is unique, returns true if yes */
bool unique(char character, char result[], int resultsize)
{
	for (int i = 0; i < resultsize; i++)
		if (character == result[i])
			return false;
	return true;
}

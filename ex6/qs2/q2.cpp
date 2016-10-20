/* adapt selection sort such that
 * it sorts the characters in a string alphabetically
 * but puts all UPPER before lower
 * leave position of sentinel character unchanged.
 */

#include <iostream>
#include <cstring> // getline
using namespace std;

const int SIZE = 60;

/* function prototypes */
void sel_sort(char array[], int size);
void swap(char &first, char &second);
int minimum_from(char array[], int current, int size);


int main()
{
	char string[SIZE];

	cout << "Type in a string: ";
	cin.getline(string, SIZE);
	cout << endl;

	// call function to sort array
	sel_sort(string, strlen(string));

	cout << "Your string is: " << string << endl << endl;

	return 0;
}


void sel_sort(char array[], int size)
{
	for (int i = 0; i < size - 1; i++)
		swap(array[i], array[minimum_from(array, i, size)]);
	cout << "Sorted..." << endl << endl;
}

/* pass in the address of first and second and swaps its values */
void swap(char &first, char &second)
{
	char temp = first;
	first = second;
	second = temp;
}

/* function to calculate minimum value from current positon
 * returns the position of minimum */
int minimum_from(char array[], int current, int size)
{
	int minimum = current;
	// always puts space character in front
	if (array[minimum] == static_cast<char>(32))
		return minimum;

	for (int position = current + 1; position < size; position++)
	{
		if (array[position] == static_cast<char>(32)) {
			minimum = position;
			break;
		} else if (array[position] < array[minimum]) {
			minimum = position;
		}
	}

	return minimum;
}



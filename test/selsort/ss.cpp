/* Asks the user to input integers to an array
 * of size 10. Then sorts the lists
 * in ascending order
 * using selection sort algorithm
 */

#include <iostream>

using namespace std;

const int MAX = 8;
typedef int Array_ofints[MAX];


/* PROTOTYPES */
void print_array(Array_ofints array, int length);
void swap(int& first, int& second);
void sel_sort(Array_ofints array, int length);
int minimum_from(Array_ofints array, int count, int length);




int main()
{
	Array_ofints hi;

	// input array;
	int count;
	for (count = 0; count < MAX; count++)
	{
		cout << "Input int for " << count + 1 << " number: ";
		cin >> hi[count];
	}

	// print array before
	print_array(hi, MAX);

	// sort array call
	sel_sort(hi, MAX);

	// print array after
	print_array(hi, MAX);

	return 0;
}




void print_array(Array_ofints array, int length)
{
	cout << "Your array is: ";
	int count;
	for (count = 0; count < length; count++)
	{
		cout << array[count];
		if (count != length - 1)
			cout << ", ";
	}
	cout << endl;
}

void sel_sort(Array_ofints array, int length)
{
	for (int count = 0; count < length - 1; count++)
		swap(array[count], array[minimum_from(array, count, length)]);

	cout << "Sorted." << endl;
}

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

/* FUNCTION TO RETURN MINIMUM INDEX FROM COUNT */
int minimum_from(Array_ofints array, int count, int length)
{
	int minimum = count;

	for (count = count + 1 ; count < length ; count++)
	{
		if (array[count] < array[minimum])
			minimum = count;
	}
	return minimum;
}


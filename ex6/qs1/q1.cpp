/* This program tests using arrays and functions on arrays
 * which also uses the header files 
 */

#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
	int size;
	float myarray[50], notmyarray[50];

	cout << "This program does funky stuff." << endl;
	cout << "Enter size of array (<10 is good): ";
	cin >> size;

	input_array(myarray, size);
	display_array(myarray, size);

	cout << "Testing copying array..." << endl;
	copy_array(notmyarray, myarray, size);
	display_array(notmyarray, size);

	cout << "Testing maths on your array..." << endl;
	cout << "Average: " << average(myarray, size) << endl;
	cout << "Standard deviation: ";
	cout << standard_deviation(myarray, size) << endl << endl;

	cout << "K thx bye." << endl;

	return 0;
}
#include <iostream>
#include <cmath>
#include "IntegerArray.h"

using namespace std;

/* A function "input_array(a,n)" which allows the user to input values
 for the first n elements of the array a. */
void input_array(float array[], int n)
{
	float input;
	for (int count = 0; count < n; count++)
	{
		cout << "Enter value for element " << count+1 << ": ";
		cin >> input;
		array[count] = input;
	}
	cout << endl;
}

/* A function "display_array(a,n)" which displays the values of the
 first n elements of the array a on the screen. */
void display_array(float array[], int n)
{
	cout << "Values in this array are: " << endl;
	for (int count = 0; count < n; count++)
	{
		cout << array[count];
		if (count != (n-1))
			cout << ", ";
	}
	cout << endl << endl;
}

/* A function "copy_array(a1,a2,n)" which copies the first n elements
 of a2 to the respective first n elements in a1. */
void copy_array(float array1[], float array2[], int n)
{
	for (int count = 0; count < n; count++)
	{
		array1[count] = array2[count];
	}
	cout << "Array copied." << endl << endl;
}


/* a function that calculates the average of the first n elements */
float average(float array[], int n)
{
	float total = 0;
	for (int count = 0 ; count < n ; count++)
		total += float(array[count]);

	return (total / n);
}


/* A function "standard_deviation(a,n)" which returns the standard deviation
 of the first n elements of a. */
float standard_deviation(float array[], int n)
{
	float avg = average(array, n);
	float numerator = 0;
	for (int count = 0; count < n; count++)
		numerator += pow((array[count] - avg), 2);

	return sqrt(numerator/n);
}

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 80;

int main()
{
	char string1[MAX];
	char string2[MAX];

	cout << "Enter first string: ";
	cin.getline(string1, MAX - 1);
	cout << "Enter second string: ";
	cin.getline(string2, MAX - 1);

	cout << "Before copying, the strings were ";
	if (strcmp(string1, string2))
		cout << "not ";
	cout << "the same." << endl;

	strcpy(string1, string2);

	cout << "After copying the strings were";
	if (strcmp(string1, string2))
		cout << "not ";
	cout << "the same." << endl;

	strcat(string1, string2);

	cout << "After concatenating, the string is: ";
	cout << string1 << endl << endl;

	return 0;
}
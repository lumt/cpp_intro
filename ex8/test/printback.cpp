#include <iostream>
using namespace std;

void print_back();

int main()
{
	print_back();
	cout << endl << endl;

	return 0;
}

void print_back()
{
	char character;

	cout << "Enter char, '.' to end: ";
	cin >> character;

	if (character != '.') {
		print_back();
		cout << character;
	}
}
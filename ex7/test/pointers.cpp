#include <iostream>
using namespace std;

int main()
{
	// declares two pointers and two ints
	int *ptr_a, *ptr_b;
	int int_c = 9, int_d = 15;

	ptr_a = &int_c; // assigns pointer using the address-of operator
	ptr_b = &int_d;

	cout << "This prints the address of the pointers: " << endl;
	cout << &ptr_a << endl;
	cout << &ptr_b << endl;	

	cout << "This prints the address stored in the pointers: " << endl;
	cout << ptr_a << "  " << &int_c << endl;
	cout << ptr_b << "  " << &int_d << endl;

	cout << "This prints the variables located at the pointers: " << endl;
	cout << *ptr_a << endl; // dereferencing
	cout << *ptr_b << endl; // aka variable located at addresses pointed to

	ptr_b = ptr_a;

	cout << "Assigned ptr_b = ptr_a" << endl;
	cout << "This prints the address stored in the pointers: " << endl;
	cout << ptr_a << "  " << &int_c << endl;
	cout << ptr_b << "  " << &int_d << endl;

	cout << "This prints the variables located at the pointers: " << endl;
	cout << *ptr_a << endl; // dereferencing
	cout << *ptr_b << endl; // aka variable located at addresses pointed to

	ptr_b = &int_d;
	cout << "changing values of the variables through pointers" << endl;
	*ptr_a = -3; // dereference and assign
	*ptr_b = 1;

	cout << "This prints the variables located at the pointers: " << endl;
	cout << *ptr_a << endl; // dereferencing
	cout << *ptr_b << endl; // aka variable located at addresses pointed to


	return 0;	
}
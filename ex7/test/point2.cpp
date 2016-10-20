#include <iostream>
using namespace std;

//typedef int *IntPtr;

void assign_new_int(int* &ptr);

int main()
{
	int *ptr_a = NULL;

	// passing in the memory address stored under ptr_a
	assign_new_int(ptr_a);

	cout << "AFTER TRIP: " << endl;
	cout << ptr_a << endl;
	*ptr_a = 7;

	cout << "AFTER ASSIGN: " << endl;
	cout << ptr_a << "   ";
	cout << *ptr_a << endl;

	return 0;	
}

// function to dynamically assign int memory to pointer passed in
void assign_new_int(int* &ptr) 
{
	cout << "I GOT HERE" << endl;
	cout << ptr << endl;
	try {
		ptr = new int;
	} catch (bad_alloc) {
		cout << "didnt work";
		return;
	}
}
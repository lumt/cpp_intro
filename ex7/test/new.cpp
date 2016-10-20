/* Program 7.1.5 from C++ Programming Lecture notes  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 28th September 2013    */

/* This program all further illustrates the use of "NULL",
   and of passing pointer variables as parameters to functions. */ 

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int *IntPtrType; 

/* Function to initialise the pointer "ptr" 
to a new dynamic variable, or report a memory 
error and terminate the program */ 
void assign_new_int(IntPtrType &ptr);

/* START OF MAIN PROGRAM */
int main()
{
	IntPtrType ptr_a, ptr_b;

	assign_new_int(ptr_a);
	*ptr_a = 4;
	ptr_b = ptr_a;
		
	cout << *ptr_a << " " << *ptr_b << "\n";
	
	assign_new_int(ptr_b);
	*ptr_b = 7;
	
	cout << *ptr_a << " " << *ptr_b << "\n";

	*ptr_a = *ptr_b;
		
	cout << *ptr_a << " " << *ptr_b << "\n";
	
	delete ptr_a;
	ptr_a = NULL;
	ptr_b = NULL;
	
	if (ptr_a != NULL)
	{
		*ptr_a = 40;
		cout << "*ptr_a == " << *ptr_a;
	}
	else
	{
		cout << "Dangling pointer error - program terminated\n";
		exit(1);
	}
		
	return 0;
}
/* END OF MAIN PROGRAM */

/* START OF DEFINITION OF FUNCTION new_int */
void assign_new_int(IntPtrType &ptr)
{
        ptr = new (nothrow) int;
	if (ptr == NULL)
	{
		cout << "Sorry, ran out of memory";
		exit(1);
	}
}
/* END OF FUNCTION DEFINITION */
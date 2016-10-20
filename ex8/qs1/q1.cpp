/* write a function that
 * computes the fibonacci number
 * recursivly
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int fib(int n);

int main()
{
	int n;

	cout << endl;
	cout << "Calculates the nth term for the fibonacci sequence." << endl;
	cout << "nth term = ";
	cin >> n;
	cout << endl;

	cout << "Fib(" << n << ") = " << fib(n) << endl << endl;

	return 0;
}

int fib(int n)
{
	if (n <= 0) {
		cout << "can't calculate zero or negative numbers" << endl;
		exit(1);
	}

	if (n == 1 || n == 2) {
		return 1;
	} else {
		return fib(n-1) + fib(n-2);
	}
}
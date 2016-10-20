/* given two postive ints n, m
 * n > m
 * gcd of m and n = gcd of m and (n-m)
 * write a recursive function gcd
 * to return the greatest common divisor
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int gcd (int n, int m);

int main()
{
	int n, m;
	cout << "input n: ";
	cin >> n;
	cout << "input m: ";
	cin >> m;

	cout << "result = " << gcd(n, m);
	cout << endl << endl;
	return 0;
}

int gcd (int n, int m)
{
	if (n == m)
		return n;
	else if (n > m)
		return gcd(n-m, m);
	else if (m > n)
		return gcd(m-n, n);
	else {
		cout << "invalid entry.";
		exit(1);
	}
}
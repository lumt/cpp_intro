/* This program raises any number x to a positive power n
 * using a for loop
 */

#include <iostream>

using namespace std;

int main()
{
  int x, n;

  cout << "Input a number: ";
  cin >> x;

  cout << "Raise " << x << " to the power of: ";
  cin >> n;

  if (n == 0){
    cout << "Answer = 1" << endl;
    return 0;
  }

  int i, result = 1;
  
  for (i = 1; i <= n; i++) {
    result *= x;
  }

  cout << "Answer = " << result << endl;
  return 0;
}

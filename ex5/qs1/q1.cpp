/* write a logical valued func which takes 
 * a single int parameter and
 * returns Tru IFF prime and between 1 and 1000
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int x);

int main()
{
  int x;
  cout << "input number: ";
  cin >> x;
  isprime(x);
  return 0;
}

bool isprime(int x) {
  if (x > 1000 || x < 2){
    cout << "value too large" << endl;
    return false;
  }

  int num = 2;
  for (num = 2; num < sqrt(x) + 1 ; num++) {
    if (x % num == 0) {
      cout << "not prime" << endl;
      return false;
    }
  }

  cout << "prime it is" << endl;
  return true;
}

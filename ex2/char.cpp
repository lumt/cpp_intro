/* This program reads in a char from the keyboard,
 * then displays if lower, prints upper
 * if upper, prints lower, 
 * if not a letter, prints error msg
 */

#include <iostream>
using namespace std;

const int UA = 'A';
const int UZ = 'Z';
const int LA = 'a';
const int LZ = 'z';

int main()
{
  char ans, result;
  int num;

  cout << "Hello, please input a single char: ";
  cin >> ans;
  num = ans;

  if (num >= LA && num <= LZ) {
    result = num - (LA - UA);
    cout << "The upper case char for this is: " << result << endl;
  } else if (num >= UA && num <= UZ) {
    result = num + (LA - UA);
    cout << "The lower case char for this is: " << result << endl;
  } else {
    cout << ans << " is not a letter" << endl;
  }
  
  return 0;
}

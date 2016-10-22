/* 
 * To print out Fahrenheit, Celcius and Kelvin Temperatures
 * To open terminal in emacs hit :M-x then type shell (ESC + x)
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Prompt user for input
  int lowest, highest, step;
  
  cout << "This program outputs a temperature conversion table." << endl;
  cout << "Input the lowest number you want: ";
  cin >> lowest;
  cout << "Your input was: " << lowest << endl;

  cout << "Input the highest number you want: ";
  cin >> highest;
  cout << "Your input was: " << highest << endl;

  cout << "Input the steps you want: ";
  cin >> step;
  cout << "Your input was: " << step << endl << endl;
  
  
  // Print headers
  cout << setiosflags (ios :: left);
  cout.width(15);
  cout << "Fahrenheit";
  cout.width(15);
  cout << "Celcius";
  cout.width(15);
  cout << "Kelvins" << endl;

  // initialize values
  double store = 0;
  int n;

  // set output formatting
  cout.precision(2);
  cout.setf(ios::fixed);
  
  // Print values in for loop
  for (n = lowest; n <= highest; n += step) {
    cout.width(15);
    cout << n;
    store = (n - 32) * (static_cast<double>(5)/9);
    cout.width(15);
    cout << store;
    cout.width(15);
    cout << store + 273.15 << endl;
  }
  return 0;
}

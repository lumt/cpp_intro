/* This program tests the functions
 * in stats.h again and again
 * with various input until it has been
 * told to stop
 */

#include <iostream>
#include "stats.h"

using namespace std;

int main()
{
  int test = 1;
  float num1, num2, num3, num4;
  
  while (test != 0){
    cout << "Do you wish to test 1, 2, 3 or 4 numbers ";
    cout << "(enter 0 to end the program): ";
    cin >> test;

    if (test == 0){
      break;
    } else if (test > 4) {
      cout << "Sorry, the program can only test 1, 2, 3 or 4 values." << endl << endl;
      continue;
    }
      
    cout << "Enter first value: ";
    cin >> num1;

    if (test == 1){
      cout << "Average: " << num1 << ". Standard deviation: 0.";
      cout << endl << endl;
    } else if (test == 2){
      cout << "Enter second value: ";
      cin >> num2;
      cout << "Average: " << average(num1, num2) << ". ";
      cout << "Standard deviation: " << standard_dev(num1, num2) << ".";
      cout << endl << endl;
    } else if (test == 3) {
      cout << "Enter second value: ";
      cin >> num2;
      cout << "Enter third value: ";
      cin >> num3;
      cout << "Average: " << average(num1, num2, num3) << ". ";
      cout << "Standard deviation: " << standard_dev(num1, num2, num3) << ".";
      cout << endl << endl;
    } else if (test == 4) {
      cout << "Enter second value: ";
      cin >> num2;
      cout << "Enter third value: ";
      cin >> num3;
      cout << "Enter final value: ";
      cin >> num4;
      cout << "Average: " << average(num1, num2, num3, num4) << ". ";
      cout << "Standard deviation: " << standard_dev(num1, num2, num3, num4) << ".";
      cout << endl << endl;
    }
  }

  cout << "Finished testing 'statistics.h' header file." << endl << endl;

  return 0;
}

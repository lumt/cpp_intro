/* 
 * To print out Fahrenheit, Celcius and Kelvin Temperatures
 * To open terminal in emacs hit :C-x C-u
 * Q2: Split into 3 files
 */

#include <iostream>
#include <iomanip>        // to setiosflag
#include "conversions.h"

using namespace std;

/* Function prototypes */
void print_prelim();
void input_table_specs(int& lowest, int& highest, int& step);
void print_echo(int lowest, int highest, int step);
void print_table(int lowest, int highest, int step);

int main()
{
  // initialize parameters
  int lowest = 0, highest = 100, step = 1;

  // call functions
  print_prelim();
  input_table_specs(lowest, highest, step);
  print_echo(lowest, highest, step);
  print_table(lowest, highest, step);
  
  return 0;
}

/* Prints prelim message */
void print_prelim() {
  cout << "This program outputs a temperature conversion table." << endl;
}

void input_table_specs(int& lowest, int& highest, int& step) {
  cout << "Input the lowest number you want: ";
  cin >> lowest;
  cout << "Your input was: " << lowest << endl;

  cout << "Input the highest number you want: ";
  cin >> highest;
  cout << "Your input was: " << highest << endl;

  cout << "Input the steps you want: ";
  cin >> step;
  cout << "Your input was: " << step << endl << endl;
}

void print_echo(int lowest, int highest, int step) {
  cout << "Temperature conversion table from " << lowest << " to" << endl;
  cout << highest << " in steps of " << step << ":" << endl << endl;
}

void print_table(int lowest, int highest, int step) {
  // Print headers
  cout << setiosflags (ios::left);
  cout.width(15);
  cout << "Fahrenheit";
  cout.width(15);
  cout << "Celcius";
  cout.width(15);
  cout << "Kelvins" << endl;
  // the following prints a line of width filled with:
  cout.fill('-');
  cout.width(45);
  cout << "" << endl;
  // convert fill function back to spaces
  cout.fill(' ');

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
    store = celcius_of(n);
    cout.width(15);
    cout << store;
    cout.width(15);
    cout << kelvin_of(store) << endl;
  }
}

/* This is not actually an exercise but practice
 *
 * The purpose of this program is to
 * calculate the roots of a quadratic equation
 * by asking the coefficients from the user
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*prototypes*/
void print_prelim();
void get_coeff(float& a1, float& b1, float& c1);
double calc_root(float a1, float b1, float c1);

int main()
{
  // prints greeting msg to user
  print_prelim();

  float a1 = 1, b1 = 10, c1 = 1;
  
  // get coefficients from user by passing in ref to a b c
  get_coeff(a1, b1, c1);
  cout << "Inputted." << endl << "a: " << a1 << ". b: " << b1 << ". ";
  cout << "c: " << c1 << "." << endl << endl;
  
  // calcs and returns the root, if possible (real roots)
  cout << "Answer: " << calc_root(a1, b1, c1) << endl << endl;

  return 0;
}

/* function definitions */
void print_prelim() {
  cout << "This program calculates the roots of a quadratic:";
  cout << endl << endl << endl;
  cout.width(20);
  cout << setiosflags(ios::left);
  cout << "     ax^2 + bx + c = 0     ";
  cout << endl << endl;
  cout << "But does not work if roots are not real numbers";
  cout << endl << endl;
}

void get_coeff(float& a1, float& b1, float& c1) {
  cout << "Input value of a: ";
  cin >> a1;

  cout << "Input value of b: ";
  cin >> b1;

  cout << "Input value of c: ";
  cin >> c1;
}

double calc_root(float a1, float b1, float c1) {
  float test;
  test = (b1*b1) - (4*a1*c1);
  
  if (test < 0) {
    cout << "Sorry, root is not real." << endl;
    return 0;
  }
  
  double x1, x2;
  x1 = (-b1 + test)/(2*a1);
  x2 = (-b1 - test)/(2*a1);

  if (x1 > x2) return x1;
  return x2;
}

  
  
  

/* write "print_pyramid"
 * takes in height and prints the pyramid
 * with '*' to that height
 */

#include <iostream>
#include <iomanip>

using namespace std;

int get_height();
void print_prompt();
void print_pyramid(int height);
void print_level(int level, int height);

int main()
{
  int height;
  print_prompt();
  height = get_height();
  print_pyramid(height);
  
  return 0;
}

int get_height()
{
  int height;  
  do {
    cout << "Enter height for pyramid: ";
    cin >> height;
    if (height < 1 || height > 30)
      cout << "height out of range. enter 1 to 30." << endl;
  } while (height < 1 || height > 30);
  
  return height;
}

void print_prompt()
{
  cout << "This program prints a 'pyramid' shape of" << endl;
  cout << "a specified height on the screen." << endl << endl;
}
  
void print_pyramid(int height)
{
  int level;

  cout << endl;
  for (level = 1; level <= height; level++)
    print_level(level, height);
  cout << endl;
}

void print_level(int level, int height)
{
  int padding;
  padding = height - level + (height/2);
  cout << string(padding, ' ');
  cout << string(level*2, '*') << endl;
}

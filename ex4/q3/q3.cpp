/* A program which counts then displays
 * the number of characters (including blanks) in its
 * own source code file
 * 
 * lt1516
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  
  cout << "Hello, this program counts the characters within its own source code file";
  cout << endl << endl;

  ifstream input;
  
  int count = 0;
  char ch;
  
  input.open("q3.cpp");

  if (input.fail()) {
    cout << "File could not be loaded!" << endl << endl;
    return 1;
  }

  input.get(ch);

  while (!input.eof()) {
    count++;
    input.get(ch);
  }
  input.close();

  cout << "Total number of characters: " << count;
  cout << endl;  

  return 0;
}

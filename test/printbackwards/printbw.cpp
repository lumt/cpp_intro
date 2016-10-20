#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int MAX = 1000;
	typedef char File_array[MAX];

	ifstream input;
	input.open("printbw.cpp");

	File_array file;
	char buffer;
	int count;

	input.get(buffer);
	for (count = 0; !input.eof() && count < MAX; count++)
	{
		file[count] = buffer;
		input.get(buffer);
	}

	for ( ; count > 0; count --)
		cout << file[count];

	return 0;
}
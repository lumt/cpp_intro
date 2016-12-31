#include <iostream>
#include "soundex.h"

using namespace std;

int main() {

	char soundex[5];

	// question 1 

	cout << "====================== Question 1 ======================" << endl;

	encode("Washington", soundex);
	cout << "The soundex coding for 'Washington' is " << soundex << endl;

	encode("Lee", soundex);
	cout << "The soundex coding for 'Lee' is " << soundex << endl;

	encode("Jackson", soundex);
	cout << "The soundex coding for 'Jackson' is " << soundex << endl;

	encode("Lumsum", soundex);
	cout << "The soundex coding for 'Lumsum' is " << soundex << endl;

	encode("Tanthasatian", soundex);
	cout << "The soundex coding for 'Tanthasatian' is " << soundex << endl;

	encode("Leeson", soundex);
	cout << "The soundex coding for 'Leeson' is " << soundex << endl;

	// question 2  

	cout << "====================== Question 2 ======================" << endl;

	cout << "The soundex codes S250 and S255 are ";
	if (!compare("S250", "S255"))
	cout << "not ";
	cout << "equal" << endl;

	cout << "The soundex codes W252 and W252 are ";
	if (!compare("W252", "W252"))
	cout << "not ";
	cout << "equal" << endl;

	cout << "The soundex codes L525 and L222 are ";
	if (!compare("L525", "L222"))
	cout << "not ";
	cout << "equal" << endl;

		cout << "The soundex codes T532 and T532 are ";
	if (!compare("T532", "T532"))
	cout << "not ";
	cout << "equal" << endl;

	cout << "The soundex codes W252 and W252123 are ";
	if (!compare("W252", "W252123"))
	cout << "not ";
	cout << "equal" << endl;

	// question 3

	cout << "====================== Question 3 ======================" << endl;

	cout << "There are ";
	cout << count("Leeson", "Linnings, Leasonne, Lesson and Lemon.") << " ";
	cout << "surnames in the sentence 'Linnings, Leasonne, Lesson and Lemon.'"
	   << endl;
	cout << "  that have the same Soundex encoding as 'Leeson'" << endl;

	cout << "There are ";
	cout << count("Jackson", "Jakes, Jaxin, J acksin, Jones.");
	cout << " surnames in the sentence 'Jakes, Jaxin, J acksin, Jones.'" 
	   << endl;
	cout << "  that have the same Soundex encoding as 'Jackson'" << endl << endl;

	return 0;
}


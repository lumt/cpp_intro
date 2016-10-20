/*
 Replace the "switch" statement with the line

	print_day(static_cast<Day>(count), cout);
 instead, and add an appropriate definition after the main program
 for the function "print_day(...)", using a "switch" statement 
 (don't forget the function declaration as well).
 ("cout" is of type or class "ostream").
*/

#include <iostream>
#include <fstream>
using namespace std;
	
enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
	
int closing_time(Day day_of_the_week);
void print_day(Day day, ostream &out_stream);
	
/* MAIN PROGRAM */
int main()
{
	int count;

	/* Print table heading */
	cout.setf(ios::left);
	cout.width(19);
	cout << "DAY";
	cout << "CLOSING TIME\n\n";

	/* Print table from Sunday to Saturday */
	for (count = static_cast<int>(Sun) ; count <= static_cast<int>(Sat) ; count++)
	{
	  cout.width(19);
	  print_day(static_cast<Day>(count), cout);
	}


	return 0;
}
/* END OF MAIN PROGRAM */
	
void print_day(Day day, ostream &out_stream)
{
	switch (day)
	{
	case Sun: out_stream << "Sunday"; break;
	case Mon: out_stream << "Monday"; break;
	case Tue: out_stream << "Tuesday"; break;
	case Wed: out_stream << "Wednesday"; break;
	case Thu: out_stream << "Thursday"; break;
	case Fri: out_stream << "Friday"; break;
	case Sat: out_stream << "Saturday"; break;
	default:	cout << "ERROR!";
	}
	out_stream << closing_time(static_cast<Day>(day)) << "pm\n";
}

/*
b) The shop keeper wants to change the closing times to 1pm on Sundays,
5pm on Saturdays, 8pm on Wednesdays, and 6pm all other days.
Make appropriate changes to the function "closing_time(...)"
 using a "switch" statement, and test the program.
 */

/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
int closing_time(Day day_of_the_week)
{
	switch (day_of_the_week)
	{
		case Sun: return 1;
		case Sat: return 5;
		case Wed: return 8;
		case Mon:
		case Tue:
		case Thu:
		case Fri: return 6;
		default: return 0;
	}	
}



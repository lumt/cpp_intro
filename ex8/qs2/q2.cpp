/* a) write two functions
 * one prints list forwards
 * one prints list backwards
 *
 * b) write print list backwards
 * iteratively
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 50;

struct Node
{
	char word[MAX];
	Node *next;
};

void assign_list(Node *&my_list, int &list_size);
void assign_node(Node *&my_list);
void print_list(Node *my_list);
void print_back(Node *here);
void print_back_iter(Node *my_list, int list_size);


int main()
{
	Node *my_list = NULL;
	int list_size = 0; // store size of list

	assign_list(my_list, list_size);
	cout << "The list size is: " << endl;
	cout << list_size << endl;
	cout << "The forwards list is: " << endl;
	print_list(my_list);
	cout << "The list backwards (recursive) is: " << endl;
	print_back(my_list);
	cout << endl;

	cout << "The list backwards (iteratively) is: " << endl;
	print_back_iter(my_list, list_size);

	cout << endl << endl;

	return 0;
}

/* function to assign new list using input as head */
void assign_list(Node *&my_list, int &list_size)
{
	Node *current, *last;

	assign_node(my_list);
	list_size++;

	cout << "Input word or '.' to end list: ";
	cin >> my_list->word;
	if (!strcmp(".", my_list->word))
	{
		delete my_list;
		my_list = NULL;
	}
	current = my_list;

	while (current != NULL)
	{
		assign_node(last);
		list_size++;
		cout << "Input new word or '.' to end list: ";
		cin >> last->word;
		if (!strcmp(".", last->word))
		{
			delete last;
			list_size--;
			last = NULL;
		}
		current->next = last;
		current = last;
	}
}

/* function to assign new node using input para as pointer */
void assign_node(Node *&my_list)
{
	// allocates memory on heap for new node with type Node
	my_list = new (nothrow) Node;

	// checks for errors
	if (my_list == NULL)
	{
		cout << "error new node" << endl;
		exit(1);
	}
}

/* function to print values in list */
void print_list(Node *my_list)
{
	Node *current;

	current = my_list;
	while (current != NULL) {
		cout << current->word << " ";
		current = current->next;
	}
	cout << endl;
}

/* function to print list backwards (recursively) */
void print_back(Node *here)
{
	// if not last one
	if (here->next != NULL) {
		// print the next one
		print_back(here->next);
		// before you print yourself
		cout << here->word << " ";
	} else {
		// i am the last node, so i print myself and return the stack
		cout << here->word << " ";
	}
}

// iterative version
void print_back_iter(Node *my_list, int list_size)
{
	char array[list_size][MAX];
	int count = 0;
	Node *current;
	current = my_list;

	while (current != NULL) {
		strcpy(array[count], current->word);
		current = current->next;

		if (current != NULL)
			count++;
	}


	for (;count > -1; count--)
		cout << array[count] << " ";
}

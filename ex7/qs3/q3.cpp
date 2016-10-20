/* LINKED LIST
 * write functions to:
 * add node in the middle
 * print list
 * delete node
 * sort the list
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX = 50;

struct Node
{
	char word[MAX];
	Node *next;
};

void assign_list(Node *&my_list);
void assign_node(Node *&my_list);
void print_list(Node *my_list);
void add_node_here(Node *&my_list);
void delete_word(Node *&my_list);
void sort_list(Node *&my_list);
void swap_node(Node *&first, Node *second);
Node *minimum_from(Node *adjacent);
bool string_smaller(char string1[], char string2[]);


int main()
{
	Node *my_list = NULL;

	assign_list(my_list);

	cout << "The list is: ";
	print_list(my_list);

	cout << "After which word to add extra? ";
	add_node_here(my_list);

	cout << "The list is: ";
	print_list(my_list);

	cout << "Which word would you like to delete? ";
	delete_word(my_list);

	cout << "The list has become: ";
	print_list(my_list);

	cout << "Now we sort the list." << endl;
	sort_list(my_list);
	cout << "Finally, the list is: ";
	print_list(my_list);

	cout << endl;

	return 0;
}

/* function to assign new list with input parameter as head */
void assign_list(Node *&my_list)
{
	Node *current, *last;

	assign_node(my_list);
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
		cout << "Input new word or '.' to end list: ";
		cin >> last->word;
		if (!strcmp(".", last->word))
		{
			delete last;
			last = NULL;
		}
		current->next = last;
		current = last;
	}
}

/* function to assign new node using input para as head */
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

void add_node_here(Node *&my_list)
{
	char da_word[MAX], add_word[MAX];
	Node *current, *here;
	assign_node(here); // here points to a new node;

	cin >> da_word;
	current = my_list;

	// find where da_word is in my_list
	while (current != NULL)
	{
		if (strcmp(da_word, current->word)) // if different
			current = current->next;
		else // must be same ie found it
			break;
	}

	if (current == NULL) {
		cout << "Word does not exist in list" << endl;
		exit(1);
	}

	cout << "Word to add in: ";
	cin >> add_word;
	strcpy(here->word, add_word);
	here->next = current->next;
	current->next = here;
}

void delete_word(Node *&my_list)
{
	char del_word[MAX];
	Node *current, *prev;

	cin >> del_word;
	current = my_list;
	prev = my_list;

	if (!strcmp(del_word, current->word)) {
		my_list = current->next;
		delete current;
		return;
	}

	current = current->next;

	while (current != NULL)
	{
		if (strcmp(del_word, current->word)) {
			current = current->next;
			prev = prev->next;
		}
		else
			break;
	}

	if (current == NULL) {
		cout << "Word does not exist in list" << endl;
		exit(1);
	}
	
	prev->next = current->next;
	delete current;
}

void sort_list(Node *&my_list)
{
	Node *current = my_list;

	// checks up to the one before the last node
	while (current->next != NULL)
	{
		swap_node(current, minimum_from(current->next));
		current = current->next;
	}
}

void swap_node(Node *&first, Node *second)
{
	// technically swapping values not nodes
	char temp[MAX];
	strcpy(temp, first->word);
	strcpy(first->word, second->word);
	strcpy(second->word, temp);
}

/* function that returns a pointer to the node that is lowest from current */
Node *minimum_from(Node *adjacent)
{
	Node *minimum = adjacent;

	adjacent = adjacent->next;
	while (adjacent != NULL)
	{
		if (string_smaller(adjacent->word, minimum->word))
			minimum = adjacent;
		adjacent = adjacent->next;
	}

	return minimum;
}

bool string_smaller(char string1[], char string2[])
{
	int count = 0;

	while (string1[count] != '\0' && string2[count] != '\0') {
		if (string1[count] < string2[count])
			return true;
		else
			return false;
		count++;
	}

	if (string1[0] == '\0' && string2[count] != '\0')
		return true;
	else
		return false;
}
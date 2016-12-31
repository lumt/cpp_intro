#include <iostream>
#include "substring.h"

using namespace std;

int substring_position(const char* sub, const char* str)
{
	int count = 0;
	
	if (is_prefix(sub, str))
		return count;

	char str_cpy[strlen(str)];
	while (count != strlen(str)) {
		count++;

		// copy everything starting from counter
		for (int i = count; i < strlen(str) + 1; i++) {
			*(str_cpy + i - count) = *(str + i);
		}

		if (is_prefix(sub, str_cpy))
			return count;
	}

	// not found
	return -1;
}


// Function to check if sub is a prefix of str
// prefix = beginning
bool is_prefix(const char* sub, const char* str)
{
	if (strlen(sub) == 0) {
		return true;
	}

	if (*sub == *str) {
		// creates copy to store sub[1:]
		char sub_cpy[strlen(sub)];
		int i;
		for (i = 1; i < strlen(sub) + 1; i++)
			*(sub_cpy + i - 1) = *(sub + i);

		// copy to store str[1:]
		char str_cpy[strlen(str)];
		for (i = 1; i < strlen(str) + 1; i++)
			*(str_cpy + i - 1) = *(str + i);

		return is_prefix(sub_cpy, str_cpy);
	}

	return false;
}
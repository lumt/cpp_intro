/* Binary search
 * given a sorted array
 * write a binary search function
 * whch searches the values in array
 * from list[first] to list[last]
 * and return the position of 'value' 
 * being looked for if not found return -1
 */

#include <iostream>
using namespace std;

const int MAX = 10;

int binary_search(int value, int array[], int start, int end);
int partition(int array[], int start, int end);
void quicksort(int array[], int start, int end);
void display(int array[], int size);


int main()
{
	int array[MAX] = {6,4,2,7,1,21,99,25,31,11};
	int value;

	cout << "Your array (unsorted) is: " << endl;
	display(array, MAX);

/*
	cout << "Enter values for your array." << endl;
	for (int i = 0; i < MAX; i++) {
		cout << "Enter value of element " << i << ": ";
		cin >> array[i];
	}
	cout << endl;
*/
	quicksort(array, 0, MAX-1);
	cout << "Your array (sorted) is: " << endl;
	display(array, MAX);

	cout << "Enter value to search in your array: ";
	cin >> value;

	binary_search(value, array, 0, MAX-1);

	return 0;
}


int binary_search(int value, int array[], int start, int end)
{
	// recursive case
	if (start < end) {
		int mid_idx = (start+end)/2;

		if (value == array[mid_idx]) {
			cout << "Found it, index is: " << mid_idx;
			cout << endl << endl;
			return mid_idx;
		} else if (value > array[mid_idx]) {
			binary_search(value, array, mid_idx + 1, end);
		} else if (value < array[mid_idx]) {
			binary_search(value, array, start, mid_idx - 1);
		}
	} else {
		if (value == array[start]) {
			cout << "Found " << value << ", index is at: " << start;
			cout << endl;
			return start;
		}

		cout << "Did not find " << value << "." << endl;
		return -1;
	}
}

int partition(int array[], int start, int end)
{
	int pivot = array[end];
	int partitionidx = start;

	for (int i = start; i < end; i++)
	{
		if (array[i] < pivot) {
			swap(array[i], array[partitionidx]);
			partitionidx++;
		}
	}

	swap(array[partitionidx], array[end]);
	return partitionidx;
}

void quicksort(int array[], int start, int end)
{
	if (start < end)
	{
		int partition_idx = partition(array, start, end);
		quicksort(array, start, partition_idx - 1);
		quicksort(array, partition_idx + 1, end);
	}
}


void display(int array[], int size)
{
	for (int i = 0; i < MAX; i++) {
		cout << array[i];
		if (i != MAX-1)
			cout << ", ";
	}
	cout << endl;
}

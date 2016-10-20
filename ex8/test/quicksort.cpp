/* test program
 * to implement quicksort algorithm
 */

#include <iostream>
using namespace std;

const int MAX = 10;

int partition(int array[], int start, int end);
void quicksort(int array[], int start, int end);
void display(int array[], int size);


int main()
{
	int array[MAX];

	cout << "Enter values for your array." << endl;
	for (int i = 0; i < MAX; i++) {
		cout << "Enter value of element " << i << ": ";
		cin >> array[i];
	}
	cout << endl;

	cout << "Array before quicksort: " << endl;

	display(array, MAX);

	quicksort(array, 0, MAX- 1);

	cout << "Array after quicksort: " << endl;

	display(array, MAX);

	cout << endl;

	return 0;
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


/* write a function which multiplies
 * m x n matrix of integers by 
 * n x r matrix of integers.
 */

#include <iostream>
 using namespace std;

const int MSIZE = 2;
const int NSIZE = 2;
const int RSIZE = 2;


void input_matrix1(int matrix[][NSIZE], int rowsize);
void input_matrix2(int matrix[][RSIZE], int rowsize);
void display_matrix1(int matrix[][NSIZE], int rowsize);
void display_matrix2(int matrix[][RSIZE], int rowsize);
void multiply_matrix(int matrix1[][NSIZE],int matrix2[][RSIZE], int result[][RSIZE]);
int compute_product(int row, int col, int matrix1[][NSIZE], int matrix2[][RSIZE]);


int main()
{
	int matrix_1[MSIZE][NSIZE];
	int matrix_2[NSIZE][RSIZE];
	int result[MSIZE][RSIZE];

	cout << endl;
	cout << "INPUT FIRST (" << MSIZE << "x" << NSIZE << ") MATRIX: " << endl;
	input_matrix1(matrix_1, MSIZE);
	cout << "INPUT SECOND (" << NSIZE << "x" << RSIZE << ") MATRIX: " << endl;
	input_matrix2(matrix_2, NSIZE);
	cout << endl;

	display_matrix1(matrix_1, MSIZE);
	cout << "     TIMES" << endl << endl;
	display_matrix2(matrix_2, NSIZE);
	cout << "     EQUALS" << endl << endl;
	multiply_matrix(matrix_1, matrix_2, result);
	display_matrix2(result, MSIZE);

	return 0;
}

void input_matrix1(int matrix[][NSIZE], int rowsize)
{
	for (int row = 0; row < rowsize; row++) {
		cout << "Type in " << NSIZE << " values for ROW " << row + 1 << " seperated by spaces: ";
		for (int col = 0; col < NSIZE; col++)
			cin >> matrix[row][col];
	}
}

void input_matrix2(int matrix[][RSIZE], int rowsize)
{
	for (int row = 0; row < rowsize; row++) {
		cout << "Type in " << RSIZE << " values for ROW " << row + 1 << " seperated by spaces: ";
		for (int col = 0; col < RSIZE; col++)
			cin >> matrix[row][col];
	}
}

void display_matrix1(int matrix[][NSIZE], int rowsize)
{
	for (int row = 0; row < rowsize; row++) {
		cout << "     ";
		for (int col = 0; col < NSIZE; col ++)
			cout << matrix[row][col] << "     ";
		cout << endl;
	}
	cout << endl;
}

void display_matrix2(int matrix[][RSIZE], int rowsize)
{
	for (int row = 0; row < rowsize; row++) {
		cout << "     ";
		for (int col = 0; col < RSIZE; col ++)
			cout << matrix[row][col] << "     ";
		cout << endl;
	}
	cout << endl;
}

void multiply_matrix(int matrix1[][NSIZE],int matrix2[][RSIZE], int result[][RSIZE])
{
	for (int row = 0; row < MSIZE; row++) {
		for (int col = 0; col < RSIZE; col++)
			result[row][col] = compute_product(row, col, matrix1, matrix2);
	}
}

int compute_product(int row, int col, int matrix1[][NSIZE], int matrix2[][RSIZE])
{
	int result = 0;
	for (int iter = 0; iter < NSIZE; iter++)
		result += matrix1[row][iter] * matrix2[iter][col];
	return result;
}
/* C++ Programming, Example answer, Exercise 4, Sheet 6  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 30th September 2001    */

/* This program demonstrates the function 'matrix_mult' which
   multiplies an MxN matrix by a NxR matrix */

#include <iostream>
using namespace std;

const int M = 2;
const int N = 3;
const int R = 2;

/* Function to multiply matrices */
void matrix_mult(int a[][N], int b[][R], int answer[][R], int a_rows);

/* Function to work out a single entry in the answer matrix */
int entry_for_row_and_column(int row, int column, int a[][N], int b[][R]);

/* Function to input N column matrix */
void input_N_column_matrix(int a[][N], int a_rows);

/* Function to input R column matrix */
void input_R_column_matrix(int a[][R], int a_rows);

/* Function to display N column  matrix */
void display_N_column_matrix(int a[][N], int a_rows);

/* Function to display R column  matrix */
void display_R_column_matrix(int a[][R], int a_rows);

/* START OF MAIN PROGRAM */
int main()
{
	int a[M][N];
	int b[N][R];
	int answer[M][R];
	
	/* input the two matrices to be multiplied */
	cout << "INPUT FIRST (" << M << "x" << N << ") MATRIX:\n";
	input_N_column_matrix(a, M);
	cout << "INPUT SECOND (" << N << "x" << R << ") MATRIX:\n";
	input_R_column_matrix(b, N);
	
	/* multiply them */
	matrix_mult(a, b, answer, M);
	
	/* and display the answer */
	cout << "\n";
	display_N_column_matrix(a, M);
	cout << "TIMES\n";
	display_R_column_matrix(b, N);
	cout << "EQUALS\n";
	display_R_column_matrix(answer, M);
		
	return 0;
}
/* END OF MAIN PROGRAM */

/* DEFINITION OF FUNCTION matrix_mult */
void matrix_mult(int a[][N], int b[][R], int answer[][R], int a_rows)
{
	for (int row = 0 ; row < a_rows ; row++)
		for (int column = 0 ; column < R ; column++)
		{
			answer[row][column] = entry_for_row_and_column(row, column, a, b);
		}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION matrix_mult */
int entry_for_row_and_column(int row, int column, int a[][N], int b[][R])
{
	int total = 0;
	for (int count = 0 ; count < N ; count++)
	{
		total += a[row][count] * b[count][column];
	}
	return total;
}
/* END OF FUNCTION DEFINITION */


/* DEFINITION OF FUNCTION input_N_column_matrix */
void input_N_column_matrix(int a[][N], int a_rows)
{
	for (int row = 0 ; row < a_rows ; row++)
	{
		cout << "Type in " << N << " values for row " << row + 1 << " separated by spaces: ";
		for (int column = 0 ; column < N ; column++)
			cin >> a[row][column];
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION input_R_column_matrix */
void input_R_column_matrix(int a[][R], int a_rows)
{
	for (int row = 0 ; row < a_rows ; row++)
	{
		cout << "Type in " << R << " values for row " << row + 1 << " separated by spaces: ";
		for (int column = 0 ; column < R ; column++)
			cin >> a[row][column];
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION display_N_column_matrix */
void display_N_column_matrix(int a[][N], int a_rows)
{
	for (int row = 0 ; row < a_rows ; row++)
	{
		cout << "           ";
		for (int column = 0 ; column < N ; column++)
		{
			cout.width(5);
			cout << a[row][column] << " ";
		}
		cout << "\n";
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION display_R_column_matrix */
void display_R_column_matrix(int a[][R], int a_rows)
{
	for (int row = 0 ; row < a_rows ; row++)
	{
		cout << "           ";
		for (int column = 0 ; column < R ; column++)
		{
			cout.width(5);
			cout << a[row][column] << " ";
		}
		cout << "\n";
	}
}
/* END OF FUNCTION DEFINITION */
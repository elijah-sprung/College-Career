/*
* Program Name: m_mult.cpp
* Author: Elijah Sprung
* Class: CSC-4310
* Date: 09-04-2023
* Location: ~/csc4310/matrix_multiply
* This program takes in 4 arguments - the program run, the first input file, the second input file, and the output file. The first
* and second input files both contain two matricies with their length and height specified at the top of the file.
* These are then loaded into memory and multiplied together. The output matrix is stored in the fourth arguement, the output file.
* The memory for the matricies has been allocated dynamically (wow that was easier than I thought).
* If the files that are being written from or written to do not exist, then this program will not function, and it will show
* these errors.
* Compilation Line: g++ m_mult.cpp -o m_mult
* Execution Line: ./m_mult matrix1.txt matrix2.txt product.txt
*/

#include <iostream>
#include <fstream>

using namespace std;

// Function prototypes for the load, multiply, and output operations.
void load_matrix(int* & matrix, int& N, int& M, char** argv, int index);
void multiply_matrix(int* mat_a, int* mat_b, int& N1, int& M1, int& N2, int& M2, int* & mat_out, int& N3, int& M3);
void output_matrix(int* mat_out, int& N3, int& M3, char** argv, int index);

// Main function where all other functions are called, takes input from the command line in the form of agrc and argv.
// argc is the number of arguments and argv is those arguments.
int main(int argc, char** argv) {
	// Forces the user to use 4 arguments.
	if (argc != 4) {
		cerr << "You have not entered enough arguments, there should be 4. The name of the executed file, the two input files, and the output file." << endl;
	}

	// Declare matrices, but do not initialize them yet.
	int* mat_a;
	int* mat_b;
	int* mat_out;

	// N is rows, M is columns
	int N1, M1, N2, M2, N3, M3;

	// Initialize the two input matrices
	load_matrix(mat_a, N1, M1, argv, 1);
	load_matrix(mat_b, N2, M2, argv, 2);

	// Make sure the matrices can be multiplied and then do so if that is the case. This also initializes the output matrix.
	if (M1 == N2) {
		multiply_matrix(mat_a, mat_b, N1, M1, N2, M2, mat_out, N3, M3);
	} else {
		cerr << "Your matrices cannot be multiplied. " << M1 << " != " << N2 << endl;
	}
	// Print the output matrix to a file.
	output_matrix(mat_out, N3, M3, argv, 3);

	// Free up all used memory and return 0.
	delete[] mat_a;
	delete[] mat_b;
	delete[] mat_out;

	return 0;
}

/*
* This function takes in the uninitialized matrix along with the number of columns and rows, argv, and the index for argv.
* Then it tries to open the file specified by the index of argv passed, and takes in the number of rows and columns.
* Finally it reads in to the matrix the numbers from the file dynamically, before closing the file.
*/

void load_matrix(int* & matrix, int & N, int & M, char** argv, int index) {
	fstream input_file;
	input_file.open(argv[index]);
	if (!input_file) {
		cerr << "File " << argv[index] << " could not be opened, try again." << endl;
	} else {
		input_file >> N;
		input_file >> M;

		matrix = new int[N * M];

		while (input_file) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					input_file >> *(matrix + i * M + j);
				}
			}
		}
	}
	input_file.close();
}

/*
* This function takes in both of the input matrices, their measurements, and the output matrix and its measurements.
* It sets the measurements for the output matrix and then initializes it and fills it with 0s. Then it steps through
* both input matrices and multiplies them together, storing the resulting values in the output matrix.
*/

void multiply_matrix(int* mat_a, int* mat_b, int& N1, int& M1, int& N2, int& M2, int* & mat_out, int& N3, int& M3) {
	N3 = M1;
	M3 = N2;

	mat_out = new int[N3 * M3];
	
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M2; j++) {
			*(mat_out + i * M3 + j) = 0;

			for (int k = 0; k < N2; k++) {
				*(mat_out + i * M3 + j) += *(mat_a + i * M1 + k) * *(mat_b + k * M2 + j);
			}
		}
	}
}

/*
* This function takes in the output matrix and its measurements along with argv and the index passed in for the file needed.
* The file is opened, or an error is displayed, and the loop runs through the matrix and outputs its data to a file for
* easy readability. After this concludes, the file is closed.
*/

void output_matrix(int* mat_out, int& N3, int& M3, char** argv, int index) {
	fstream output_file;
	output_file.open(argv[index]);
	if (!output_file) {
		cerr << "File " << argv[index] << " could not be opened, try again." << endl;
	} else {
		for (int i = 0; i < N3; i++) {
			for (int j = 0; j < M3; j++) {
				output_file << *(mat_out + i * M3 + j) << " ";
			}
			output_file << endl;
		}
	}
}
/*
* Program Name: test_1.c
* Author: Elijah Sprung
* Class: CSC-4310
* Date: 10/01/2023
* Location: ~/csc4310/test_1
* Program that does a multithreaded matrix multiply with openMPI
* Line 1 has an integer for the number of columns and rows the matrix has (N). The N lines after have N integers separated by spaces. N should be equal
* to the definition NUM_THREADS
* Compilation Line: gcc test_1.c -o test_1 -fopenmp
* Execution Line: ./test_1 (matrix 1 input) (matrix 2 input) (output) 2>/dev/null
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include <sys/time.h>

// define the number of threads available
#define NUM_THREADS 4

// function prototypes
int* load_matrix(int *matrix, int *N, int *M, char *argv[], int index);
int* matrix_multiply(int* mat_a, int* N1, int* M1, int* mat_b, int* N2, int* M2, int* mat_out);
void print_matrix(int* mat_out, int* N, char* argv[]);

int main(int argc, char *argv[])
{
	// variables for calculations
	int *mat_a, *mat_b, *mat_out = NULL;
	int N1, M1, N2, M2, N3, M3;

	// time structs
	struct timeval begin, end;

	// handle if there are not enough CLI arguments
	if (argc != 4)
	{
		fprintf(stderr, "Error: Invalid number of arguments, check test_1.c for execution requirements. \n");
		exit(1);
	}

	// load the matrices from their files
	mat_a = load_matrix(mat_a, &N1, &M1, argv, 1);
	mat_b = load_matrix(mat_b, &N2, &M2, argv, 2);

	// check for if the matrices follow multiplication rules
	if (M1 != N2)
	{
		fprintf(stderr, "Error: Matrices cannot be multiplied to do multiplication rules. \n");
		exit(3);
	}

	// make sure matrices are square
	if ((N1 != M1) && (N2 != M2))
	{
		fprintf(stderr, "Error: At least one of your matrices is not square. \n");
		exit(3);
	}

	// make sure the matrices can be evenly divided amongst the threads
	if (N1 != NUM_THREADS)
	{
		fprintf(stderr, "Error: Must have same length matrix as threads used. \n");
	}

	// setup output array and multiply
	mat_out = malloc((N1 * M2) * sizeof(int));

	gettimeofday(&begin, NULL);
	matrix_multiply(mat_a, &N1, &M1, mat_b, &N2, &M2, mat_out);
	gettimeofday(&end, NULL);

	// output results
	print_matrix(mat_out, &N1, argv);

	// time calculation and output
	double elapsed = (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) / 1000000.0);
	printf("time elapsed: %f s \n", elapsed);

	return 0;
}

// function to load a matrix from a file
int* load_matrix(int *matrix, int *N, int *M, char *argv[], int index) {
	FILE *input_file;
	int holder;

	// open file and guarentee success
	if ((input_file = fopen(argv[index], "r")) == NULL) {
		printf("Error: Could not open file %s. \n", argv[index]);
		exit(2);
	}

	// get N and M
	fscanf(input_file, "%d", &holder);
	*N = holder;
	*M = holder;

	// allocate array
	matrix = malloc((*N * *M) * sizeof(int));

	// fill array
	for (int i = 0; i < *N; i++) 
	{
		for (int j = 0; j < *M; j++) 
		{
			fscanf(input_file, "%d", &holder);
			matrix[(i * *M + j)] = holder;
		}
	}
	
	// close file
	fclose(input_file);

	return matrix;
}

// function to perfrom a multithreaded matrix multiply
int* matrix_multiply(int* mat_a, int* N1, int* M1, int* mat_b, int* N2, int* M2, int* mat_out)
{
	#pragma omp parallel num_threads(NUM_THREADS)
	{
		// local dot_products and thread number
		int dot_product = 0;
		int thread_num = omp_get_thread_num();
		int i = thread_num;

		// two loops to make sure all calculations are done
		for (int ii = 0; ii < *N1; ii++)
		{
			dot_product = 0;
			for (int j = 0; j < *N1; j++)
			{
				int holder = (mat_a[(i * *M1 + j)] * mat_b[(j * *M2 + ii)]);
				dot_product += holder;
			}
			mat_out[(thread_num * *M1 + ii)] = dot_product;
		}
	}

	return mat_out;
}

// function to otuput the result matrix to a file
void print_matrix(int* mat_out, int* N, char* argv[])
{
	FILE* output_file;

	// open output file
	if ((output_file = fopen(argv[3], "w")) == NULL) {
		printf("Error: Could not open file %s. \n", argv[3]);
		exit(2);
	}

	// fill output file with matrix data
	for (int i = 0; i < *N; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			fprintf(output_file,"%d ", mat_out[(i * *N + j)]);
		}
		fprintf(output_file, "\n");
	}

	// close file
	fclose(output_file);
}
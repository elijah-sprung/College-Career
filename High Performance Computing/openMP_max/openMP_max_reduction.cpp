/*
* Program Name: openMP_max_reduction.cpp
* Author: Elijah Sprung
* Class: CSC-4310
* Date: 09-14-2023
* Location: ~/csc4310/openMP_max
* Description: This program dynamically allocates and then fills an array with random numbers. Then it
* loops through that entire array using '#pragma omp parallel for' along with a max reduction in order
* to speed up the process. The max value is then printed out along with how long it took to complete the
* operation in seconds. There are other functions whose use has been commented out, as they were only
* needed for testing.
* Compilation Line: g++ openMP_max_reduction.cpp -o openMP_max_reduction -fopenmp
* Execution Line: ./openMP_max_reduction 10 2
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

using namespace std;

void array_setup(int* array, long length);
void print_array(int* array, long length);
int find_max_parallel(int* array, long length, int num_threads);

// Used for generating the random array, no value greater than 1000
#define MAX 1001

int main(int argc, char** argv) {
	// Seed random at NULL and a flag to check input
	bool flag = false;
	srand(time(NULL));

	// Checking argc to sanitize input
	switch (argc) {
	case 1:
		cerr << "You have not entered N or T, which correspond to the amount of numbers generated for the array and the number of threads to use." << endl;
		break;
	case 2:
		cerr << "You are missing an argument, there should be 2 along with the program. The amount of numbers to be generated and the number of threads to use." << endl;
		break;
	case 3:
		flag = true;
	}

	if (flag == true) {
		// Take in arguments and assign them to variables
		long length = strtol(argv[1], NULL, 10);
		int num_threads = strtol(argv[2], NULL, 10);

		// Logic to make sure that all inputs are valid and usable
		if (length >= 10001 || length < 2) {
			cerr << "Invalid input for length of the array. Must be greater than 2 and less than 10,000." << endl;
		}
		else if (num_threads >= 50 || num_threads < 2) {
			cerr << "Invalid input for number of threads. Must be greater than 2 and less than 50." << endl;
		}
		else if (length % num_threads != 0) {
			cerr << "Invalid input. Length of the array should evenly divide into number of threads." << endl;
		}
		else {
			// Dynamically allocate the array
			int* array = (int*)malloc(length * sizeof(int));
			array_setup(array, length);

			// print_array(array, length);
			// Do the parallel version of finding max
			double parallel_begin = omp_get_wtime();
			int parallel_max = find_max_parallel(array, length, num_threads);
			double parallel_end = omp_get_wtime();

			// Output results and time for checking
			cout << "Parallel - max: " << parallel_max << ", elapsed: " << ((parallel_end - parallel_begin) * 1000) << endl;

			// Un-allocate the space for the array
			free(array);
		}
	}

	return 0;
}

// Loops through the entire array and fills it with random numbers
void array_setup(int* array, long length) {
	for (int i = 0; i < length; i++) {
		array[i] = rand() % MAX;
	}
}

// Prints out the array in a readable format
void print_array(int* array, long length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

// Find the max value in an array through parallel computing
int find_max_parallel(int* array, long length, int num_threads) {
	// Set a global max outside of pragma one and find the bounds for the upcoming loop
	int global_max = array[0];
	const int thread_bounds = length / num_threads;
	//cout << length << endl;

	//cout << global_max << " " << thread_bounds << " " << num_threads << endl;

	// Set the number of threads based on input
	omp_set_num_threads(num_threads);

	// Begin parallel computing
	#pragma omp parallel for reduction(max:global_max)
	for (int i = 0; i < length; i++) {
		// printf("%i %i %i\n", i, omp_get_thread_num(), array[i]);
		if (array[i] > global_max) {
			global_max = array[i];
		}
	}

	return global_max;
}
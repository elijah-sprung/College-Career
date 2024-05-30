/*
* Program Name: openMP_max.cpp
* Author: Elijah Sprung
* Class: CSC-4310
* Date: 09-11-2023
* Location: ~/csc4310/openMP_max
* Description: This program dynamically allocates and creates an array of random values, and then finds the max value in that array
* through both serial and parallel methods. Then it runs these methods 20 times each and compares the time it took to see which is
* faster.
* Compilation Line: g++ openMP_max.cpp -o openMP_max -fopenmp
* Execution Line: ./openMP_max 10 2
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

using namespace std;

void array_setup(int* array, long length);
void print_array(int* array, long length);
int find_max_serial(int* array, long length);
int find_max_parallel(int* array, long length, int num_threads);
void find_average_time(int* array, long length, int num_threads);

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
		} else if (num_threads >= 50 || num_threads < 2) {
			cerr << "Invalid input for number of threads. Must be greater than 2 and less than 50." << endl;
		} else if (length % num_threads != 0) {
			cerr << "Invalid input. Length of the array should evenly divide into number of threads." << endl;
		} else {
			// Dynamically allocate the array
			int* array = (int*) malloc(length * sizeof(int));
			array_setup(array, length);

			// Do the serial version of finding max
			double serial_begin = omp_get_wtime();
			int serial_max = find_max_serial(array, length);
			double serial_end = omp_get_wtime();

			// Do the parallel version of finding max
			double parallel_begin = omp_get_wtime();
			int parallel_max = find_max_parallel(array, length, num_threads);
			double parallel_end = omp_get_wtime();

			// Output results and time for checking
			cout << "Serial - max: " << serial_max << ", elapsed: " << ((serial_end - serial_begin) * 1000) << endl;
			cout << "Parallel - max: " << parallel_max << ", elapsed: " << ((parallel_end - parallel_begin) * 1000) << endl;

			// For finding average time over 20 runs for comparison
			find_average_time(array, length, num_threads);

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

// Simple loop that finds the max value in an array
int find_max_serial(int* array, long length) {
	int max = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	return max;
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
	#pragma omp parallel
	{
		// Setup local variables in the thread for computation
		int local_max = array[0];
		const int thread_num = omp_get_thread_num();
		const int start_bound = thread_num * thread_bounds;
		const int LCV = start_bound + thread_bounds;

		// Loop through the array based on the bounds set for each thread and find a local max
		//#pragma omp for THIS CAUSED ME SO MUCH MISERY WHY
		for (int i = start_bound; i < start_bound + thread_bounds; i++) {
			if (array[i] > local_max) {
				local_max = array[i];
			}
		}

		// Compare local maxes to the global max one thread at a time to avoid a race condition
		#pragma omp critical
		{
			if (local_max > global_max) {
				global_max = local_max;
			}
		}
	}

	return global_max;
}

// Loops both methods of finding max 20 times and finds the percent different between the average time to completion
void find_average_time(int* array, long length, int num_threads) {
	// Setup variables
	double serial_time = 0.0, parallel_time = 0.0;
	double serial_begin, serial_end, parallel_begin, parallel_end;

	// Loop and call each find max function, adding the times each run
	for (int i = 0; i < 20; i++) {
		serial_begin = omp_get_wtime();
		int serial_max = find_max_serial(array, length);
		serial_end = omp_get_wtime();

		serial_time += ((serial_end - serial_begin) * 1000);
		//cout << serial_time << endl;
	
		parallel_begin = omp_get_wtime();
		int parallel_max = find_max_parallel(array, length, num_threads);
		parallel_end = omp_get_wtime();

		parallel_time += ((parallel_end - parallel_begin) * 1000);
		//cout << parallel_time << endl;
	}

	// Find the average
	serial_time = serial_time / 20;
	parallel_time = parallel_time / 20;

	// Output for reading
	cout << "Serial time: " << serial_time << endl;
	cout << "Parallel time: " << parallel_time << endl;
	cout << "Num elements: " << length << endl;
	cout << "Num threads: " << num_threads << endl;
	cout << "Difference magnitude " << (((serial_time - parallel_time) / ((serial_time + parallel_time) / 2)) * 100) << endl;
}
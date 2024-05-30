/*
   Authors: Dylan Hudson, Blake Robinson, Parker Blue, McHale Trotter, Elijah Sprung
   Date: 3/7/22
   Class: CSC-2710

   About: Implementation of the seven sorting algorithms: selection sort, exchange sort, bubble sort, insertion sort, merge sort, quicksort and heapsort
          with timers to tell how long they take. Swaps are counted for exchange and selection sort, and all sorts have their compares tracked. There are
          also four datasets or size 100,000: one with fully random numbers, one with duplicates, one that is almost sorted, and one that is reverse sorted.

   How to compile:
      g++ -o testProg.out sortingProgram.cpp
   To execute the program:
      ./testProg.out
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <time.h>

using namespace std;

// Function prototypes for all of the functions that fill the different arrays with the types of datasets specified in the
// project description.
void fillRandom(int array1[], int size);
void fillDuplicate(int X[]);
void fillAlmost(int Y[]);
void fillReverse(int Z[]);

// Function prototypes for the functions that copy an array into another to be manipulated and print out an array.
void copyArray(int original[], int copy[]);
void printArray(int array1[], int size);

// Function prototypes for the sorting algorithms that do not require a partner function or recursion.
void selectionSort(int array1[], int size, long long int& compares, long long int& swaps);
void exchangeSort(int array1[], int size, long long int& compares, long long int& swaps);
void bubbleSort(int array1[], int size, long long int& compares);
void insertionSort(int arr[], int n, long long int& compares);

// Function prototypes for the merge sort algorithm and its companion function merge.
void merge(int x[], int left, int mid, int right, long long int& compares);
void mergeSort(int x[], int left, int right, long long int& compares);

// Function prototypes for the quick sort algorithm and its companion function partition.
void quickSort(int low, int high, int myarray[], long long int& compares);
void partition(int low, int high, int& pivotpoint, int myarray[], long long int& compares);

// Function prototypes for the heap sort algorithm and its companion function heapify.
void heapSort(int arr[], int n, long long int& compares);
void heapify(int arr[], int n, int i, long long int& compares);

// Function prototype for the function that is used to determine what type of dataset is being used, as each algorithm must
// be used 4 times with differing datasets that are specified in the project instructions.
void testDataset(int original[], int sort[]);

// Function prototype for the function that checks if an array is sorted before an algorithm runs its course.
bool is_sorted(int array[], int size);

// Defines MAX for 100,000 or 1,000 (100,000 for generating arrays, 1,000 for using a given data file)
//#define MAX 100000
#define MAX 1000

// Main Function
int main()
{
  // Constant Arrays - Holds the original datasets.
  int randomConst[MAX];
  /*
  int almostSortedConst[MAX];
  int reverseConst[MAX];
  int duplicateConst[MAX];
  */

  // Array Copies - Copies of datasets that are used in operations.
  int random[MAX];
  /*
  int almostSorted[MAX];
  int reverse[MAX];
  int duplicate[MAX];
  */

  // Dataset filling
  fillRandom(randomConst, MAX);
  /*
  fillAlmost(almostSortedConst);
  fillReverse(reverseConst);
  fillDuplicate(duplicateConst);
  */

  /*=====Randomly Distributed=====*/
  cout << "Randomly Distributed:" << endl;
  testDataset(randomConst, random);
  cout << endl
    << endl;
  /*==============================*/

 
  //These are commented out because we were instructed to use file i/o with one dataset of 1000 numbers.
  /*========Almost Sorted========*/
  //cout << "Almost Sorted:" << endl;
  //testDataset(almostSortedConst, almostSorted);
  //cout << endl
  // << endl;
  /*=============================*/

  /*========Reverse Sorted========*/
  //cout << "Reverse Sorted:" << endl;
  //testDataset(reverseConst, reverse);
  //cout << endl
  //  << endl;
  /*==============================*/

  /*========Lots of Duplicates========*/
  //cout << "Lots of Duplicates:" << endl;
  //testDataset(duplicateConst, duplicate);
  /*==================================*/
  return 0;
}

/*=======================FUNCTIONS START=======================*/

/*
  fillRandom: Function that will fill an array with random numbers from 1 to 1,000 for manipulation.
	      Uses file i/o to fill the array in from a given dataset of 1,000 numbers
  Precondition: Pass in the empty array and the size of the array.
  Postcondition: Array is filled to its entirety with random numbers.
*/

void fillRandom(int myArray[], int arraySize)
{
  //srand(time(0));
  fstream myFile;
  string filename;
  cout << "Enter filename: ";
  cin >> filename;
  myFile.open(filename);

  if (myFile.fail())
  {
    cerr << "Error opening file. Closing program." << endl;
    exit(1);
  }

  else
  {
    cout << "File successfully opened." << endl;
  }

  for (int i = 0; i < arraySize; i++)
  {
    myFile >> myArray[i];
  }
  
  myFile.close();
}

/*
  fillDuplicate: Function to fill an array with a multitude of duplicate numbers. Two indices are randomly generated,
     and a count variable is created. The array is iterated through, and checks the counter. If the counter
     reaches the first index, a certain number is inserted and count is increased. If the counter reaches
     the second index, a certain number is inserted and the count is reset. Otherwise a random number is
     inserted and the counter is increased.
  Precondition: Pass in the array.
  Postcondition: Array is filled with random numbers with multiple duplicate numbers.
*/

void fillDuplicate(int X[])
{
  int count = 1;
  srand(time(0));
  int randIndex1 = rand() % 100;
  int randIndex2 = rand() % 100;
  while (randIndex2 < randIndex1)
  {
    randIndex2 = rand() % 100;
  }
  for (int i = 0; i < MAX; i++)
  {
    if (count == randIndex1)
    {
      X[i] = 69;
      count++;
    }
    else if (count == randIndex2)
    {
      X[i] = 420;
      count = 1;
    }
    else
    {
      int numRand = rand() % 100000;
      X[i] = numRand;
      count++;
    }
  }
}

/*
  fillAlmost: Function to fill an array with numbers in such a way that it is almost fully sorted, but not fully.
  Precondition: Pass in the array to be filled.
  Postcondition: Fill the array with a random number every 20 spaces.
*/

void fillAlmost(int Y[])
{
  int count = 1;
  srand(time(0));
  // Loop until max size (100,000).
  for (int i = 0; i < MAX; i++)
  {
    if (count == 20)
    {
      int numRand = rand() % 100000;
      Y[i] = numRand;
      // Set counter to 1 to reset.
      count = 1;
    }
    else
    {
      Y[i] = i;
      count++;
    }
  }
}

/*
  fillReverse: Fucntion that just fills an array with numbers starting from the maximum elements possible in the array to 0.
  Precondition: Pass in the empty array, though it does not need to be empty and can overwrite any array input.
  Postcondition: The array will be filled in reverse order to be manipulated.
*/

void fillReverse(int Z[])
{
  // Max - 1 is 99,999 so from that to 0.
  int count = MAX - 1;
  for (int i = 0; i < MAX; i++)
  {
    Z[i] = count;
    count--;
  }
}

/*
  copyArray: Takes one array and copies its contents into another array.
  Precondition: Pass in two arrays, one with elements filled and one preferably empty.
  Postcondition: The second array becomes an exact copy of the first array.
*/

void copyArray(int original[], int copy[])
{
  for (int i = 0; i < MAX; i++)
  {
    copy[i] = original[i];
  }
}

/*
  printArray: Function that prints out an array.
  Precondition: Pass in array and size.
  Postcondition: Array is printed out.
*/

void printArray(int array1[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array1[i] << " ";
  }
  cout << endl
    << endl;
}

/*
  selectionSort: Function to sort an array and keep track of compares and swaps.
  Precondition: Pass in array, its size, a variable to hold the compares, and a counter for swaps.
  Postcondition: Array will be sorted and the two counters will be changed as needed with their value stored and output.
*/

void selectionSort(int array1[], int size, long long int& compares, long long int& swaps)
{
  int low, pass = 0;

  // Turned a for loop into a while loop to incorporate the is_sorted function to check if they array is ever sorted
  // before the algorithm has run its entire course.
  while (pass < size && !is_sorted(array1, size))
  {
    low = pass;
    for (int x = pass; x < size; x++)
    {
      // Compares counter before the compare as it will always run.
      compares++;
      if (array1[x] < array1[low])
      {
        low = x;
      }
    }
    // Swapping of variables.
    int temp = array1[pass];
    swaps++;
    array1[pass] = array1[low];
    swaps++;
    array1[low] = temp;
    swaps++;

    pass++;
  }
}

/*
  exchangeSort: Function to sort an array and keep track of compares and swaps.
  Precondition: Pass in array, its size, a variable to hold the compares, and a counter for swaps.
  Postcondition: Array will be sorted and the two counters will be changed as needed with their value stored and output.
*/

void exchangeSort(int array1[], int size,long long int& compares, long long int& swaps)
{
  int temp, i = 0;
  // Turned a for loop into a while loop to incorporate the is_sorted function to check if they array is ever sorted
  // before the algorithm has run its entire course.
  while (i < size - 1 && !is_sorted(array1, size))
  {
    for (int j = i + 1; j < size; j++)
    {
      // Compares counter before the compare as it will always run.
      compares++;
      if (array1[i] > array1[j])
      {
        // Swapping of variables.
        temp = array1[j];
        swaps++;
        array1[j] = array1[i];
        swaps++;
        array1[i] = temp;
        swaps++;
      }
    }
    i++;
  }
}

/*
  bubbleSort: Function to sort an array and keep track of compares.
  Precondition: Pass in array, its size, and a variable to hold the compares.
  Postcondition: Array will be sorted and thecounter will be changed as needed with its value stored and output.
*/

void bubbleSort(int array1[], int size, long long int& compares)
{
  int pass = 1;
  // Turned a for loop into a while loop to incorporate the is_sorted function to check if they array is ever sorted
  // before the algorithm has run its entire course.
  while (pass < size && !is_sorted(array1, size))
  {
    for (int x = 0; x < pass; x++)
    {
      // Compares counter before the compare as it will always run.
      compares++;
      if (array1[x] < array1[x + 1])
      {
        int temp = array1[x];
        array1[x] = array1[x + 1];
        array1[x + 1] = temp;
      }
    }
    pass++;
  }
}

/*
  insertionSort: Function to sort an array and keep track of compares.
  Precondition: Pass in array, its size, and a variable to hold the compares.
  Postcondition: Array will be sorted and the counter will be changed as needed with its value stored and output.
*/

void insertionSort(int arr[], int n, long long int& compares)
{
  int i = 1, key, j;
  // Turned a for loop into a while loop to incorporate the is_sorted function to check if they array is ever sorted
  // before the algorithm has run its entire course.
  while (i < n && !is_sorted(arr, n))
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
      // Compares for while in the loop.
      compares++;
    }
    // Single compare for when the while loop fails.
    compares++;
    arr[j + 1] = key;
    i++;
  }
}

/*
  mergeSort: Function to sort an array and keep track of compares.
  Precondition: Pass in array, its size, and a variable to hold the compares.
  Postcondition: Array will be sorted and the counter will be changed as needed with its value stored and output.
*/

void mergeSort(int x[], int left, int right, long long int& compares)
{
  // Added the condition of the loop not being sorted.
  if (left < right && !is_sorted(x, MAX))
  {
    int mid = (left + right) / 2;
    mergeSort(x, left, mid, compares);
    mergeSort(x, mid + 1, right, compares);
    merge(x, left, mid, right, compares);
  }
}

/*
  merge: Function that takes two arrays and combines them in correct order.
  Precondition: Pass in the array, left position, middle position, right postion, and compares.
  Postcondition: Array passed in is split apart and put back together in order.
*/

void merge(int x[], int left, int mid, int right, long long int& compares)
{
  int T[MAX];
  int L1 = left;
  int R1 = mid;
  int L2 = mid + 1;
  int R2 = right;
  int n = left;
  while (L1 <= R1 && L2 <= R2)
  {
    compares++;
    if (x[L1] < x[L2])
    {
      T[n++] = x[L1++];
    }
    else
      T[n++] = x[L2++];
  }
  while (L1 <= R1)
  {
    T[n++] = x[L1++];
    compares++;
  }
  compares++;
  while (L2 <= R2)
  {
    T[n++] = x[L2++];
    compares++;
  }
  for (int i = left; i <= right; i++)
    x[i] = T[i];
}

/*
  quickSort: Function that takes an array and sorts it while keeping track of compares using a global variable.
  Precondition: Pass in the low and high bounds along with the array.
  Postcondition: Function is sorted and counters tracked.
*/

void quickSort(int low, int high, int myarray[], long long int& compares)
{
  int pivotpoint;
  // Added condition to check if the array is sorted.
  if (high > low && !is_sorted(myarray, MAX))
  {
    partition(low, high, pivotpoint, myarray, compares);
    quickSort(low, pivotpoint - 1, myarray, compares);
    quickSort(pivotpoint + 1, high, myarray, compares);
  }
}

/*
  partition: Function that helps run the quick sort by comparing values and swapping.
  Precondition: Input low and high bounds with the pivotpot undetermined and the array itself.
  Postcondition: The middle variable's place is determined based on the step of the sort.
*/

void partition(int low, int high, int& pivotpoint, int myarray[], long long int& compares)
{
  int pivotitem = myarray[low];

  int j = low;
  for (int i = low + 1; i <= high; i++)
  {
    // Use of global variable for compares so that a segmentation fault is avoided.
    compares++;
    if (myarray[i] < pivotitem)
    {
      j++;
      swap(myarray[i], myarray[j]);
    }
  }
  pivotpoint = j;
  swap(myarray[low], myarray[pivotpoint]);
}

//orders elements of the array into a max heap (explained below)
void heapify(int arr[], int n, int i, long long int& compares)
{
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest])
    largest = l;
  compares++;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest])
    largest = r;
  compares++;

  // If largest is not root
  if (largest != i)
  {
    swap(arr[i], arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest, compares);
  }
}

// First orders all elements into a "max heap", a tree where the parent leaf is larger than its children leaves,
// it then goes through and swaps the first and last value of the heap, and because it is a max, this moves the largest element to the back.

void heapSort(int arr[], int n, long long int& compares)
{
  if (!is_sorted(arr, n))
  {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i, compares);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
      // Move current root to end
      swap(arr[0], arr[i]);

      // call max heapify on the reduced heap
      heapify(arr, i, 0, compares);
    }
  }
}

/* testDataset - Takes a dataset, tests it on different sorts, then prints out
                 a table with data collected from the tests.
   Precondition: Takes in an int array (original) and another int array (copy). The
                 "copy" array copies the values from the "original" array, so the
                 "original" array's order remains unchanged.
   Postcondition: A table will be outputted containing: sort name, time, compares,
                  and swaps.
*/

void testDataset(int original[], int sort[])
{
    // Swap Counters - Counts the number of swaps in these algorithms.
    long long int selectionSwaps = 0;
    long long int exchangeSwaps = 0;

    // Compare Counters - Counters to keep track of the compares.
    long long int selectionCompares = 0;
    long long int exchangeCompares = 0;
    long long int bubbleCompares = 0;
    long long int insertionCompares = 0;
    long long int mergeCompares = 0;
    long long int quickCompares = 0;
    long long int heapCompares = 0;

    /*Selection Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_s = std::chrono::system_clock::now();
    selectionSort(sort, MAX, selectionCompares, selectionSwaps);
    auto end_s = std::chrono::system_clock::now();
    std::chrono::duration<double> selection_time = end_s - start_s;

    /*Exchange Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_e = std::chrono::system_clock::now();
    exchangeSort(sort, MAX, exchangeCompares, exchangeSwaps);
    auto end_e = std::chrono::system_clock::now();
    std::chrono::duration<double> exchange_time = end_e - start_e;

    /*Bubble Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_b = std::chrono::system_clock::now();
    bubbleSort(sort, MAX, bubbleCompares);
    auto end_b = std::chrono::system_clock::now();
    std::chrono::duration<double> bubble_time = end_b - start_b;

    /*Insertion Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_i = std::chrono::system_clock::now();
    insertionSort(sort, MAX, insertionCompares);
    auto end_i = std::chrono::system_clock::now();
    std::chrono::duration<double> insertion_time = end_i - start_i;

    /*Merge Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_m = std::chrono::system_clock::now();
    mergeSort(sort, 0, MAX - 1, mergeCompares);
    auto end_m = std::chrono::system_clock::now();
    std::chrono::duration<double> merge_time = end_m - start_m;

    /*Quick Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_q = std::chrono::system_clock::now();
    quickSort(0, MAX - 1, sort, quickCompares);
    auto end_q = std::chrono::system_clock::now();
    std::chrono::duration<double> quick_time = end_q - start_q;

    /*Heap Sort*/
    copyArray(original, sort);
    // Time recording
    auto start_h = std::chrono::system_clock::now();
    heapSort(sort, MAX, heapCompares);
    auto end_h = std::chrono::system_clock::now();
    std::chrono::duration<double> heap_time = end_h - start_h;

    cout << setprecision(4) << showpoint << fixed;
    cout << setw(15) << "Sort Name" << setw(5) << "|" << setw(15) << "Time (Sec)" << setw(5) << "|" << setw(14) << "Compares" << setw(8) << "|" << setw(12) << "Swaps" << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Selection" << setw(5) << "|" << setw(15) << selection_time.count() << setw(5) << "|" << setw(17) << selectionCompares << setw(5) << "|" << setw(16) << selectionSwaps << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Exchange" << setw(5) << "|" << setw(15) << exchange_time.count() << setw(5) << "|" << setw(17) << exchangeCompares << setw(5) << "|" << setw(16) << exchangeSwaps << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Bubble" << setw(5) << "|" << setw(15) << bubble_time.count() << setw(5) << "|" << setw(17) << bubbleCompares << setw(5) << "|" << setw(12) << "(n/a)" << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Insertion" << setw(5) << "|" << setw(15) << insertion_time.count() << setw(5) << "|" << setw(17) << insertionCompares << setw(5) << "|" << setw(12) << "(n/a)" << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Merge" << setw(5) << "|" << setw(15) << merge_time.count() << setw(5) << "|" << setw(17) << mergeCompares << setw(5) << "|" << setw(12) << "(n/a)" << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Quick" << setw(5) << "|" << setw(15) << quick_time.count() << setw(5) << "|" << setw(17) << quickCompares << setw(5) << "|" << setw(12) << "(n/a)" << endl;
    cout << setfill('-') << setw(82) << "-" << setfill(' ') << endl;
    cout << setw(15) << "Heap" << setw(5) << "|" << setw(15) << heap_time.count() << setw(5) << "|" << setw(17) << heapCompares << setw(5) << "|" << setw(12) << "(n/a)" << endl;
}

/*
  is_sorted: Function that determines if an array is sorted or not by traversing it and finding any times
             where it isn't and returning false if so. It will return if it is sorted.
  Precondition: Pass in the array and its size.
  Postcondition: False or true is returned to beused in the other sorts.
*/

bool is_sorted(int array[], int size)
{
  // Any array of size 0 or 1 is sorted.
  if (size == 0 || size == 1)
  {
    return true;
  }

  for (int i = 0; i < size; i++)
  {
    // Should go from low to high, check if it isn't.
    if (array[i] > array[i + 1])
    {
      return false;
    }
  }

  return true;
}

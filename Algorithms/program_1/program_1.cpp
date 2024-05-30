/*
  Name: Elijah Sprung
  Date: 02/02/2022
  Class: CSC-2710-01

  Description: A program to implement multiple algorithms: sequential search, exchange sort, binary search,
               recursive Fibonacci to the nth term, and iterative Fibonacci to the nth term. All algorithms
               that use an array will have a randomly generated array used and all algorithms will have a
               counter to output how many operations take place.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <utility>

using namespace std;

/*
  Description: Function to sequentially search a randomly generated array that is unsorted. A search integer is input and
               then each item of the array is checked against that search integer to see if a match is found. If a match is
               found, the function will output the location of that find from positions 1-100 (the location +1 becuase of
               starting at 0). If a match is not found, -1 is output.

  Preconditions: Pass in the randomized array that is not sorted and is full of integers.

  Postconditions: The array is searched and if a match is found for the desired search item, the location output. If a match
                  is not found, then -1 is output. The function also outputs how many comparisons were made.
*/

void seq_search(int array[100]);

/*
  Description: Function to sort an array using an exchange method. The array will be traversed iteratively and if the array
                at position j is less than that at position i, they will be swapped. This will sort the array of integers
                from smallest to largest.

  Preconditions: The function must be called and an integer array of size 100 will be passed in. The array should not be sorted
                 before it is passed in, but it can be if the user chooses.

  Postconditions: The input array will be sorted from least to greatest.
*/

void ex_sort(int array[100]);

/*
  Description: Function to search an integer array of 100 elements for an integer that is provided by the user. The function
               only works on an array that is already sorted, so the function contains the code for an exchange sort that
               runs before the search. After the sort, the function sets the upper and lower bounds of the array based on the
               elements at the first and last position in the array (position 0 and 99). It then searches to see where the search
               item fits in those bounds and adjusts the bounds as needed until the search term is found. This cuts the need for
               multiple compares down to much less than it used to be with a sequential search.

  Precondition: Pass an array, either sorted or not, that has 100 integers. The user then must input an integer to search for.

  Postcondition: The function will either return the position of the term or -1 if the term is not in the array. The function
                 also tracks how many compares are made and outputs this.
*/

void bin_search(int array[100]);

/*
  Description: Function that asks for a nth term of the Fibonacci sequence and then calculates to that position and outputs it,
               using recursive math. The function recurses for every number of n except for 0 or 1, so essentially it breaks down
               the desired nth term into the addition of 0 and 1, which is extrememly inefficient and slow. The function counts
               how much addition is down and outputs this as well as the calculated number.

  Precondition: Pass in the position of the term to be found and a counter by reference that is to be output after the function
                is called.

  Postcondition: The calculated term at position n in the Fibonacci sequence is returned, and it along with how many additions were
                 made is output.
*/

int recurs_fibonacci(int n, int &counter);

/*
  Description: Function that Function that asks for a nth term of the Fibonacci sequence and then calculates to that position and outputs it,
               using iterative math. The function just three values: a, b, and c. a is the first number in the sequence and b is the second.
               c is their sum and the function simply repreats this until the nth position is reached with a + b being assigned to c,
               b being assigned to a, and c being assigned to b.

  Precondition: Call the function and input which position of the sequence is to be calculated.

  Postcondition: The calculated term at position n in the Fibonacci sequence is returned, and it along with how many additions were
                 made is output.
*/

void it_fibonacci();


/*
  Description: Simple function to fill an array with 100 random numbers with the values from 0-999. This is used to show the utility of the searches
               and sorts.

  Precondition: Integer array is declared with size of 100 and passed.

  Postcondition: The array is filled with random integers.
*/

void rand_array(int array[100]);

/*
  Description: Function to print out all the numbers of an array in a readable format.

  Precondition: Pass an array to print.

  Postcondition: Array is printed out for the user to see.
*/

void print_array(int array[100]);

/*
  Description: Function to print a line out for organization.

  Precondition: Function called.

  Postcondition: Line is printed on the screen and my sanity is kept.
*/

void line();

/*
  Description: Main function that tests all of the other functions used in the order of: seq_search, ex_sort, bin_search,
               recurs_fibonacci, and it_fibonacci. The rand_array function is used to generate a random array before
               either a sort or a search. The print_array function is used to show that the sort worked and was used in testing
               to make sure that the searches worked. The line function simply is used to output text to separate the use of
               the different algorithms.

  Preconditions: The program must be run.

  Postconditions: All of the algorithms will be run and their output will be shown.
*/

int main()
{
  int n, counter = 0;
  int array[100];

  rand_array(array);
  seq_search(array);

  line();

  rand_array(array);
  ex_sort(array);

  line();

  rand_array(array);
  bin_search(array);

  line();

  cout << "RECURSIVE FIBONACCI SEQUENCE" << endl << endl;
  cout << "To what number nth would you like to find of the Fibonacci sequence?" << endl << endl;
  cin >> n;
  cout << endl;
  cout << "The " << n << "th term of the Fibonacci sequence is: " << recurs_fibonacci(n - 1, counter) << endl << endl;
  cout << "The number of times 2 numbers were added together to make another in the sequence was: " << counter << endl << endl;

  line();

  it_fibonacci();

  return 0;
}

void rand_array(int array[100])
{
  srand(time(0));

  for (int i = 0; i < 100; i++)
  {
    array[i] = rand() % 999;
  }
}

void print_array(int array[100])
{
  for (int i = 0; i < 100; i++)
  {
    cout << array[i] << " ";

    if (i % 10 == 0 && i != 0)
    {
      cout << endl;
    }
  }

  cout << endl << endl;
}

void line()
{
  for (int i = 0; i < 50; i++)
  {
    cout << "-";
  }
  cout << endl << endl;
}

void seq_search(int array[100])
{
  int search, location = 0, counter = 0;

  cout << "SEQUENTIAL SEARCH" << endl << endl;

  cout << "What integer would you like to search for? The location from 1-100 will be returned if it exists, -1 if it does not." << endl << endl;
  cin >> search;
  cout << endl;

  while (location <= 99 && array[location] != search)
  {
    location++;
    counter++;
  }
  if (location > 99)
  {
    location = -2;
  }

  cout << "The location was: " << location + 1 << endl << endl;
  cout << "The amount of compares in the search was: " << counter << endl << endl;
}

void ex_sort(int array[100])
{
  cout << "EXCHANGE SORT" << endl << endl;

  cout << "Array Before:" << endl;
  print_array(array);

  for (int i = 0; i < 100; i++)
  {
    for (int j = i + 1; j < 100; j++)
    {
      if (array[j] < array[i])
      {
        swap(array[i], array[j]);
      }
    }
  }

  cout << "Array After:" << endl;
  print_array(array);
}

void bin_search(int array[100])
{
  cout << "BINARY SEARCH" << endl << endl;

  for (int i = 0; i < 100; i++)
  {
    for (int j = i + 1; j < 100; j++)
    {
      if (array[j] < array[i])
      {
        swap(array[i], array[j]);
      }
    }
  }

  int low = 0, high = 99, search, location = -2, mid, counter = 0;

  cout << "What integer would you like to search for? The location from 1-100 will be returned if it exists, -1 if it does not." << endl << endl;
  cin >> search;
  cout << endl;

  while (low <= high)
  {
    mid = (low + high) / 2;

    if (array[mid] == search)
    {
      location = mid;
      counter++;
    }
    else if (array[mid] < search)
    {
      low = mid + 1;
      counter++;
    }
    else
    {
      high = mid - 1;
      counter++;
    }
  }

  cout << "The location was: " << location + 1 << endl << endl;
  cout << "The amount of compares in the search was: " << counter << endl << endl;
}

int recurs_fibonacci(int n, int &counter)
{
  if (n < 2)
  {
    return n;
  }
  else
  {
    counter++;
    return (recurs_fibonacci(n - 1, counter) + recurs_fibonacci(n - 2, counter));
  }
}

void it_fibonacci()
{
  cout << "ITERATIVE FIBONACCI SEQUENCE" << endl << endl;

  int n, a = 0, b = 1, c = 0, counter = 0;

  cout << "To what number nth would you like to find of the Fibonacci sequence?" << endl << endl;
  cin >> n;
  cout << endl;

  for (int i = 0; i < n-1; i++)
  {
    c = a + b;
    a = b;
    b = c;
    counter++;
  }

  cout << "The " << n << "th term of the Fibonacci sequence is: " << a << endl << endl;
  cout << "The number of times 2 numbers were added together to make another in the sequence was: " << counter << endl << endl;
}
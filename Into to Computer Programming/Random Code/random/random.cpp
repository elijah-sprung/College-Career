/*
 Elijah Sprung
 CSC 1710-04
 09/30/2020
 home/students/esprung/csc1710/random
 The Fibonacci Sequence.
*/

#include <iostream>
using namespace std;

//Main function.
int main ()
{
    // Variables for the first 2 numbers, the current number, how far the user wants to go, and a coutner.
    double previous1, previous2, current, nthFibonacci, counter = 0;

    // Ask for the first 2 numbers and input them.
    cout << "What are the first two numbers of the Fibonacci Sequence? (or the first two from where you want to start)" << endl;
    cin >> previous1;
    cin >> previous2;

    // Ask where the user wants to go and input it.
    cout << "To what place of the Fibonacci Sequence would you like to go to?" << endl;
    cin >> nthFibonacci;

    // Loop until the desired number of Fibonacci is found.
    while (counter <= nthFibonacci)
    {
        // Do the math for the Fibonacci Sequence and increase the counter.
        current = previous2 + previous1;
        previous1 = previous2;
        previous2 = current;
        counter++;
    }

    // Output the number found at the desired place.
    cout << "The " << nthFibonacci << " place in the Fibonacci Sequence is " << current << endl;
}
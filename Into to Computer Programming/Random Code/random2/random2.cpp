/*
 Elijah Sprung
 CSC 1710-04
 09/30/2020
 home/students/esprung/csc1710/random
 Guessing game.
*/

#include <iostream>
#include <time.h>
using namespace std;

//Main function.
int main ()
{
    // Variables for the guess, actual number, a counter, and a boolean to control the loop.
    double num, guess, counter = 0;
    bool stopper = false;

    // Set the time to 0, then find a random number, and ask for the intial guess.
    srand(time(0));
    num = rand() % 1000 + 1;
    cout << "Enter your first guess for a number from 1 to 1000." << endl;

    // Loop until the guess is correct.
    while (stopper == false)
    {
        // Input guess and increase counter.
        cin >> guess;
        counter++;

        // Check for correct.
        if (guess == num)
        {
            // Print out congrats, number of guesses, and stop the loop.
            cout << "You are correct, the random number was " << num << "." << endl;
            cout << "It took you " << counter << " guesses." << endl;
            stopper = true;
        }
        // For guess too large.
        else if (guess > num)
        {
            // Statement that shows it.
            cout << "Your guess was too high, please try again!" << endl;
        }
        // For guess too small.
        else
        {
            // Statement that shows it.
            cout << "Your guess was too low, please try again!" << endl;
        }
    }
}
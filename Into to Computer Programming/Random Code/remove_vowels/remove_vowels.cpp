/*
 Elijah Sprung
 CSC 1710-04
 10/26/2020
 home/students/esprung/csc1710/vowels/remove_vowels.cpp
 Program to take a string and then take all of the values out of it.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to take all vowels out of a given string.
string remove_vowels(string input)
{
    // Loop for the entire length of the string.
    for (int LCV = 0; LCV < input.length(); LCV++)
    {
        // Check for values.
        if (input[LCV] == 'A' || input[LCV] == 'a' || input[LCV] == 'E' || input[LCV] == 'e' || input[LCV] == 'I' || input[LCV] == 'i' || input[LCV] == 'O' || input[LCV] == 'o' || input[LCV] == 'U' || input[LCV] == 'u')
        {
            // Erase the vowels.
            input.erase(LCV, 1);

            // Reset LCV so that multiple values in a row doesn't break it.
            LCV = 0;
        }
    }

    // Check one last time for the initial value because the previous loop does not check this.
    int LCV = 0;

    if (input[LCV] == 'A' || input[LCV] == 'a' || input[LCV] == 'E' || input[LCV] == 'e' || input[LCV] == 'I' || input[LCV] == 'i' || input[LCV] == 'O' || input[LCV] == 'o' || input[LCV] == 'U' || input[LCV] == 'u')
    {
        input.erase(LCV, 1);
    }

    return input;
}

//Main function.
int main ()
{
    // Input string.
    string in;

    // Ask for a string and enter it.
    cout << "Please enter your initial string." << endl;
    cin >> in;

    // Output the initial string.
    cout << "The initial string was: " << in << endl;
    
    // Call remove_vowels.
    in = remove_vowels(in);

    // Output the new string.
    cout << "The new string is: " << in << endl;
}
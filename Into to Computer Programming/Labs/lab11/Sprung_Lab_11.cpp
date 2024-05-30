/*
 Elijah Sprung
 CSC 1710-04
 11/05/2020
 home/students/esprung/csc1710/lab11/sorting.cpp
 Program to sort an array of integers using functions.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototypes for all of the different functions used.
int load_array (string file, int array []);
void print_array (int array_length, int array []);
void sort_array (int array_length, int array []);
double median (int array_length, int array[]);
int search_array (int array_length, int array[], int search_val);

// Global array to be manipulated.
int array [100];

//Main function.
int main ()
{
    // Variables for the file, array parameters, and the desired values.
    string file;
    int array_length, search_val, match_val;
    double median_val;

    // Ask for file name and input.
    cout << "Please enter the name of the file that you wish to open." << endl;
    cin >> file;

    // Find the length of the array and create it.
    array_length = load_array (file, array);
    
    // Print the array.
    print_array (array_length, array);

    // Sort and print the array.
    sort_array (array_length, array);

    // Find the median, maximum, and minimum values and output.
    median_val = median (array_length, array);
    cout << "The median value is " << median_val << endl;

    // Ask for a desired number and input.
    cout << "Please enter a non-negative integer that you wish to search for." << endl;
    cin >> search_val;

    // Search the array for the number of times the desired number appears and output.
    match_val = search_array (array_length, array, search_val);
    cout << "Number of occurrences of the integer " << search_val << ": " << match_val << endl;
}

// Function to load an array of numbers from a given file name.
int load_array (string file, int array [])
{
    // Set file variable.
    fstream inData;

    // Convert the file name to a c-string.
    file.c_str();

    // Open the file.
    inData.open(file);

    // Control variables.
    int i = 0, num;
    bool sentinal = false;

    // Input numbers until -1 is reached, but do not input -1.
    while (sentinal == false)
    {
        inData >> num;

        if (num != -1)
        {
            array[i] = num;
            i++;
        }
        else
        {
            sentinal = true;
        }
    }

    // Close the file.
    inData.close();

    // Return the number of numbers put in the array.
    return i;
}

// Function to print out an array.
void print_array (int array_length, int array [])
{
    // Loop for the entire array and print out each value.
    for (int i = 0; i < array_length; i++)
    {
        cout << array [i] << " ";
    }
    cout << endl;
}

// Function to sort an array.
void sort_array (int array_length, int array [])
{
    // Variables for loop control.
    int placeholder, counter = 0;
    bool sentinal = false;

    // Loop until there are no switches.
    while (sentinal == false)
    {
        // Reset counter at start.
        counter = 0;

        // Loop through array.
        for (int i = 0; i < array_length - 1; i++)
        {
            // Sort from lowest to highest.
            if (array [i] > array [i + 1])
            {
                placeholder = array [i];
                array [i] = array [i + 1];
                array [i + 1] = placeholder;
                counter++;
            }
        }

        // Check for no switches.
        if (counter == 0)
        {
            sentinal = true;
        }
    }

    // Print out the array.
    print_array (array_length, array);
}

// Function to find the median, minimum, and maximum.
double median(int array_length, int array [])
{
    // Variables for the middle place and output.
    int side_1, side_2, middle;
    double output;    

    // Check for even or odd number of elements in array and then calculate median.
    if (array_length % 2 == 0)
    {
        side_1 = (array_length / 2);
        side_2 = (array_length / 2) - 1;

        output = (static_cast<double>(array [side_1]) + static_cast<double>(array [side_2])) / 2;
    }
    else
    {
        middle = (array_length / 2) + 0.5;

        output = array [middle];
    }

    // Print out minimum and maximum and then return median.
    cout << "The minimum value is " << array[0] << endl;
    cout << "The maximum value is " << array[array_length - 1] << endl;
    return output;
}

// Function to seach an array for a specific value.
int search_array (int array_length, int array[], int search_val)
{
    // Output variable.
    int output = 0;

    // Loop for the whole array, check for a specific value, and count it.
    for (int i = 0; i < array_length; i++)
    {
        if (array[i] == search_val)
        {
            output++;
        }
    }

    // Retrun the number of times a specific number occurs.
    return output;
}   
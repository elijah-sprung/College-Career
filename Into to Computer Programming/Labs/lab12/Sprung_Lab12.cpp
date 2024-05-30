/*
 Elijah Sprung
 CSC 1710-04
 11/12/2020
 home/students/esprung/csc1710/lab12/exercise_2.cpp
 Program that reads students' names followed by their test scores and then outputs their name and relevant grade.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Structure with first name, last name, test score, and grade.
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Array filled with structures of studentType.
studentType students [20];

// Functions to load the data, find the letter grades, find the highest score, and find the student(s) with the highest score.
void load_data (string file);
void find_grade ();
int highest_score ();
void high_score_students (int highest);

//Main function.
int main ()
{
    // Variable for the file name and the highest score.
    string file;
    int high_score;

    // Ask for file name and input.
    cout << "From what file would you like to load the information?" << endl;
    cin >> file;

    // Load the data in and find all the letter grades.
    load_data (file);
    find_grade ();

    // Find the highest score and the students with that score.
    high_score = highest_score ();
    high_score_students (high_score);

    // Return statement.
    return 0;
}

// Function to load data from a file given its name as a string.
void load_data (string file)
{
    // Open the input stream.
    fstream inData;

    // Turn the file name to a c-string.
    file.c_str();

    // Open the file.
    inData.open(file);

    // Loop through the whole array and input names and test scores.
    for (int i = 0; i < 19; i++)
    {
        inData >> students [i].studentFName;
        inData >> students [i].studentLName;
        inData >> students [i].testScore;
    }

    // Close the file.
    inData.close();
}

// Function to give out a letter grade to each student basted on their test score.
void find_grade ()
{
    for (int i = 0; i < 19; i++)
    {
        if (students [i].testScore >= 90 && students [i].testScore <= 100)
        {
            students [i].grade = 'A';
        }
        else if (students [i].testScore >= 80 && students [i].testScore <= 89)
        {
            students [i].grade = 'B';
        }
        else if (students [i].testScore >= 70 && students [i].testScore <= 79)
        {
            students [i].grade = 'C';
        }
        else if (students [i].testScore >= 50 && students [i].testScore <= 69)
        {
            students [i].grade = 'D';
        }
        else if (students [i].testScore < 50)
        {
            students [i].grade = 'F';
        }
    }

    // Output all of the information for all of the students.
    cout << setw (30) << left << "Student Name" << setw (10) << left << "Test Score" << setw (10) << right << "Grade" << endl;

    for (int i = 0; i < 19; i++)
    {
        cout << setw (30) << left << students [i].studentLName + ", " + students [i].studentFName << setw (10) << right << students [i].testScore << setw (10) << right << students [i].grade << endl;
    }
}

// Function to find the highest score.
int highest_score ()
{
    // Start with the first score.
    int highest = students [0].testScore;

    // Loop through the rest of the array and find the highest score.
    for (int i = 1; i < 19; i++)
    {
        if (highest < students [i].testScore)
        {
            highest = students [i].testScore;
        }
    }

    // Output the highest score and return it.
    cout << endl << "The highest test score was a " << highest << "." << endl;

    return highest;
}

// Function to print out of the students that have the highest score.
void high_score_students (int highest)
{
    cout << endl << "The student(s) with the highest score are: " << endl;

    for (int i = 0; i < 20; i++)
    {
        if (students [i].testScore == highest)
        {
            cout << students [i].studentLName + ", " + students [i].studentFName << endl;
        }
    }
}
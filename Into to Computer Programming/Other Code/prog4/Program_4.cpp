/*
 Elijah Sprung
 CSC 1710-04
 Date
 home/students/esprung/csc1710/prog4/golf.cpp
 Program to open a file and take in the data for a golf score sheet, and then format it to find the winner and add other details.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Array for the par scores.
int par_scores [18];

// Structure for all of the data on the score card.
struct golf_data
{
    string name;
    int score [18];
    int total_score;
    int front_nine;
    int back_nine;
    int golf_score;
    string symbols [18];
};

// Array full of structs.
golf_data players [4];

// Functions used to find all of the data on the score card.
void load_data (string file);
void find_scores ();
void find_the_nines ();
void find_golf_scores ();
int find_winner ();
void add_symbols ();

//Main function.
int main ()
{
    // Variables to be manipulated.
    string file;
    int winner;

    // Ask for input file name and input.
    cout << "From what file would you like to pull your data from?" << endl;
    cin >> file;

    // Load the data, find all scores, find the winner, and add extra symbols.
    load_data (file);
    find_scores ();
    winner = find_winner ();
    add_symbols ();

    // Print out names, total score, and the front and back nine scores.
    for (int i = 0; i < 4; i++)
    {
        cout << setw (10) << right << players [i].name << setw (5) << right << players [i].total_score << setw (5) << right << "(" << players [i].front_nine << "  -  " << players [i].back_nine << ")" << endl;
    }
    
    // Print out the winner.
    cout << endl << players [winner].name << " was the winner with a score of " << players [winner].golf_score << "." << endl << endl;

    cout << setw (11) << "";

    // Show the number for each hole.
    for (int i = 1; i < 19; i++)
    {
        cout << setw (4) << left << i;
    }

    // Title for scores.
    cout << setw (5) << right << "Score" << endl;

    // Print out names, the score for each hole with its designated symbol, and the total score.
    for (int i = 0; i < 4; i++)
    {
        cout << setw (10) << right << players [i].name;

        for (int j = 0; j < 18; j++)
        {
            cout << setw (2) << right << players [i].score [j] << setw (2) << left << players [i].symbols [j];
        }

        cout << setw (5) << right << players [i].total_score << endl;
    }

    // Return statement.
    return 0;
}

// Function to read in the data from a file.
void load_data (string file)
{
    // Open input stream.
    fstream inData;

    // Make the file name a c-string.
    file.c_str ();

    // Open the file.
    inData.open (file);

    // Input par scores.
    for (int i = 0; i < 18; i++)
    {
        inData >> par_scores [i];
    }

    // Input player names.
    for (int i = 0; i < 4; i++)
    {
        inData >> players [i].name;
    }

    // Input player scores.
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            inData >> players [j].score [i];
        }
    }
}

// Function to find all scores.
void find_scores ()
{
    // Total score value.
    int total;

    // Find the total score for each player.
    for (int i = 0; i < 4; i++)
    {
        total = 0;

        for (int j = 0; j < 18; j++)
        {
            total = total + players [i].score [j];
        }

        players [i].total_score = total;
    }

    // Find the scores for the front and back nines along with the scores according to the par score.
    find_the_nines ();
    find_golf_scores ();
}

void find_the_nines ()
{
    // Variables for totals.
    int front_total, back_total;

    // Find the front nine scores for each player.
    for (int i = 0; i < 4; i++)
    {
        front_total = 0;

        for (int j = 0; j < 9; j++)
        {
            front_total = front_total + players [i].score [j];
        }

        players [i].front_nine = front_total;
    }

    // Find the back nine scores for each player.
    for (int i = 0; i < 4; i++)
    {
        back_total = 0;

        for (int j = 9; j < 18; j++)
        {
            back_total = back_total + players [i].score [j];
        }

        players [i].back_nine = back_total;
    }
}

// Function to find the scores according to the par score.
void find_golf_scores ()
{
    // Total variable.
    int total;

    // Find the scores for each player according to the par score.
    for (int i = 0; i < 4; i++)
    {
        total = 0;

        for (int j = 0; j < 18; j++)
        {
            total = total + (players [i].score [j] - par_scores [j]);
        }

        players [i].golf_score = total;
    }
}

// Function to find the winner.
int find_winner ()
{
    // Output variable.
    int output = 0;

    // Find which player had the lowest score.
    for (int i = 0; i < 4; i++)
    {
        if (players [output].golf_score > players [i].golf_score)
        {
            output = i;
        }
    }

    // Return the value of the winner.
    return output;
}

// Function to add a symbol based on the score and the par score.
void add_symbols ()
{
    // Add a symbol for birdies and eagles for every score a player has.
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (players [i].score [j] == par_scores [j] - 1)
            {
                players [i].symbols [j] = "*";
            }
            else if (players [i].score [j] == par_scores [j] - 2)
            {
                players [i].symbols [j] = "!";
            }
            else
            {
                players [i].symbols [j] = "";
            }
            
        }
    }
}
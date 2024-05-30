/*
 Elijah Sprung
 CSC 1710-04
 11/03/2020
 home/students/esprung/csc1710/prog3/Sprung_Hangman_Grade100
 My attempt at a 100% on creating a program that runs the game hangman.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

// Constants for use.
int guesses = 0, incorrect_guesses = 0;
char guess_array [30], user_guess_array [30];
bool correct = false, incorrect = false;
string user_guess_string;

// Three functions for the entire game.
string select_word (string file = "inData.txt");
void run_game (string word);
void drawing ();

// Main function.
int main ()
{
    // File and the word to be guessed.
    string file, word;

    // Ask for file name and input.
    cout << "Welcome to the game Hangman! Please enter the file name that you wish to select your words from." << endl;
    cin >> file;

    // Call select_word and then run the game with the word that was found.
    word = select_word (file);
    run_game (word);

    // Return statement.
    return 0;
}

// Function to select a random word out of 30 choices given a file name.
string select_word (string file)
{
    // Input stream.
    fstream inData;

    // Create a word bank and variables to be manipulated.
    string word_bank [30], output;
    int rand_num;

    // Change the file name to a c-string.
    file.c_str();

    // Open the file.
    inData.open(file);

    // Loop 30 times and input the 30 words.
    for (int i = 0; i < 30; i++)
    {
        inData >> word_bank [i];
    }

    // Randomly select one word.
    srand(time(0));
    rand_num = rand() % (30);

    // Make the output the random word selected.
    output = word_bank [rand_num];

    // Close the file.
    inData.close();

    // Return the chosen word.
    return output;
}

// Function the run hangman when given a word.
void run_game (string word)
{
    // Variables to be manipulated.
    char letter_guess;
    bool status;

    // Output word length.
    cout << "The word that you must guess has " << word.length() << " letters!" << endl;

    // For the entire word length, fill the user's guess array with underscores.
    for (int i = 0; i < word.length(); i++)
    {
        user_guess_array [i] = '_';
    }

    // Loop until either the user wins or loses.
    while (correct == false && incorrect == false)
    {
        // Set the correct status to false.
        status = false;

        // Ask for a letter, input it, store it in the guess array, increase guesses, and increase incorrect guesses.
        cout << "Please guess a letter." << endl;
        cin >> letter_guess;
        guess_array [guesses] = letter_guess;
        guesses++;
        incorrect_guesses++;

        // Loop for the entire word, check if the letter guessed is in the word and if so, place that letter into the guess array and set correct status to true.
        for (int i = 0; i < word.length(); i++)
        {
            if (letter_guess == word [i])
            {
                user_guess_array [i] = letter_guess;
                status = true;
            }
        }

        // Loop for the amount of guesses - 1, check if the letter entered has been entered previously and if so, remove all penalties.
        for (int i = 0; i < (guesses - 1); i++)
        {
            if (letter_guess == guess_array [i])
            {
                cout << "You have entered a letter that was entered previously, this has not counted against you." << endl;
                
                guess_array [guesses] = {};
                guesses--;
                incorrect_guesses--;
                status = false;
            }
        }

        // Check if the guess was correct and if so, decrease the incorrect guesses.
        if (status == true)
        {
            incorrect_guesses--;
        }

        // Output the word, as guessed so far.
        cout << "Your current guess is: ";

        for (int i = 0; i < word.length(); i++)
        {
            cout << user_guess_array [i];
        }

        // Output all of the letters that the user has guessed.
        cout << endl << "These are your letters guessed: ";

        for (int i = 0; i < guesses; i++)
        {
            cout << guess_array [i];
        }

        // Ouput number of guesses and incorrect guesses.
        cout << endl << "You have made " << guesses << " guesses and " << incorrect_guesses << " incorrect guesses." << endl;

        // Check if they made an incorrect guess, and then draw the hangman.
        if (status == false)
        {
            drawing ();
        }

        // Check if they have 10 incorrect guesses, and then end the game.
        if (incorrect_guesses == 10)
        {
            incorrect = true;
        }

        // Erase the guess string.
        user_guess_string.erase();

        // Fill the guess string with the characters in the user guess array.
        for (int i = 0; i < word.length(); i++)
        {
            user_guess_string.append(1, user_guess_array [i]);
        }

        // Check if the user guess string is equivalent to the initial word and if so, end the game and say that they have won.
        if (user_guess_string == word)
        {
            correct = true;
            cout << "You have won!" << endl;
        }
    }
}

// Function to draw each part of the hangman based on how many incorrect guesses the user has made while also outputting which part has been drawn.
void drawing ()
{
    if (incorrect_guesses == 1)
    {
        cout << "The head has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       /     \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 2)
    {
        cout << "The torso has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       /     \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 3)
    {
        cout << "The left arm has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       /     \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|         " << endl;
        cout << "|          |         " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 4)
    {
        cout << "The right has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       /     \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|                    " << endl;
        cout << "|                    " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 5)
    {
        cout << "The left leg has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       /     \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|         /          " << endl;
        cout << "|        /           " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 6)
    {
        cout << "The right leg has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       /     \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|         / \\        " << endl;
        cout << "|        /   \\       " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 7)
    {
        cout << "The left eye has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       / 0   \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|         / \\        " << endl;
        cout << "|        /   \\       " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 8)
    {
        cout << "The right eye has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       / 0 0 \\      " << endl;
        cout << "|      |       |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|         / \\        " << endl;
        cout << "|        /   \\       " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 9)
    {
        cout << "The nose has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       / 0 0 \\      " << endl;
        cout << "|      |   o   |     " << endl;
        cout << "|       \\     /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|         / \\        " << endl;
        cout << "|        /   \\       " << endl;
        cout << "_____________________" << endl;
    }
    else if (incorrect_guesses == 10)
    {
        cout << "The frown has been drawn!" << endl;
        cout << " ___________         " << endl;
        cout << "/          |         " << endl;
        cout << "|          |         " << endl;
        cout << "|         ___        " << endl;
        cout << "|       / X X \\      " << endl;
        cout << "|      |   o   |     " << endl;
        cout << "|       \\ /-\\ /      " << endl;
        cout << "|         ---        " << endl;
        cout << "|          |         " << endl;
        cout << "|     -----|-----    " << endl;
        cout << "|          |         " << endl;
        cout << "|         / \\        " << endl;
        cout << "|        /   \\       " << endl;
        cout << "_____________________" << endl;
        cout << "You have lost!";
    }
}
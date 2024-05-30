/*
  Elijah Sprung
  01/12/2021
  CSC 1720-03
  home/students/esprung/csc1720/lab_1/lab_1_soccer_data.cpp

  This program takes a datafile and inputs all of the data for multiple players,
  counts how many players were input, and then outputs all of the data in a
  readable form while also calculating the percentage of shots made.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
  Struct used for each player, which contains a variable for the player's name,
  position, games played, goals, shots made, and minutes played.
*/

struct player_type
{
  string name;
  string position;
  int games_played;
  int goals;
  int shots_made;
  int minutes_played;
};

/*
  Function prototypes for the functions to load the player data from a file
  and to print out the data in an organized and readable form.
*/

int load_data(player_type& player);
void print_data(player_type players[], int num_players);

/*
  This is the main funciton that runs all of the code used.
  There are no preconditions other than that it must be run.
  The postcondition is that it will return 0 to close off the program.
*/

int main()
{
  /*
    Declaration of an array of 30 structs for player data along with an integer
    for the number of players and a placeholder for counting.
  */

  player_type players[30];
  int num_players = 0, placeholder;

  /*
    Loop through all of the possible elements of the array and load in all of
    the data, while also keeping track of how many players have been entered
    for use later.
  */
  
  for (int i = 0; i < 29; i++)
  {
    placeholder = load_data(players[i]);
    num_players = num_players + placeholder;
  }

  /*
    Print out all of the data using the array and the number of players - 1
    to account for base 0. Then return
  */

  print_data(players, num_players - 1);

  return 0;
}

/*
  This function loads in all of the data from the given datafile for the struct
  and returns whether or not an actual player was loaded for the counter.
  This funciton requires an empty struct to be passed to it for the precondition.
  It also returns either a 1 or a 0 to be added to the total amount of players,
  based on whether or not the first string input was NULL or not.
*/

int load_data(player_type& player)
{
  /*
    Use a counter to check for when a player in input and only input all of
    the data for a single player if the file has not ended. Return the coutner.
  */

  int counter = 0;

  if (cin)
  {
    cin >> player.name;
    cin >> player.position;
    cin >> player.games_played;
    cin >> player.goals;
    cin >> player.shots_made;
    cin >> player.minutes_played;

    counter++;
  }

  return counter;
}

/*
  This function prints out all of the data in an array full of structs.
  The function requires the array of structs and the number of players total.
  It only outputs the data in textual form, but it does not return antything.
*/

void print_data(player_type players[], int num_players)
{
  /*
    Print out the heading for all of the data.
  */

  cout << "HPU Women's Soccer Stats" << endl;
  cout << left << setw(10) << "Name" << left << setw(15) << "Position" <<
  right << setw(5) << "GP" << right << setw(5) << "G" << right << setw(5) <<
  "ST" << right << setw(5) << "Mins" << right << setw(10) << "Shot" << "%" << endl;

  /*
    Loop for all of the players and print out their data, but check if there
    were no shots made so that the program will not divide by 0 and break.
  */

  for (int i = 0; i < num_players; i++)
  {
    cout << left << setw(10) << players[i].name << left << setw(15) <<
    players[i].position << right << setw(5) << players[i].games_played <<
    right << setw(5) << players[i].goals << right << setw(5) <<
    players[i].shots_made << right << setw(5) << players[i].minutes_played;

    if (players[i].shots_made != 0)
    {
      cout << right << setw(10) << setprecision(3) <<
      (static_cast<double>(players[i].goals) /
      static_cast<double>(players[i].shots_made)) * 100 << "%" << endl;
    }
    else
    {
      cout << right << setw(11) << "0.0%" << endl;
    }
  }
}
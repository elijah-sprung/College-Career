/*
  Name: Elijah Sprung
  Date: 03/22/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_3/main.cpp

  About: Program to take a given data file and input all of the names inside,
         randomly select 4 unique winners for the fisrt 4 prizes, prompt the
         user for the cost per ticket and the total expenses, and calculate
         and output the profit from the fundraiser using all the files from
         Lab 8 as templates.

  Compilation Line:

  g++ -Wall main.cpp -o prog3Test

  Run Command:

  ./prog3Test
*/

/*
  Got a great divide by 0 error if only 4 people join the raffle because there are 5 prizes, stumped me for at least an hour.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "uniqueListType.h"

using namespace std;

void loadData(unorderedArrayListType<string>& nameList);
int randPerson(const unorderedArrayListType<string>& nameList);
void removeWinner(unorderedArrayListType<string>& nameList, const string name);
string findGrandWinner(uniqueListType<string>& nameList);
string findWinner(unorderedArrayListType<string>& nameList);
void findProfits(const int numTickets);

/*
  main: Function to run the raffle using all of the predefined functions.
  precondition: Program run.
  postcondition: Return 0.
*/
int main()
{
  //Seed time and set up variables.
  srand(time(0));
  string name;
  int numTickets;

  //Create unordered list and load data and then create its unique copy.
  unorderedArrayListType<string> repeatList(1000);
  loadData(repeatList);

  uniqueListType<string> uniqueList(repeatList);
  
  //Find and output number of tickets purchased.
  numTickets = repeatList.listSize();
  cout << "Number of tickets purchased: " << numTickets << endl;

  //Find and output winners for all prizes.
  name = findGrandWinner(uniqueList);
  removeWinner(repeatList, name);
  removeWinner(uniqueList, name);
  cout << "The Grand Prize winner was: " << name << endl;

  name = findWinner(repeatList);
  removeWinner(repeatList, name);
  removeWinner(uniqueList, name);
  cout << "The winner of the Dinner for Two at Blue Water Grille: " << name << endl;

  name = findWinner(repeatList);
  removeWinner(repeatList, name);
  removeWinner(uniqueList, name);
  cout << "The winner of the Set of Four Passes to Wet N Wild: " << name << endl;

  name = findWinner(repeatList);
  removeWinner(repeatList, name);
  removeWinner(uniqueList, name);
  cout << "The winner of the $100 Amazon Gift Card: " << name << endl;

  name = findWinner(repeatList);
  removeWinner(repeatList, name);
  removeWinner(uniqueList, name);
  cout << "The winner of the Set of Four Movie Passes at the Palladium Regal Theater: " << name << endl << endl;

  //Find total profits.
  findProfits(numTickets);

  return 0;
}

/*
  loadData: Function to load in data from a given file when asked for file name.
  precondition: Pass array for data to be loaded in to.
  postcondition: Array initialized.
*/

void loadData(unorderedArrayListType<string>& nameList)
{
  ifstream file;
  string fileName, firstName, lastName, name;

  cout << "Enter the name of the file full of names you wish to open:";
  cin >> fileName;
  cout << endl;
  
  file.open(fileName);
  
  if (file)
  {
    file >> firstName;
    file >> lastName;
    
    if (firstName != "" && lastName != "")
    {
      name = firstName + " " + lastName;
      nameList.insertEnd(name);

      while (!file.eof())
      {
        file >> firstName;
        file >> lastName;
        
        name = firstName + " " + lastName;
        nameList.insertEnd(name);
      }
    }
  }

  file.close();
}

/*
  randPerson: Function to find a random person from the unordered list.
  precondition: Pass the unordered name list.
  postcondition: Place of person returned.
*/

int randPerson(const unorderedArrayListType<string>& nameList)
{
  int randNum = rand();

  return (randNum % nameList.listSize());
}

/*
  removeWinner: Function to take a winner out of the list.
  precondition: Pass the unordered name list and the winner's name.
  postcondition: Winner removed from list.
*/

void removeWinner(unorderedArrayListType<string>& nameList, const string winner)
{
  while (nameList.seqSearch(winner) != -1)
  {
    nameList.removeAt(nameList.seqSearch(winner));
  }
}

/*
  randPerson: Function to find the winner of the Grand Prize.
  precondition: Pass the unique name list.
  postcondition: Name of winner returned.
*/

string findGrandWinner(uniqueListType<string>& nameList)
{
  string name;

  name = nameList.getAt(randPerson(nameList));
  return name;
}

/*
  randPerson: Function to find the winner for other prizes.
  precondition: Pass the unordered name list.
  postcondition: Name of winner returned.
*/

string findWinner(unorderedArrayListType<string>& nameList)
{
  string name;
  
  name = nameList.getAt(randPerson(nameList));
  return name;
}

/*
  findProfits: Function to calculate the amount made based on input for cost
               of tickets and total spent.
  precondition: Number of tickets passed.
  postcondition: Total amount made output.
*/

void findProfits(const int numTickets)
{
  double ticketCost, spent, made;

  cout << "Enter the cost per ticket: $";
  cin >> ticketCost;

  cout << "Enter total cost: $";
  cin >> spent;

  made = (ticketCost * numTickets) - spent;

  cout << "The total made was: $" << made;
}
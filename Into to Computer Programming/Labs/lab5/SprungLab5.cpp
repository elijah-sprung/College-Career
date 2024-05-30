/*
 Elijah Sprung
 CSC 1710-04
 09/21/2020
 home/students/esprung/csc1710/lab5/programmingExercise.cpp
 Program to test out reading information from a file.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Main function.
int main ()
{
    //Declares the variables for the files.
    ifstream inData;
    ofstream outData;

    //Declares the variables that will be input and used.
    string first, last, department;
    double salary, bonus, taxes, paycheck, distance, time, speed, numCups, cost, sales;

    //Opens the files and shows 2 decimal points.
    inData.open("inData.txt");
    outData.open("outData.txt");
    cout << fixed << setprecision(2) << endl;

    //Ask for the full name and department and then outputs it readably.
    inData >> first;
    inData >> last;
    inData >> department;

    cout << "Name: " << first << " " << last << ", Department: " << department << endl;

    //Inputs salary, bonus, and tax amount, and then calculates total paycheck and outputs it readably.
    inData >> salary;
    inData >> bonus;
    inData >> taxes;
    paycheck = salary + ((bonus / 100) * salary) - ((taxes / 100) * salary);

    cout << "Monthly Gross Salary: $" << salary << ", Monthly Bonus: " << bonus << "%, Taxes:" << taxes << "%" << endl;
    cout << "Paycheck: $" << paycheck << endl;

    //Inputs distance and time, calculates speed, and outputs these readably.
    inData >> distance;
    inData >> time;
    speed = distance / time;

    cout << "Distancce Traveled: " << distance << " miles, Traveling Time: " << time << " hours" << endl;
    cout << "Average Speed: " << speed << " miles per hour" << endl;

    //Inputs the number of cups sold and their cost, calculates the total sales, and outputs it readably.
    inData >> numCups;
    inData >> cost;
    sales = numCups * cost;

    cout << "Number of Coffee Cups Sold: " << setprecision(0) << numCups << ", Cost: $" << setprecision(2) << cost << " per cup" << endl;
    cout << "Sales Amount = $" << sales << endl;

    //Close the input and output files.
    inData.close();
    outData.close();
}
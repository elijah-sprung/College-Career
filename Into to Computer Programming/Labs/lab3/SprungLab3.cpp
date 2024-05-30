/*
 Elijah Sprung
 CSC 1710-04
 09/03/2020
 home/students/esprung/csc1710/lab3/gradesB.cpp
 A program to take a certain number of grades and then use weighted averages to create a final grade.
*/

#include <iostream>
using namespace std;

//Main function.
int main ()
{
    //Variables for each of the grades to input.
    double lab1;
    double lab2;
    double lab3;
    double lab4;
    double quiz1;
    double quiz2;
    double quiz3;
    double program1;
    double test1;

    //Ask for all of the values for each of the different types of grades.
    //cout << "Enter your first lab grade:" << endl;
    cin >> lab1;

    //cout << "Enter your second lab grade:" << endl;
    cin >> lab2;

    //cout << "Enter your third lab grade:" << endl;
    cin >> lab3;

    //cout << "Enter your fourth lab grade:" << endl;
    cin >> lab4;

    //cout << "Enter your first quiz grade:" << endl;
    cin >> quiz1;

    //cout << "Enter your second quiz grade:" << endl;
    cin >> quiz2;

    //cout << "Enter your third lab grade:" << endl;
    cin >> quiz3;

    //cout << "Enter your program grade:" << endl;
    cin >> program1;

    //cout << "Enter your test grade:" << endl;
    cin >> test1;

    //Create a variable and calculate the weighted average using all of the grades.
    double total = ((((lab1 + lab2 + lab3 + lab4) / 40) * 0.1) + (((quiz1 + quiz2 + quiz3) / 30) * 0.1) + ((program1 / 100) * 0.3) + ((test1 / 100) * 0.3)) / 0.80 * 100;

    //Print out the total.
    cout << "Your final grade is " << total << "%" << endl;
}
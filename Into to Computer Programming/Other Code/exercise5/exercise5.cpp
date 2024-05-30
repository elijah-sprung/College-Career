/*
 Elijah Sprung
 CSC 1710-04
 09/30/2020
 home/students/esprung/csc1710/exercise5
 Program to tell whether or not a triangle is a right triangle when the three lengths are entered.
*/

#include <iostream>
#include <cmath>
using namespace std;

//Main function.
int main ()
{
    // Variables for the 3 sides.
    double a, b, c;

    // Ask for the 3 sides in order and input them.
    cout << "Enter the three lengths to a triangle, with the first two numbers being the small sides and the third number being the largest number value." << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    // Calculate each of the sides to the power of 2.
    a = pow(a, 2);
    b = pow(b, 2);
    c = pow(c, 2);

    // Check for the pythagorean theorem.
    if (a + b == c)
    {
        cout << "The triange is a right triangle." << endl;
    }
    else
    {
        cout << "The triange is not a right triangle." << endl;
    }
    
}
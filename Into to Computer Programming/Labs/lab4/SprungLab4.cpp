/*
 Elijah Sprung
 CSC 1710-04
 09/10/2020
 home/students/esprung/csc1710/lab4/compilerMath.out
 A program to do math and then output answers using given variables.
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Main function.
int main ()
{
    //Variables for math.
    int p = 17, q = 4, r = 3;
    double j = 3.00, k = 5.00;

    //Show all of the zeros in every number.
    cout << showpoint << endl;

    //All of the math with descriptions.
    cout << "p - q * r = " << p - q * r << endl;
    cout << "p / r = " << p / r << endl;
    cout << "p % r = " << p % r << endl;
    cout << "p / q / r = " << p / q / r << endl;
    cout << "q + r % p = " << q + r % p << endl;
    cout << "q * j / p = " << q * j / p << endl;
    cout << "p / q / j = " << p / q / j << endl;
    cout << "p / j / q = " << p / j / q << endl;
    k = k / (r / q);
    cout << "k /= r / q, k = " << k << endl;
    cout << "j / -q = " << j / (-1 * q) << endl;
    cout << "Area of a triangle with a base of p and hieght of r = " << (0.5 * p) * r << endl;
}
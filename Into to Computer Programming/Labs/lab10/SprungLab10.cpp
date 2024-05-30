/*
 Elijah Sprung
 CSC 1710-04
 10/22/2020
 home/students/esprung/csc1710/lab10/more_functions.cpp
 A program to demonstrate mastery of functions using different mathematical equations.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Constant for the number pi.
const double PI = 3.14159265358979323846;

// Prototypes for all of the functions to be called.
double distance(double x1, double y1, double x2, double y2);
double distance(double x2, double y2);
double radius(double x1, double y1, double x2, double y2);
double radius(double x2, double y2);
double circumference(double x1, double y1, double x2, double y2);
double area(double x1, double y1, double x2, double y2);

//Main function.
int main ()
{
    // Variables to be used.
    double x1, y1, x2, y2, result;

    // Ask for x1, y1, x2, and y2.
    cout << "Please enter the x and y position of the first coordinate." << endl;
    cin >> x1 >> y1;
    cout << "Please enter the x and y position of the second coordinate." << endl;
    cin >> x2 >> y2;

    // Calculate distance and output.
    result = distance(x1, y1, x2, y2);
    cout << "The distance is " << result << " units." << endl;
    result = distance(x2, y2);
    cout << "The distance of the test is " << result << " units." << endl;

    // Ask for a the center of a circle and a point on the perimeter.
    cout << "Please enter the x and y position of the center of the circle." << endl;
    cin >> x1 >> y1;
    cout << "Please enter the x and y position of any point on the perimeter of the circle." << endl;
    cin >> x2 >> y2;

    // Calculate radius and output.
    result = radius(x1, y1, x2, y2);
    cout << "The radius is " << result << " units." << endl;
    result = radius(x2, y2);
    cout << "The radius of the test is " << result << " units." << endl;

    // Ask for a the center of a circle and a point on the perimeter.
    cout << "Please enter the x and y position of the center of the circle." << endl;
    cin >> x1 >> y1;
    cout << "Please enter the x and y position of any point on the perimeter of the circle." << endl;
    cin >> x2 >> y2;

    // Calculate circumference and output.
    result = circumference(x1, y1, x2, y2);
    cout << "The circumference of the circle is " << result << " units." << endl;

    // Ask for a the center of a circle and a point on the perimeter.
    cout << "Please enter the x and y position of the center of the circle." << endl;
    cin >> x1 >> y1;
    cout << "Please enter the x and y position of any point on the perimeter of the circle." << endl;
    cin >> x2 >> y2;

    // Calculate area and output.
    result = area(x1, y1, x2, y2);
    cout << "The area of the circle is " << result << " units." << endl;
}

// Function to find distance between two points.
double distance(double x1, double y1, double x2, double y2)
{
    double output;

    // Use the distance formula.
    output = pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0);
    output = sqrt(output);

    // Return distance.
    return output;
}

// Function to find the distance between two points if only one point is given.
double distance(double x2, double y2)
{
    double x1 = 0, y1 = 0, output;

    // Use the distance formula.
    output = pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0);
    output = sqrt(output);

    // Return distance.
    return output;
}

// Function to find the radius based on the center point of a circle and any point on its perimeter.
double radius(double x1, double y1, double x2, double y2)
{
    double output;

    // Use distance funciton.
    output = distance(x1, y1, x2, y2);

    // Return radius.
    return output;
}

// Function to find the radius based on the center point of a circle being the origin and any point on its perimeter.
double radius(double x2, double y2)
{
    double x1 = 0, y1 = 0, output;

    // Use distance funciton.
    output = distance(x1, y1, x2, y2);

    // Return radius.
    return output;
}

// Function to find the circumference based on the center point of a circle and any point on its perimeter.
double circumference(double x1, double y1, double x2, double y2)
{
    double output, rad = 1;

    // Use radius function and circumference formula.
    rad = radius(x1, y1, x2, y2);
    output = 2.0 * PI * rad;

    // Return circumference.
    return output;
}

// Function to find the area based on the center point of a circle and any point on its perimeter.
double area(double x1, double y1, double x2, double y2)
{
    double output, rad = 1;

    // Use radius function and area formula.
    rad = radius(x1, y1, x2, y2);
    output = PI * pow(rad, 2);

    // Return area.
    return output;
}
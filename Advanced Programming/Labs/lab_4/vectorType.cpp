/*
   Author: Elijah Sprung
   Date:  2/2/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_4/vectorType.cpp

   About: The implementation file for class vectorType.
*/

#include "vectorType.h"
#include <iostream>
#include <iomanip>
#include <cmath>

void vectorType::setComps(double x_in = 0, double y_in = 0, double z_in = 0)
{
  x = x_in;
  y = y_in;
  z = z_in;
}

double vectorType::getX() const
{
  return x;
}

double vectorType::getY() const
{
  return y;
}

double vectorType::getZ() const
{
  return z;
}

void vectorType::printVector() const
{
  std::cout << std::setprecision(4) << std::showpoint << std:: fixed << "<" << x << ", " << y << ", " << z << ">";
}

double vectorType::calcMagnitude() const
{
  double magnitude;
  double powX, powY, powZ;
  
  powX = pow(x, 2);
  powY = pow(y, 2);
  powZ = pow(z, 2);
  magnitude = sqrt(powX + powY + powZ);

  return magnitude;
}

vectorType vectorType::scalarMultiply(double scalar)
{
  vectorType output;
  
  output.setComps(x * scalar, y * scalar, z * scalar);

  return output;
}

vectorType::vectorType(double x_in, double y_in, double z_in)
{
  x = x_in;
  y = y_in;
  z = z_in;
}

vectorType::vectorType()
{
  x = 0;
  y = 0;
  z = 0;
}
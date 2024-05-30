/*
   Author: Elijah Sprung
   Date:  2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/prog_2/vectorType.cpp

   About: The implementation file for class vectorType.
*/

#include "vectorType.h"
#include <iostream>
#include <iomanip>
#include <cmath>

#define EPSILON 0.0001

void vectorType::setComps(double x_in = 0, double y_in = 0, double z_in = 0)
{
  x = x_in;
  y = y_in;
  z = z_in;
}

double vectorType::getX(void) const
{
  return x;
}

double vectorType::getY(void) const
{
  return y;
}

double vectorType::getZ(void) const
{
  return z;
}

void vectorType::printVector(void) const
{
  std::cout << std::setprecision(4) << std::showpoint << std:: fixed << "<" << x << ", " << y << ", " << z << ">";
}

double vectorType::calcMagnitude(void) const
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

vectorType vectorType::addVector(vectorType vector_in)
{
  vectorType output;
  double x_out, y_out, z_out;

  x_out = x + vector_in.getX();
  y_out = y + vector_in.getY();
  z_out = z + vector_in.getZ();

  output.setComps(x_out, y_out, z_out);

  return output;
}

vectorType vectorType::subVector(vectorType vector_in)
{
  vectorType output;
  double x_out, y_out, z_out;

  x_out = x - vector_in.getX();
  y_out = y - vector_in.getY();
  z_out = z - vector_in.getZ();

  output.setComps(x_out, y_out, z_out);

  return output;
}

vectorType vectorType::unitVector(void)
{
  vectorType output, vector_in(x, y, z);
  double scalar;

  scalar = 1 / vector_in.calcMagnitude();
  output = vector_in.scalarMultiply(scalar);

  return output;
}

double vectorType::dotProduct(vectorType vector_in)
{
  double output, x_out, y_out, z_out;
  
  x_out = x * vector_in.getX();
  y_out = y * vector_in.getY();
  z_out = z * vector_in.getZ();

  output = x_out + y_out + z_out;

  return output;
}

vectorType vectorType::crossProduct(vectorType vector_in)
{
  vectorType output;
  double x_out, y_out, z_out;

  x_out = y * vector_in.getZ() - z * vector_in.getY();
  y_out = z * vector_in.getX() - x * vector_in.getZ();
  z_out = x * vector_in.getY() - y * vector_in.getX();

  output.setComps(x_out, y_out, z_out);

  return output;
}

bool vectorType::equalVector(vectorType vector_in)
{
  bool output;
  vectorType base_vector, holder;

  base_vector.setComps(x, y, z);
  holder = base_vector.subVector(vector_in);

  if ((abs(holder.getX()) < EPSILON) && (abs(holder.getY()) < EPSILON) && (abs(holder.getZ()) < EPSILON))
  {
    output = true;
  }
  else
  {
    output = false;
  }

  return output;
}

vectorType::vectorType(double x_in, double y_in, double z_in)
{
  x = x_in;
  y = y_in;
  z = z_in;
}

vectorType::vectorType(void)
{
  x = 0;
  y = 0;
  z = 0;
}
/*
  Name: Elijah Sprung
  Date: 04/27/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_13/stuType.h

  About: Header file with implementation for the stuType class.
*/

#ifndef STUTYPE
#define STUTYPE

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// Definition of EPSILON to compare doubles.

#define EPSILON 0.0001

using namespace std;

/*-----------------------Declaration of stuType class.-----------------------*/

class stuType
{

  /*
    String variables for the frist and last names of the student, and then the
    double for their GPA.
  */

  private:
    string first_name;
    string last_name;
    double GPA;

  public:

    /*
      stuType: Constuctor for the class.
      precondition: Called.
      postcondition: stuType variable created with default values of "", "",
      and -1 used for first name, last name, and GPA.
    */

    stuType();

    /*
      set_first_name: Sets the private variable first_name to a given string value.
      precondition: Passed some string value that is not empty.
      postcondition: Private variable first_name is set as either the given value
                     or unchanged.
    */

    void set_first_name(string first_name_in);

    /*
      set_last_name: Sets the private variable last_name to a given string value.
      precondition: Passed some string value that is not empty.
      postcondition: Private variable last_name is set as either the given value
                     or unchanged.
    */

    void set_last_name(string last_name_in);

    /*
      set_GPA: Sets the private variable GPA to a given double value.
      precondition: Passed some double value that is greater than or equal to 0.
      postcondition: Private variable GPA is set as either the given value
                     or unchanged.
    */

    void set_GPA(double GPA_in);

    /*
      get_GPA: Returns the double value of private member GPA.
      precondition: Called.
      postcondition: GPA value returned.
    */

    double get_GPA();

    /*
      operator==: Overloading of == operator to check if two stuType objects
                  have the same GPA.
      precondition: Passed a stuType object.
      postcondition: Returned true if the GPAs are the same, false if they are not.
    */

    bool operator==(stuType right_object);

    /*
      operator!=: Overloading of != operator to check if two stuType objects
                  have different GPAs.
      precondition: Passed a stuType object.
      postcondition: Returned true if the GPAs are the different, false if they are not.
    */

    bool operator!=(stuType right_object);

    /*
      operator<: Overloading of < operator to check if the base stuType object
                 has a lower GPA then the passed stuType object.
      precondition: Passed a  stuType object.
      postcondition: Returned true if the base object is less than the passed
                     object, false if not.
    */

    bool operator<(stuType right_object);

    /*
      operator<: Overloading of > operator to check if the base stuType object
                 has a greater GPA then the passed stuType object.
      precondition: Passed a  stuType object.
      postcondition: Returned true if the base object is greater than the passed
                     object, false if not.
    */

    bool operator>(stuType right_object);

    /*
      operator=: Overloading of = operator to create a deep copy of a stuType
                 object for the base object based on the passed object.
      precondition: Passed stuType object;
      postcondition: The base stuType object now has the same values as the passed
                     object, but they are both deep copies.
    */

    const stuType& operator=(stuType right_object);

    /*
      operator<<: Overloading of the << operator to output the first name,
                  last name, and GPA with a certain format.
      precondtion: Passed the ostream object to store the output and the stuType
                   object containting the data.
      postcondition: An ostream object is returned to be output.
    */

    friend ostream& operator<<(ostream& osObject, const stuType& cObject);
};

/*----------------------Implementation of stuType class.----------------------*/

stuType::stuType()
{
  first_name = "";
  last_name = "";
  GPA = -1;
}

void stuType::set_first_name(string first_name_in)
{
  if (first_name_in != "")
  {
    first_name = first_name_in;
  }
}

void stuType::set_last_name(string last_name_in)
{
  if (last_name_in != "")
  {
    last_name = last_name_in;
  }
}

void stuType::set_GPA(double GPA_in)
{
  if (GPA_in >= 0)
  {
    GPA = GPA_in;
  }
}


double stuType::get_GPA()
{
  return GPA;
}

bool stuType::operator==(stuType right_object)
{
  if (abs(GPA - right_object.GPA) <= EPSILON)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool stuType::operator!=(stuType right_object)
{
  if (abs(GPA - right_object.GPA) <= EPSILON)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool stuType::operator<(stuType right_object)
{
  if (GPA < right_object.GPA)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool stuType::operator>(stuType right_object)
{
  if (GPA > right_object.GPA)
  {
    return true;
  }
  else
  {
    return false;
  }
}

const stuType& stuType::operator=(stuType right_object)
{
  string fname, lname;
  double gpa;

  fname = right_object.first_name;
  lname = right_object.last_name;
  gpa = right_object.GPA;

  first_name = fname;
  last_name = lname;
  GPA = gpa;

  return *this;
}

ostream& operator<<(ostream& output, const stuType& input)
{
  output << fixed << showpoint << setprecision(2);
  output << input.first_name << " ";
  output << input.last_name << " ";
  output << input.GPA << " ";

  return output;
}

#endif
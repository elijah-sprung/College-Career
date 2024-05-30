/*
   Author: Elijah Sprung
   Date:  1/26/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_3/empType.h

   About: The implementation file for the class empType.
*/

#include"empType.h"

void empType::setName(string iname)
{
   name = iname;
}


void empType::setAge(int iage)
{
   age = iage;
}


void empType::setSalary(double isalary)
{
   salary = isalary;
}

void empType::setID(int iID)
{
  ID = iID;
}

string empType::getName(void) const
{
   return name;
}


int empType::getAge(void) const
{
   return age;
}

double empType::getSalary(void) const
{
   return salary;
}

int empType::getID(void) const
{
  return ID;
}

empType::empType(int ID_in, string name_in, int age_in, double salary_in)
{
  if (ID_in < 1)
  {
    cerr << "The input ID is below 1." << endl;
    ID_in = 0;
  }

  ID = ID_in;

  if (name_in == "")
  {
    cerr << "The input name was blank." << endl;
  }
   
  name = name_in;

  if (age_in < 18)
  {
    cerr << "The input age is 18 or lower." << endl;
  }
  
  age = age_in;

  if (salary_in < 0)
  {
    cerr << "The salary input was below 0." << endl;
    salary_in = 0;
  }

  salary = salary_in;
}

empType::empType()
{
  ID = 0;
  name = "";
  age = 0;
  salary = 0.0;
}
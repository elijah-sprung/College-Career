/*
  Author: Elijah Sprung
  Date: 01/26/2021
  Class: CSC 1720-03
  Code Location: ~/esprung/csc1720/prog_1/counter_type.cpp

  About: This is the implementation of class counter_type.
*/

#include <iostream>
#include "counter_type.h"

using namespace std;

/*
  Method in the counter_type class that initializes the main private variable
  for use.
  Preconditions: There are none required for this to run.
  Postconditions: The counter private variable will be set to 0.
*/

void counter_type::initialize_counter()
{
  counter = 0;
}

/*
  Method in the counter_type class that sets the counter to a specified value.
  Preconditions: The user must input a value greater than or equal to zero.
  Postconditions: The counter private variable will be set to the user's
  number, or it will be zero.
*/

void counter_type::set_counter(int count)
{
  if (count < 0)
  {
    counter = 0;
  }
  else
  {
    counter = count;
  }
}

/*
  Method in the counter_type class that gets the main private variable.
  Preconditions: There are none required for this to run.
  Postconditions: The counter private variable will be returned.
*/

int counter_type::get_counter() const
{
  return counter;
}

/*
  Method in the counter_type class that increases the private counter variable
  by 1.
  Preconditions: There are none required for this to run.
  Postconditions: The counter private variable will be increased by 1.
*/

void counter_type::increment_counter()
{
  counter++;
}

/*
  Method in the counter_type class that decreases the counter by one.
  Preconditions: There are none required for this to run.
  Postconditions: The counter private variable will be lowered by one unless
  it is already 0.
*/

void counter_type::decrement_counter()
{
  if (counter != 0)
  {
    counter--;
  }
  else
  {
    counter = 0;
  }
}

/*
  Method in the counter_type class that prints out the counter.
  Preconditions: There are none required for this to run.
  Postconditions: The counter private variable will be printed out.
*/

void counter_type::display_counter() const
{
  cout << "Counter: " << counter;
}

/*
  The constructor for the counter_type class.
  Preconditions: An integer to set the counter at is required.
  Postconditions: The counter private variable will be set to some number as
  long as it is not below 0.
*/

counter_type::counter_type(int count)
{
  if (count < 0)
  {
    counter = 0;
  }
  else
  {
    counter = count;
  }
}

/*
  The overload constructor for the counter_type class.
  Preconditions: There are none required for this to run.
  Postconditions: The counter private variable will be set to 0.
*/

counter_type::counter_type()
{
  counter = 0;
}
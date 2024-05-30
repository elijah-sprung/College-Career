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


void counter_type::initialize_counter()
{
  counter = 0;
}

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

int counter_type::get_counter() const
{
  return counter;
}

void counter_type::increment_counter()
{
  counter++;
}

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

void counter_type::display_counter() const
{
  cout << "Counter: " << counter;
}

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

counter_type::counter_type()
{
  counter = 0;
}
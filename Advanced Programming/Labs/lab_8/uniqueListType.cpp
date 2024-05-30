/*
  Name: Elijah Sprung
  Date: 03/2/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_8/uniqueListType.cpp

  About: Implementation file for uniqueListType.
*/

#include "uniqueListType.h"

uniqueListType::uniqueListType(int size)
              :unorderedArrayListType(size)
{
}

void uniqueListType::insertAt(int location, string insertItem)
{
  if (seqSearch(insertItem) == -1)
  {
    unorderedArrayListType::insertAt(location, insertItem);
  }
  else
  {
    cerr << "You have insert a value that is not unique, it has not been" <<
            " inserted." << endl;
  }
}

void uniqueListType::insertEnd(string insertItem)
{
  if (seqSearch(insertItem) == -1)
  {
    unorderedArrayListType::insertEnd(insertItem);
  }
  else
  {
    cerr << "You have insert a value that is not unique, it has not been" <<
      " inserted." << endl;
  }
}

void uniqueListType::replaceAt(int location, string insertItem)
{
  if (seqSearch(insertItem) == -1)
  {
    unorderedArrayListType::replaceAt(location, insertItem);
  }
  else
  {
    cerr << "You have insert a value that is not unique, it has not been" <<
      " inserted." << endl;
  }
}
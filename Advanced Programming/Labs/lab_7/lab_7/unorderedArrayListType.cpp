#include <iostream>
#include "unorderedArrayListType.h" 

/*
  Name: Elijah Sprung
  Date: 02/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_7/unorderedArrayListType.cpp

  About: Implementation file for the unorderedArrayListType class.
*/

using namespace std; 

unorderedArrayListType::unorderedArrayListType(int size)
                      : arrayListType(size)
{
}  //end constructor

void unorderedArrayListType::insertAt(int location, int insertItem) 
{
   if (location < 0 || location >= maxSize || location > length)
      cout << "The position of the item to be inserted "
           << "is out of range." << endl;
   else if (length >= maxSize)  //list is full
      cout << "Cannot insert in a full list" << endl;
   else
   {
      for (int i = length; i > location; i--)
         list[i] = list[i - 1];	//move the elements down

      list[location] = insertItem; //insert the item at 
                                   //the specified position

      length++;	//increment the length
   }
} //end insertAt

void unorderedArrayListType::insertEnd(int insertItem)
{
   if (length >= maxSize)  //the list is full
      cout << "Cannot insert in a full list." << endl;
   else
   {
      list[length] = insertItem; //insert the item at the end
      length++; //increment the length
   }
} //end insertEnd

void unorderedArrayListType::replaceAt(int location, int repItem)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      list[location] = repItem;
} //end replaceAt

int unorderedArrayListType::seqSearch(int searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < length && !found)
      if (list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)
      return loc;
   else
      return -1;
} //end seqSearch

void unorderedArrayListType::removeAt(int location)
{
  int holder;
  
  if (location > 0 && location <= length)
  {
    holder = list[length - 1];
    list[location] = holder;
    length--;
  }
  else
  {
    cerr << "An invalid location was input, no change." << endl;
  }
}

void unorderedArrayListType::insertFirst(int insertItem)
{
  unorderedArrayListType::insertAt(0, insertItem);
}

int unorderedArrayListType::findMax()
{
  int output;

  if (arrayListType::isEmpty() == false)
  {
    output = list[0];

    for (int i = 0; i < length; i++)
    {
      if (output < list[i])
      {
        output = list[i];
      }
    }
  }
  else
  {
    cerr << "The list was empty, returning 0." << endl;
    output = 0;
  }

  return output;
}
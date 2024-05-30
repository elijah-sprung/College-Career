#include <iostream>
#include "orderedArrayListType.h" 

orderedArrayListType::orderedArrayListType(int size)
                      : arrayListType(size)
{
}  //end constructor

orderedArrayListType::orderedArrayListType(const orderedArrayListType& otherList)
                     : arrayListType(otherList)
{
}


void orderedArrayListType::insertAt(int location, int insertItem) 
{
  this -> insert(insertItem);
} //end insertAt

void orderedArrayListType::insertEnd(int insertItem)
{
  this -> insert(insertItem);
} //end insertEnd

void orderedArrayListType::replaceAt(int location, int repItem)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      list[location] = repItem;
} //end replaceAt

int orderedArrayListType::seqSearch(int searchItem) const
{
  bool greater = false, found = false, end = false;
  int i = 0, output;

  while (found == false && greater == false && end == false)
  {
    if (list[i] == searchItem)
    {
      found = true;
      output = i;
    }
    if (list[i] < searchItem)
    {
      greater = true;
      output = -1;
    }
    if (i == length)
    {
      end = true;
      output = -1;
    }

    i++;
  }

  return output;
} //end seqSearch


void orderedArrayListType::insert(int insertItem)
{
  //list empty?
  if (length == 0)
    list[length++] = insertItem;
  else if (length == maxSize)
    cout << "Cannot insert in a full list." << endl;
  else {
    //Find the location in the list where to insert
    //insertItem. Keep in items are in ascending order.
    int loc = 0;
    bool found = false;
    while (!found && loc < length) {
      if (list[loc] >= insertItem)
        found = true;
      else
        loc++;
    }
    //Now, move elements down to make space for insertItem
    for (int i = length; i > loc; i--)
      list[i] = list[i - 1];
    //loc is the location in the array for insertItem
    list[loc] = insertItem;
    length++;
  }
} //end insert

const orderedArrayListType& orderedArrayListType::operator=(const orderedArrayListType& otherObject)
{
  //local declaration, if any
  //avoid self-assignment with an if statement
  if (this != &otherObject)
  {
    delete [] list;
    maxSize = otherObject.maxSize;
    length = otherObject.length;

    list = new int[maxSize]; 	//create the array

    for (int j = 0; j < otherObject.length; j++)  //copy otherList
      list[j] = otherObject.list[j];
  }
  //Return the object assigned.
  return *this;
}

ostream& operator<<(ostream& output, const orderedArrayListType& input)
{
  for (int i = 0; i < input.length; i++)
  {
    output << input.list[i] << " ";
  }

  return output;
}
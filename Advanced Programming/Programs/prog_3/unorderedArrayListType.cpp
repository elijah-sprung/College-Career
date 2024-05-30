/*
  Name: Elijah Sprung
  Date: 03/22/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_3/unorderedArrayListType.cpp

  About: Implementation file for unorderedArrayListType.
*/

#include <iostream>

using namespace std;

template <typename T>
unorderedArrayListType<T>::unorderedArrayListType(int size)
                      : arrayListType<T>(size)
{
}  //end constructor

template <typename T>
void unorderedArrayListType<T>::insertAt(int location, T insertItem)
{
   if (location < 0 || location >= this->maxSize || location > this->length)
      cout << "The position of the item to be inserted "
           << "is out of range." << endl;
   else if (this->length >= this->maxSize)  //list is full
      cout << "Cannot insert in a full list" << endl;
   else
   {
      for (int i = this->length; i > location; i--)
         this->list[i] = this->list[i - 1];	//move the elements down

      this->list[location] = insertItem; //insert the item at 
                                   //the specified position

      this->length++;	//increment the length
   }
} //end insertAt

template <typename T>
void unorderedArrayListType<T>::insertEnd(T insertItem)
{
   if (this->length >= this->maxSize)  //the list is full
      cout << "Cannot insert in a full list." << endl;
   else
   {
      this->list[this->length] = insertItem; //insert the item at the end
      this->length++; //increment the length
   }
} //end insertEnd

template <typename T>
void unorderedArrayListType<T>::replaceAt(int location, T repItem)
{
   if (location < 0 || location >= this->length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      this->list[location] = repItem;
} //end replaceAt

template <typename T>
int unorderedArrayListType<T>::seqSearch(T searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < this->length && !found)
      if (this->list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)
      return loc;
   else
      return -1;
} //end seqSearch



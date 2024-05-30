/*
  Name: Elijah Sprung
  Date: 03/22/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_3/arrayListType.cpp

  About: Implelentations file for arrayListType.
*/

#include <iostream>

using namespace std;

template <typename T>
arrayListType<T>::arrayListType(int size)
{
   if (size <= 0)
   {
      cout << "The array size must be positive. Creating "
           << "an array of the size 100." << endl;

      maxSize = 100;
   }
   else
      maxSize = size;

   length = 0;

   list = new T[maxSize];
} //end constructor

template <typename T>
arrayListType<T>::~arrayListType()
{
   delete [] list;
} //end destructor

template <typename T>
arrayListType<T>::arrayListType(const arrayListType<T>& otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;

   list = new T[maxSize]; 	//create the array

   for (int j = 0; j < length; j++)  //copy otherList
      list [j] = otherList.list[j];
}//end copy constructor

template <typename T>
bool arrayListType<T>::isEmpty() const
{
   return (length == 0);
} //end isEmpty

template <typename T>
bool arrayListType<T>::isFull() const
{
   return (length == maxSize);
} //end isFull

template <typename T>
int arrayListType<T>::listSize() const
{
   return length;
} //end listSize

template <typename T>
int arrayListType<T>::maxListSize() const
{
   return maxSize;
} //end maxListSize

template <typename T>
void arrayListType<T>::print() const
{
   for (int i = 0; i < length; i++)
      cout << list[i] << " ";
   cout << endl;
} //end print

template <typename T>
void arrayListType<T>::removeAt(int location)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be removed "
           << "is out of range." << endl;
   else
   {
      for (int i = location; i < length - 1; i++)
         list[i] = list[i+1];

      length--;
   }
} //end removeAt

template <typename T>
void arrayListType<T>::clearList()
{
   length = 0;
} //end clearList

template <typename T>
T arrayListType<T>::getAt(int location) const
{
  if (location < 0 || location >+length)
  {
    cerr << "The location input is out of range, returned NULL" << endl;
    return NULL;
  }
  else
  {
    return list[location];
  }
}
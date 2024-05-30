/*
  Name: Elijah Sprung
  Date: 03/2/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_8/uniqueListType.cpp

  About: Implementation file for uniqueListType.
*/

#include <iostream>

template <typename T>
uniqueListType<T>::uniqueListType(int size)
              :unorderedArrayListType<T>(size)
{
}

template <typename T>
uniqueListType<T>::uniqueListType(const arrayListType<T>& otherList)
{
  this->maxSize = otherList.maxListSize();
  this->length = 0;

  this->list - new T[this->maxSize];

  for (int j = 0; j < otherList.listSize(); j++)\
  {
    if (this->seqSearch(otherList.getAt(j)) == -1)
    {
      this->insertEnd(otherList.getAt(j));
    }
  }
}

template <typename T>
void uniqueListType<T>::insertAt(int location, T insertItem)
{
  if (unorderedArrayListType<T>::seqSearch(insertItem) == -1)
  {
    unorderedArrayListType<T>::insertAt(location, insertItem);
  }
  else
  {
    cerr << "You have insert a value that is not unique, it has not been" <<
            " inserted." << endl;
  }
}

template <typename T>
void uniqueListType<T>::insertEnd(T insertItem)
{
  if (unorderedArrayListType<T>::seqSearch(insertItem) == -1)
  {
    unorderedArrayListType<T>::insertEnd(insertItem);
  }
  else
  {
    cerr << "You have insert a value that is not unique, it has not been" <<
      " inserted." << endl;
  }
}

template <typename T>
void uniqueListType<T>::replaceAt(int location, T insertItem)
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
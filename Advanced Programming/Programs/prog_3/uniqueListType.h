/*
  Name: Elijah Sprung
  Date: 03/22/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_3/uniqueListType.h

  About: Header file for uniqueListType.
*/

#ifndef UniqueList_TYPE
#define UniqueList_TYPE

#include "unorderedArrayListType.h"

template <typename T>
class uniqueListType : public unorderedArrayListType<T>
{
  public:

    /*
      uniqueListType: Constructor.
      precondiditons: Called.
      postcondiditons: Class item created.
    */

    uniqueListType(int size = 100);

    /*
      uniqueListTpye:
      preconditions:
      postconditions:
    */

    uniqueListType(const arrayListType<T>& otherList);

    /*
      insertAt: Function to only insert unique items at a specified location.
      precondiditons: Location and item passed.
      postcondiditons: Unique item inserted or error message.
    */


    void insertAt(int location, T insertItem);

    /*
      insertEnd: Function to only insert unique items at the end.
      precondiditons: Item passed.
      postcondiditons: Unique item inserted or error message.
    */

    void insertEnd(T insertItem);

    /*
      replaceAt: Function to only replace an item with a unique item.
      precondiditons: Location and item passed.
      postcondiditons: Unique item inserted or error message.
    */

    void replaceAt(int location, T repItem);
};

#include "uniqueListType.cpp"
#endif
/*
  Name: Elijah Sprung
  Date: 03/2/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_8/uniqueListType.h

  About: Header file for uniqueListType.
*/

#ifndef UniqueList_TYPE
#define UniqueList_TYPE

#include "unorderedArrayListType.h"

class uniqueListType : public unorderedArrayListType
{
  public:

    /*
      uniqueListType: Constructor.
      precondiditons: Called.
      postcondiditons: Class item created.
    */

    uniqueListType(int size = 100);

    /*
      insertAt: Function to only insert unique items at a specified location.
      precondiditons: Location and item passed.
      postcondiditons: Unique item inserted or error message.
    */

    void insertAt(int location, string insertItem);

    /*
      insertEnd: Function to only insert unique items at the end.
      precondiditons: Item passed.
      postcondiditons: Unique item inserted or error message.
    */

    void insertEnd(string insertItem);

    /*
      replaceAt: Function to only replace an item with a unique item.
      precondiditons: Location and item passed.
      postcondiditons: Unique item inserted or error message.
    */

    void replaceAt(int location, string repItem);
};

#endif
/*
  Name: Elijah Sprung
  Date: 03/22/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_3/unorderedArrayListType.h

  About: Header file for unorderedArrayListType.
*/

#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE

#include "arrayListType.h" 

template <typename T>
class unorderedArrayListType: public arrayListType<T>
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt Function to insert item at desired location.
         Precondition: Passed location and item.
         Postcondition: Item inserted.
      */
      void insertAt(int location, T insertItem);
  
      /* insertEnd Function to insert item at the end of the list.
         Precondition: Passed item.
         Postcondition: Item inserted.
      */
      void insertEnd(T insertItem);

      /* replaceAt Function to replace item at location with desired item.
         Precondition: Passed location and item.
         Postcondition: Item replaced.
      */
      void replaceAt(int location, T repItem);
  
      /* seqSearh Function to search for an item in list.
         Precondition: Passed search item.
         Postcondition: Returned location or -1.
      */
      int seqSearch(T searchItem) const;
}; 

#include "unorderedArrayListType.cpp"
#endif

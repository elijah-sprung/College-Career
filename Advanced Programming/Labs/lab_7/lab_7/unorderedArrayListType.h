/*
  Name: Elijah Sprung
  Date: 02/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_7/unorderedArrayListType.h

  About: Header file for the unorderedArrayListType class.
*/

#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 

class unorderedArrayListType: public arrayListType
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt Function to insert an integer at a given position.
         Precondition: Location and item integers passed.
         Postcondition: The item will be inserted at the given location and
                        the length changed accordingly.
      */
      void insertAt(int location, int insertItem);
  
      /* insertEnd Function to insert an integer at the end of the list.
         Precondition: The desired integer is passed.
         Postcondition: The integer is insert at the end and the length is
                        increased.
      */
      void insertEnd(int insertItem);

      /* replaceAt Function to replace some location's integer with a desired
*                  integer.
         Precondition: Pass location and desired replacement.
         Postcondition: The integer in the location will be replaced.
      */
      void replaceAt(int location, int repItem);
  
      /* seqSearh Function to search through the entire array for a desired
*                 number and returning its location.
         Precondition: Integer to be found passed.
         Postcondition: The location is returned if found, -1 if not.
      */
      int seqSearch(int searchItem) const;

      /*
        removeAt: Function to remove the integer at some location.
        precondition: The location must be passed.
        postcondition: The list is shortened by 1 and the desired location is
                       deleted.
      */
      
      void removeAt(int location);

      /*
        insertFirst: Function to insert some integer at the beginning of the
                     list.
        precondition: The integer must be passed.
        postcondition: The list length is increased and the integer is at the
                       start.
      */

      void insertFirst(int insertItem);

      /*
        findMax: Function to find the larges value in the list.
        precondition: Nothing passed.
        postcondition: The largest number in the list is returned.
      */

      int findMax();
}; 

#endif

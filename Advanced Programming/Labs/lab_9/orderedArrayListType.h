#ifndef OrderedArrayList_TYPE
#define OrderedArrayList_TYPE
   
#include "arrayListType.h" 

class orderedArrayListType: public arrayListType
{
   public:
      //Constructor
      orderedArrayListType(int size = 100);

      //Copy constructor
      orderedArrayListType(const orderedArrayListType& otherList);

      /* insertAt Function to insert a value into the list.
         Precondition: Value and desired location passed.
         Postcondition: Value added to the list in order.
      */

      void insertAt(int location, int insertItem);
  
      /* insertEnd Function to insert a value into the list.
         Precondition: Value to be inserted passed.
         Postcondition: Value added to the list.
      */
      void insertEnd(int insertItem);

      /* replaceAt Function to replace a value with a given value at a desired
*          location.
         Precondition: Desired location and value passed.
         Postcondition: Value switched out with what is in the list at the
           location
      */
      void replaceAt(int location, int repItem);
  
      /* seqSearh Function to see if a value is in the list.
         Precondition: Pass desired value.
         Postcondition: Either location is returned, or -1 if it is not in the
           list at all.
      */
      int seqSearch(int searchItem) const;

      /*
        insert: Function to insert a value into the array while keeping the
          ascending order.
        pre-conditions: Pass item to be inserted.
        post-conditions: Item is added.
      */

      void insert(int insertItem);

      /*
        =: Overiding of assignment operator.
        pre-conditions: Must be used.
        post-conditions: Values are assigned.
      */

      const orderedArrayListType& operator=(const orderedArrayListType&);

      /*
        <<: Overloading of stream insertion operator.
        pre-conditions: Must be used.
        post-conditions: Value is inserted into the stream.
      */

      friend ostream& operator<<(ostream& osObject, const orderedArrayListType& cObject);
}; 

#endif

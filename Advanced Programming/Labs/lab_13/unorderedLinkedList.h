#ifndef UNORDEREDLINKEDLIST
#define UNORDEREDLINKEDLIST

#include "linkedList.h"

using namespace std;


//***************** derived unordered linked list type definition **************************
template <class Type>
class unorderedLinkedList:public linkedListType<Type>
{
public:
      bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

      void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

      void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

      void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.

      /*
        merge: Function to merge two lists as efficiently as possible.
        precondition: Pass another linkedListType.
        postcondition: Second list is empty and first list has all items linked.
      */

      void merge(unorderedLinkedList<Type>& list_2);

      /*
        forwardPrint: Function to print all of the nodes in the linked list recursively.
        precondition: None.
        postcondition: None.
      */

      void forwardPrint();

      /*
        reversePrint: Function to print all of the nodes in the linked list recursively in reverse order.
        precondition: Object must be unorderedLinkedList<Type>.
        postcondition: None.
      */

      void reversePrint();

private:

  /*
    forwardPrint: Prints the value of a node and is private as to be used recursively by the other forwardPrint.
    precondition: Takes a pointer nodeType<Type> node.
    postcondition: None.
  */

  void forwardPrint(nodeType<Type>*);

  /*
    reversePrint: Prints the value of a node and is private as to be used recursively by the other reversePrint.
    precondition: Takes a pointer nodeType<Type> node.
    postcondition: None.
  */

  void reversePrint(nodeType<Type>*);
};

//***************** unordered linked list type implementation **************************

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
   nodeType<Type> *curPtr = this->first;

   while(curPtr != nullptr) {
      if(curPtr->info == searchItem)
         return true;
      curPtr = curPtr->link;
   }

   return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type & newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>;
   newNode->info = newItem;
   newNode->link = this->first;
   this->first = newNode;
   this->count++;

   if(this->last==nullptr)
      this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type & newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>;
   newNode->info = newItem;
   this->count++;

   if(this->last==nullptr)
      this->first = this->last = newNode;
   else {
      this->last->link = newNode;
      this->last = newNode; 
   }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   bool found = false;
  
   if(this->isEmpty())
      cerr << "List is empty, can't delete from empty list!" << endl;
   else {
      prevPtr = nullptr;
      curPtr = this->first;
      while(curPtr != nullptr && !found) {
         if(curPtr->info != deleteItem) {
            prevPtr = curPtr;
            curPtr = curPtr->link;
         } else {
            found = true;
         }
      }
      if(!found) {
         cerr << deleteItem << " is not in the list" << endl;
      } else {
         if(curPtr == this->first) {
            //found in the first node
            this->first = this->first->link;
         } else {
            //found after the first node 
            prevPtr->link = curPtr->link;
         }
         if(curPtr == this->last) {
            //if curPtr = last pointer then one of two items are true;
            //only one node in the list and deleteItem is in the first node
            //more than one node in the list and deleteItem is the last node
            this->last = prevPtr;
         }
         delete curPtr; 
         this->count--;
      }
   }

}

template <class Type>
void unorderedLinkedList<Type>::merge(unorderedLinkedList<Type>& list_2)
{
  if (this != &list_2)
  {
    if (this->isEmpty() == false && list_2.isEmpty() == false)
    {
      this->last->link = list_2.first;
      this->last = list_2.last;
      this->count += list_2.count;

      list_2.first = nullptr;
      list_2.last = nullptr;
      list_2.count = 0;
    }
    else if (this->isEmpty() == true && list_2.isEmpty() == false)
    {
      this->first = list_2.first;
      this->last = list_2.last;
      this->count = list_2.count;

      list_2.first = nullptr;
      list_2.last = nullptr;
      list_2.count = 0;
    }
    else if (list_2.isEmpty() == true) {}
  }
}

template <class Type>
void unorderedLinkedList<Type>::forwardPrint()
{
  nodeType<Type>* curptr = this->first;

  if (curptr != nullptr)
  {
    cout << curptr->info << " ";
    forwardPrint(curptr->link);
  }
}

template <class Type>
void unorderedLinkedList<Type>::forwardPrint(nodeType<Type>* nextPtr)
{
  if (nextPtr != nullptr)
  {
    cout << nextPtr->info << " ";
    forwardPrint(nextPtr->link);
  }
}

template <class Type>
void unorderedLinkedList<Type>::reversePrint()
{
  nodeType<Type>* curptr = this->first;

  if (curptr != nullptr)
  {
    reversePrint(curptr->link);
    cout << curptr->info << " ";
  }
}

template <class Type>
void unorderedLinkedList<Type>::reversePrint(nodeType<Type>* nextPtr)
{
  if (nextPtr != nullptr)
  {
    reversePrint(nextPtr->link);
    cout << nextPtr->info << " ";
  }
}
#endif

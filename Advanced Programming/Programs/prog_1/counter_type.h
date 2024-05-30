/*
  Author: Elijah Sprung
  Date: 01/26/2021
  Class: CSC 1720-03
  Code Location: ~/esprung/csc1720/prog_1/counter_type.h

  About: This is the header file for the counter_type class.
*/

#ifndef COUNTER_TYPE
#define COUNTER_TYPE

/*
  Definition for the counter_type class.
  Precondition: Technically none because of the overload constructor, though
  a value greater than 0 must be passed.
  Postcondition: Completely depends on what the user wishes, the different
  method prototypes here can be used to their full extent after implementation.
*/

class counter_type
{
  // Private members of the counter_type class.
  private:
    int counter;

  public:

    /*
      Functions to create a counter based on input.
      pre-conditions: No input will set the counter at 0, and any other input
        will set the counter to that.
      post-conditions: The private counter member will be initialized.
    */

    void initialize_counter();
    void set_counter(int count = 0);

    /*
      Functions to return and print the counter.
      pre-conditions: There are none required.
      post-conditions: The counter will either be returned or printed.
    */

    int get_counter() const;
    void display_counter() const;

    /*
      Functions to increase or decrease the counter.
      pre-conditions: None.
      post-conditions: The counter will be increased or decreased by one.
    */

    void increment_counter();
    void decrement_counter();

    /*
      Constructors for the counter_type class.
      pre-conditions: Either an integer passed or none.
      post-conditions: A variable of counter_type will be declared.
    */

    counter_type(int);
    counter_type();
};
#endif // !COUNTER_TYPE
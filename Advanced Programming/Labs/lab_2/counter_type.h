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
  private:
    int counter;

  public:
    void initialize_counter();
    void set_counter(int count = 0);
    int get_counter() const;
    void increment_counter();
    void decrement_counter();
    void display_counter() const;
    counter_type(int);
    counter_type();
};
#endif // !COUNTER_TYPE
/* 
   Author: Elijah Sprung
   Date:  1/26/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_3/empType.h
   
   About: The header file for class empType.
*/

#ifndef EMP_TYPE
#define EMP_TYPE

#include<iostream>
#include<iomanip>

using namespace std;

class empType {
   private:
      int ID;
      string name;
      int age;
      double salary;
   public:
      /* Three set methods for the empType class. 
       * pre-condition: each set method receives the data via a parameter
       * post-condition: the data is stored in the associate private instance
       *                 variable.
       */
      void setName(string name_in);
      void setAge(int age_in);
      void setSalary(double salary_in);
      void setID(int ID_in);

      /* Three get methods for the empType class. 
       * pre-condition: each set method receives the data via a parameter
       * post-condition: the data is stored in the associate private instance
       *                 variable.
       */
      string getName(void) const;
      int getAge(void) const;
      double getSalary(void) const;
      int getID(void) const;
      
      /*
        Constructors for the empType class.
        Pre-Condition: Must be called.
        Post-Condition: variable empType created.
      */

      empType(int ID_in, string name_in, int age_in, double salary_in);
      empType();
};
#endif

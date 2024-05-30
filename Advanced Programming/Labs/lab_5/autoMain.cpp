/*
   Author: Elijah Sprung
   Date: 2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_5/autoMain.cpp

   About: Main function used to test the autoType class and the hybridType
      derived class. Compile with the command 'g++ -Wall hybridType.cpp
      autoType.cpp autoMain.cpp -o testProg'.
*/

#include "autoType.h"
#include "hybridType.h"
#include <iomanip>

int main()
{
  autoType car, car2(0, 50, 4, 100);

  cout << "Testing constructors:" << endl;
  cout << car.getAutoSpecs() << endl;
  cout << car2.getAutoSpecs() << endl;
  cout << endl;
  
  cout << "Testing setAutoSpecs:" << endl;
  car.setAutoSpecs(0, 10, 4);
  cout << car.getAutoSpecs() << endl;
  cout << endl;

  cout << "Testing drive:" << endl;
  car2.drive(30);
  cout << car2.getAutoSpecs() << endl;
  cout << endl;
  
  cout << "Testing addFuel:" << endl;
  car2.addFuel(20);
  cout << car2.getAutoSpecs() << endl;
  cout << endl;
  
  cout << "Testing hybridType:" << endl;
  hybridType hybrid;
  cout << hybrid.getAutoSpecs() << endl;
  cout << "Charge Level = " << hybrid.getChargeLevel() << endl;
  cout << "Charge Efficiency = " << hybrid.getChargeEfficiency() << endl;
  cout << endl;
  
  cout << "Testing setChargeLevel and setChargeEfficiency:" << endl;
  hybrid.setChargeLevel(75);
  hybrid.setChargeEfficiency(2);
  cout << "Charge Level = " << hybrid.getChargeLevel() << endl;
  cout << "Charge Efficiency = " << hybrid.getChargeEfficiency() << endl;
  cout << endl;

  return 0;
}

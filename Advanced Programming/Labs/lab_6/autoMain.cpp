/*
  Name: Elijah Sprung
  Date: 02/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_6/autoMain.cpp

   To compile, use command:
      g++ -Wall autoMain.cpp autoType.cpp hybridType.cpp -o lab6Test		
   To execute, use command
      ./lab6Test
*/

#include"hybridType.h"
#include"autoType.h"
#include<iomanip>

int main()
{  

  //test parameterized constructor
  autoType F250(100.5, 20, 16.25, 19.7);

  cout << "******FORD F250******" << endl;
  cout << F250.getAutoSpecs() << endl << endl;

  //test addFuel
  cout << "Adding 10 gallons." << endl;
  F250.addFuel(10);
  cout << F250.getAutoSpecs() << endl << endl;

  //test drive
  cout << "Requesting to drive 400 miles." << endl;
  F250.drive(400);
  cout << F250.getAutoSpecs() << endl << endl;

  //test default constructor
  hybridType fusion;  //can't use parameterized constructor.
  cout << "******Ford Fusion******" << endl;
  cout << fusion.getAutoSpecs() << endl << endl;

  //test setAutoSpecs
  cout << "Setting auto specs to 1234, 2.25, and 42.7" << endl;
  fusion.setAutoSpecs(1234, 2.25, 42.7);
  cout << fusion.getAutoSpecs() << endl << endl;
  cout << "Request to drive 200 miles." << endl;
  fusion.drive(200);
  cout << fusion.getAutoSpecs() << endl << endl;

  //test hybridTypeDrive
  cout << "******New Ford Fusion******" << endl;
  hybridType new_fusion(0, 50, 50, 3, 100, 3);
  cout << "Requesting to drive 50 miles." << endl;
  new_fusion.drive(50);
  cout << new_fusion.getAutoSpecs() << endl << endl;

  cout << "Requesting to drive 500 miles." << endl;
  new_fusion.drive(500);
  cout << new_fusion.getAutoSpecs() << endl << endl;

  cout << "Setting charge level to 19." << endl;
  new_fusion.setChargeLevel(19);
  cout << new_fusion.getAutoSpecs() << endl;
  cout << "Requesting to drive 50 miles." << endl;
  new_fusion.drive(50);
  cout << new_fusion.getAutoSpecs() << endl;

  return 0;
}

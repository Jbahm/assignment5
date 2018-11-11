#include <iostream>
#include "person.h"
#include "DoublyLinkedList.h"

using namespace std;



class faculty: public person{
  public:
    faculty();
    faculty(int idNum, string n, string lev, string depart);
    string name;
    string level;
    string department;
    DoublyLinkedList<int> advisees;

    string getName();
    string getLevel();
    string getDepartment();



};

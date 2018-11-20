#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;



class faculty{
  public:
    faculty();
    faculty(int idNum, string n, string lev, string depart, DoublyLinkedList<int> a);
    string name;
    string level;
    int id;
    string department;
    DoublyLinkedList<int> advisees;

    int getId();
    void printData();
    void addAdvisee(int id);
    string getName();
    string getLevel();
    string getDepartment();
    DoublyLinkedList<int> getAdvisees();
};

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

    int getId(); //get faculty id
    void printData(); //print faculty data
    void addAdvisee(int id);  //add a new advisee for the faculty
    void removeAdvisee(int id); // remove a advisee from the faculty
    string getName(); //get faculty name
    string getLevel(); //get faculty level
    string getDepartment(); //get faculty department
    DoublyLinkedList<int> getAdvisees();  //faculty advisees in a list 
};

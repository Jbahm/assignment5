#include <iostream>
#include "faculty.h"

using namespace std;



faculty::faculty(){
  name = "";
  id = -1;
  level = "";
  department = "";
}


faculty::faculty(int idNum, string n, string lev, string depart, DoublyLinkedList<int> a){
  id = idNum;
  name = n;
  level = lev;
  department = depart;
  advisees = a;
}

//get faculty name
string faculty::getName(){
  return name;
}

//get faculty level (position)
string faculty::getLevel(){
  return level;
}

//get faculty department
string faculty::getDepartment(){
  return department;
}

//get faculty id
int faculty::getId(){
  return id;
}

//get faculty advisees (students they teach)
DoublyLinkedList<int> faculty::getAdvisees(){
  return advisees;
}

void faculty::printData(){
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  advisees.printList();
  cout << "----------" << endl;
}

//faculty function to add advisees
void faculty::addAdvisee(int id){
  advisees.insertBack(id);
}

//faculty function to remove advisees
void faculty::removeAdvisee(int id){
  advisees = advisees.deleteFromList(id);
}

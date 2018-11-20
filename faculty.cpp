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


string faculty::getName(){
  return name;
}

string faculty::getLevel(){
  return level;
}

string faculty::getDepartment(){
  return department;
}

int faculty::getId(){
  return id;
}

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

void faculty::addAdvisee(int id){
  advisees.insertBack(id);
}



/*
void faculty::addAdvisee(int id) {
  if(numAdvisee != maxSize) {
    int temp = 0;

    for(int i = 0; i < maxSize; i++) {
      if(adviseeArray[i] == id) {
        temp = maxSize;
      }
    }

    while(temp < maxSize) {
      if(adviseeArray[temp] == -1) {
        adviseeArray[temp] = id;
        numAdvisee++;
        break;
      }

      ++temp;
    }
  }
  else {
    if(numAdvisee == maxSize) {
      int *tempArray = new int[numAdvisee];

      for(int i = 0; i < numAdvisee; i++) {
        tempArray[i] = adviseeArray[i];
      }

      adviseeArray = new int[numAdvisee + 1];
      maxSize = numAdvisee + 1;

      for(int i = 0; i < numAdvisee; ++i) {
        adviseeArray[i] = tempArray[i];
      }

      for(int i = numAdvisee; i < numAdvisee + 1; i++) {
        adviseeArray[i] = -1;
      }

      adviseeArray[numAdvisee++] = id;
    }
  }
}

bool faculty::removeAdvisee(int adviseeID) {
  bool removed = false;

  for(int i = 0; i < maxSize; i++) {
    if(adviseeArray[i] == adviseeID) {
      adviseeArray[i] = -1;
      numAdvisee--;
      removed = true;
    }

    if(!removed) {
      cout << "The advisee was removed" << endl;
    }

    return removed;
  }
}
*/

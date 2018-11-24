#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "database.h"
#include <stdlib.h>

using namespace std;

database::database(){
  string currentLine = "";
  //Populates the student table
  ifstream students;
  students.open("studentTable.txt");
  int counter;
  string tempName;
  int tempId;
  string tempLevel;
  string tempMajor;
  double tempGPA;
  int tempAdvisor;
  while(!students.eof()){
    counter = 0;
    currentLine = "";
    while(currentLine != "+"){
      counter++;
      students >> currentLine;
      if(counter == 1){
        tempName = currentLine;
      }else if(counter == 2){
        tempId = stoi(currentLine.c_str());
        studentIDs.insertBack(tempId);
      }else if(counter == 3){
        tempLevel = currentLine;
      }else if(counter == 4){
        tempGPA = stod(currentLine);
      }else if(counter == 5){
        tempMajor = currentLine;
      }else if(counter == 6){
        if(currentLine != "+"){
        tempAdvisor = stoi(currentLine.c_str());
        }
      }else{
        //NOthing
      }
    }
    student s(tempId, tempName, tempLevel, tempGPA, tempAdvisor, tempMajor);
    masterStudent.insert(s);
  }
  students.close();

  //populates the faculty table

  ifstream facultyMems;
  facultyMems.open("facultyTable.txt");
  string tempN;
  int tempI;
  string tempL;
  string tempD;
  DoublyLinkedList<int> tempAdvisees;
  DoublyLinkedList<int> bl;
  while(!facultyMems.eof()){
    counter = 0;
    currentLine = "";
    while(currentLine != "+"){
      counter ++;
      facultyMems >> currentLine;
      if(counter == 1){
        tempN = currentLine;
      }else if(counter == 2){
        tempI = stoi(currentLine.c_str());
        facultyIDs.insertBack(tempI);
      }else if(counter == 3){
        tempL = currentLine;
      }else if(counter == 4){
        tempD = currentLine;
      }else{
        if(currentLine != "+"){
        tempAdvisees.insertBack(stoi(currentLine.c_str()));
        }
      }
    }
    faculty f(tempI, tempN, tempL, tempD, tempAdvisees);
    masterFaculty.insert(f);
    tempAdvisees = bl;
  }
}

void database::saveDB(){
  masterStudent.outputTreeStudent("studentTable.txt");
  masterFaculty.outputTreeFaculty("facultyTable.txt");
}

void database::debugDB(){
  changeAdvisor();
  saveDB();
}

void database::printAllStudent(){
  masterStudent.stuPrint();
}

void database::printAllFaculty(){
  masterFaculty.facPrint();
}

void database::printStudent(int id){
  student temp = masterStudent.find(id);
  temp.printInfo();
}

void database::printFaculty(int id){
  faculty temp = masterFaculty.find(id);
  temp.printData();
}

void database::printAdvisor(int id){
  student temp = masterStudent.find(id);
  int advisorID = temp.getAdvisor();
  printFaculty(advisorID);
}

void database::addStudent(){
  string newName;
  string newLevel;
  string newMajor;
  double newGPA;
  int newAdvisor;
  int numberAdvisors = facultyIDs.getSize();
  newAdvisor = facultyIDs.returnPos(rand() % numberAdvisors);
  int newID = rand() % 5000 + 1;
  while(studentIDs.contains(newID) || facultyIDs.contains(newID)){
    newID = rand() % 5000 + 1;
  }
  cout << "Enter the Name of the Student(No Spaces):" << endl;
  cin >> newName;
  cout << "Enter the Student's major(No Spaces): " << endl;
  cin >> newMajor;
  cout << "Enter the students level: " << endl;
  cin >> newLevel;
  cout << "Enter the students GPA: " << endl;
  cin >> newGPA;
  student s(newID, newName, newLevel, newGPA, newAdvisor, newMajor);
  faculty temp = masterFaculty.find(newAdvisor);
  temp.addAdvisee(newID);
  masterStudent.insert(s);
}

void database::addFaculty(){
  string newName;
  string newLevel;
  string newDepartment;
  DoublyLinkedList<int> adviseeList;
  int newID = rand() % 5000 + 1;
  while(studentIDs.contains(newID) || facultyIDs.contains(newID)){
    newID = rand() % 5000 + 1;
  }

  cout << "Enter the name of the Faculty(No Spaces):" << endl;
  cin >> newName;
  cout << "Enter the level of the faculty(No Spaces):" << endl;
  cin >> newLevel;
  cout << "Enter the faculty's department(No Spaces):" << endl;
  cin >> newDepartment;
  faculty f(newID, newName, newLevel, newDepartment, adviseeList);
  masterFaculty.insert(f);

}


void database::changeAdvisor(){
  int stuID;
  int newFacID;

  cout << "Enter a student ID" << endl;
  cin >> stuID;
  cout << "Enter the faculty ID" << endl;
  cin >> newFacID;
  faculty newAdvisor = masterFaculty.find(newFacID);
  student s = masterStudent.find(stuID);
  faculty oldAdvisor = masterFaculty.find(s.getAdvisor());

  newAdvisor.addAdvisee(stuID);
  masterFaculty.deleteNode(newAdvisor);
  masterFaculty.insert(newAdvisor);

  oldAdvisor.removeAdvisee(stuID);
  masterFaculty.deleteNode(oldAdvisor);
  masterFaculty.insert(oldAdvisor);

  s.changeAdvisor(newFacID);
  masterStudent.deleteNode(s);
  masterStudent.insert(s);


}


void database::printAdvisees(int id){
  faculty temp = masterFaculty.find(id);
  DoublyLinkedList<int> fa = temp.getAdvisees();
  ListNode<int> *curr = fa.getFront();
  while(curr != NULL){
    printStudent(curr->data);
    curr = curr->next;
  }
}

database::~database(){

}

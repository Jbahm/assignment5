#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "database.h"

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
      }else if(counter == 3){
        tempLevel = currentLine;
      }else if(counter == 4){
        tempGPA = stod(currentLine);
      }else if(counter == 5){
        if(currentLine != "+"){
        tempAdvisor = stoi(currentLine.c_str());
        }
      }else{
        //do nothing
      }
    }
    student s(tempId, tempName, tempLevel, tempGPA, tempAdvisor);
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
  while(!facultyMems.eof()){
    counter = 0;
    currentLine = "";
    while(currentLine != "+"){
      counter ++;
      facultyMems >> currentLine;
      if(counter == 1){
        cout << currentLine << endl;
        tempN = currentLine;
      }else if(counter == 2){
        cout << currentLine << endl;
        tempI = stoi(currentLine.c_str());
      }else if(counter == 3){
        cout << currentLine << endl;
        tempL = currentLine;
      }else if(counter == 4){
        cout << currentLine << endl;
        tempD = currentLine;
      }else{
        if(currentLine != "+"){
        cout << currentLine << endl;
        tempAdvisees.insertBack(stoi(currentLine.c_str()));
        }
      }
    }
    faculty f(tempI, tempN, tempL, tempD, tempAdvisees);
    masterFaculty.insert(f);
  }
}

void database::saveDB(){
  masterStudent.outputTreeStudent("studentTable.txt");
  masterFaculty.outputTreeFaculty("facultyTable.txt");
}

void database::debugDB(){
  DoublyLinkedList<int> advisees;
  advisees.insertBack(1);
  advisees.insertBack(2);
  faculty f(45, "Jose", "Lecturer", "GCI", advisees);
  masterFaculty.insert(f);
  saveDB();
}


database::~database(){

}

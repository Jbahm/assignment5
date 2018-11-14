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
        tempAdvisor = stoi(currentLine.c_str());
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
        tempN = currentLine;
      }else if(counter == 2){
        tempI = stoi(currentLine.c_str());
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
  }
}

void database::saveDB(){
  masterStudent.outputTree("studentTable.txt");
}

void database::debugDB(){
  masterFaculty.printTree();
}


database::~database(){

}

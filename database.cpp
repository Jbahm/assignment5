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
  int counter;
  string tempName;
  int tempId;
  string tempLevel;
  string tempMajor;
  double tempGPA;
  int tempAdvisor;
  students.open("studentTable.txt");
  if(students.fail()){
    students.close();
   cout << "StudentTable does not exsist, creating now...." << endl;
   ofstream tempOut;
   tempOut.open("studentTable.txt");
   tempOut << "";
   tempOut.close();
  }else{
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
  }
  //populates the faculty table
  ifstream facultyMems;
  facultyMems.open("facultyTable.txt");
  string tempN;
  int tempI;
  string tempL;
  string tempD;
  DoublyLinkedList<int> tempAdvisees;
  DoublyLinkedList<int> bl;
  if(facultyMems.fail()){
    facultyMems.close();
   cout << "FacultyTable does not exsist, creating now...." << endl;
   ofstream tempOut2;
   tempOut2.open("facultyTable.txt");
   tempOut2 << "";
   tempOut2.close();
  }else{
  while(!facultyMems.eof()){
    counter = 0;
    currentLine = "";
    while(currentLine != "+"){
      counter ++;
      facultyMems >> currentLine;
      if(counter == 1){
        tempN = currentLine;
      }else if(counter == 2){
        tempI = stoi(currentLine.c_str());;
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
}

//repopulate the tables
void database::repopulate(){
  string currentLine = "";
  BST<student> newStuMast;
  BST<faculty> newFacMast;
  //Populates the student table
  ifstream students;
  int counter;
  string tempName;
  int tempId;
  string tempLevel;
  string tempMajor;
  double tempGPA;
  int tempAdvisor;
  students.open("studentTable.txt");
  if(students.fail()){
    students.close();
   cout << "StudentTable does not exsist, creating now...." << endl;
   ofstream tempOut;
   tempOut.open("studentTable.txt");
   tempOut << "";
   tempOut.close();
  }else{
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
    newStuMast.insert(s);
  }
  students.close();
  }
  //populates the faculty table
  ifstream facultyMems;
  facultyMems.open("facultyTable.txt");
  string tempN;
  int tempI;
  string tempL;
  string tempD;
  DoublyLinkedList<int> tempAdvisees;
  DoublyLinkedList<int> bl;
  if(facultyMems.fail()){
    facultyMems.close();
   cout << "FacultyTable does not exsist, creating now...." << endl;
   ofstream tempOut2;
   tempOut2.open("facultyTable.txt");
   tempOut2 << "";
   tempOut2.close();
  }else{
  while(!facultyMems.eof()){
    counter = 0;
    currentLine = "";
    while(currentLine != "+"){
      counter ++;
      facultyMems >> currentLine;
      if(counter == 1){
        tempN = currentLine;
      }else if(counter == 2){
        tempI = stoi(currentLine.c_str());;
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
    newFacMast.insert(f);
    tempAdvisees = bl;
  }
  }

  masterFaculty = newFacMast;
  masterStudent = newStuMast;
}



//save database to textfiles
void database::saveDB(){
  masterStudent.outputTreeStudent("studentTable.txt", studentIDs);
  masterFaculty.outputTreeFaculty("facultyTable.txt", facultyIDs);
}

//function to update faculty info
void database::updateFacInfo(int id, string newName, string newLevel, string newDepartment, DoublyLinkedList<int> newAdvisees){
  faculty newFac(id, newName, newLevel, newDepartment, newAdvisees);
  facultyIDs = facultyIDs.deleteFromList(id);
  saveDB();
  repopulate();
  masterFaculty.insert(newFac);
  facultyIDs.insertBack(id);
}

//function to update student info
void database::updateStuInfo(int id, string newName, string newLevel, double newGPA, int newAdvisor, string newMaj){
  student newStu(id, newName, newLevel, newGPA, newAdvisor, newMaj);
  studentIDs = studentIDs.deleteFromList(id);
  saveDB();
  repopulate();
  masterStudent.insert(newStu);
  studentIDs.insertBack(id);
}


//Print all student info by ascending id function
void database::printAllStudent(){
  masterStudent.stuPrint();
}

//Print all faculty info by ascending id function
void database::printAllFaculty(){
  masterFaculty.facPrint();
}

//Print student info by student id function
void database::printStudent(int id){
  student temp = masterStudent.find(id);
  temp.printInfo();
}

//Print all faculty info by faculty id function
void database::printFaculty(int id){
  faculty temp = masterFaculty.find(id);
  temp.printData();
}

//Print advisor info by student id function
void database::printAdvisor(int id){
  student temp = masterStudent.find(id);
  int advisorID = temp.getAdvisor();
  printFaculty(advisorID);
}

//Print advisee info by faculty id function
void database::printAdvisees(int id){
  faculty temp = masterFaculty.find(id);
  DoublyLinkedList<int> fa = temp.getAdvisees();
  ListNode<int> *curr = fa.getFront();
  while(curr != NULL){
    printStudent(curr->data);
    curr = curr->next;
  }
}

//Add a new student function
void database::addStudent(){
  string newName;
  string newLevel;
  string newMajor;
  double newGPA;
  int newAdvisor;
  int numberAdvisors = facultyIDs.getSize();
  newAdvisor = facultyIDs.returnPos(rand() % numberAdvisors);
  int newID = rand() % 5000 + 1;
  while(studentIDs.contains(newID)){
    newID = rand() % 5000 + 1;
  }
  studentIDs.insertBack(newID);
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
  DoublyLinkedList<int> nA = temp.getAdvisees();
  nA.insertBack(newID);
  updateFacInfo(newAdvisor, temp.getName(), temp.getLevel(), temp.getDepartment(), nA);
  masterStudent.insert(s);
  cout<<"*Student Added*"<<endl;
}

//Add a new faculty function
void database::addFaculty(){
  string newName;
  string newLevel;
  string newDepartment;
  DoublyLinkedList<int> adviseeList;
  int newID = rand() % 5000 + 1;
  while(studentIDs.contains(newID) || facultyIDs.contains(newID)){
    newID = rand() % 5000 + 1;
  }
  facultyIDs.insertBack(newID);
  cout << "Enter the name of the Faculty(No Spaces):" << endl;
  cin >> newName;
  cout << "Enter the level of the faculty(No Spaces):" << endl;
  cin >> newLevel;
  cout << "Enter the faculty's department(No Spaces):" << endl;
  cin >> newDepartment;
  faculty f(newID, newName, newLevel, newDepartment, adviseeList);
  masterFaculty.insert(f);
  cout<<"*Faculty Added*"<<endl;
}

//change advisor function
void database::changeAdvisor(){
  int stuID;
  int newFacID;
  cout << "Enter the Student's ID" << endl;
  cin >> stuID;
  while(!studentIDs.contains(stuID)){
    cout << "Invalid Student ID, Try again:" << endl;
    cin >> stuID;
  }
  cout << "Enter the ID of the new Advisor" << endl;
  cin >> newFacID;
  while(!facultyIDs.contains(newFacID)){
    cout << "Invalid faculty ID, Try again:" << endl;
    cin >> newFacID;
  }
  student s = masterStudent.find(stuID);
  faculty oldAdvisor = masterFaculty.find(s.getAdvisor());
  faculty newAdvisor = masterFaculty.find(newFacID);
  updateStuInfo(stuID, s.getName(), s.getLevel(), s.getGPA(), newFacID, s.getMajor());
  oldAdvisor.removeAdvisee(stuID);
  newAdvisor.addAdvisee(stuID);
  updateFacInfo(oldAdvisor.getId(), oldAdvisor.getName(), oldAdvisor.getLevel(), oldAdvisor.getDepartment(), oldAdvisor.getAdvisees());
  updateFacInfo(newAdvisor.getId(), newAdvisor.getName(), newAdvisor.getLevel(), newAdvisor.getDepartment(), newAdvisor.getAdvisees());
  cout<<"*Advisor Changed*"<<endl;

}


//Delete a student by student id function
void database::deleteStudent(int id){
  studentIDs = studentIDs.deleteFromList(id);
  student s = masterStudent.find(id);
  faculty f = masterFaculty.find(s.getAdvisor());
  DoublyLinkedList<int> newAdvisees = f.getAdvisees();
  newAdvisees = newAdvisees.deleteFromList(id);
  updateFacInfo(f.getId(), f.getName(), f.getLevel(), f.getDepartment(), newAdvisees);
  cout<<"*Student Deleted*"<<endl;
}

//Delete faculty by faculty id function
void database::deleteFaculty(int id){
  faculty f= masterFaculty.find(id);
  DoublyLinkedList<int> advisees = f.getAdvisees();
  facultyIDs = facultyIDs.deleteFromList(id);
  int numberAdvisors = facultyIDs.getSize();
  int newAdvisor = facultyIDs.returnPos(rand() % numberAdvisors);
  ListNode<int> *curr = advisees.getFront();
  faculty newA = masterFaculty.find(newAdvisor);
  DoublyLinkedList<int> nA = newA.getAdvisees();

  while(curr != NULL){
    student s = masterStudent.find(curr->data);
    updateStuInfo(s.getId(), s.getName(), s.getLevel(), s.getGPA(), newAdvisor, s.getMajor());
    nA.insertBack(s.getId());
    curr = curr->next;
  }
  updateFacInfo(newAdvisor, newA.getName(), newA.getLevel(), newA.getDepartment(), nA);
  cout<<"*Faculty Deleted*"<<endl;

}

//Remove advisee by student & faculty ids function (removing the stdent from the facultys list of students)
void database::removeAdvisee(int id){
  int stuID;
  int facID;
  cout << "Enter the ID of the Advisor" << endl;
  cin >> facID;
  while(!facultyIDs.contains(facID)){
    cout << "Invalid faculty ID, Try again:" << endl;
    cin >> facID;
  }
  cout << "Enter the Student's ID" << endl;
  cin >> stuID;
  while(!studentIDs.contains(stuID)){
    cout << "Invalid Student ID, Try again:" << endl;
    cin >> stuID;
  }
  student s = masterStudent.find(stuID);
  faculty f = masterFaculty.find(s.getAdvisor());
  DoublyLinkedList<int> newAdvisees = f.getAdvisees();
  newAdvisees = newAdvisees.deleteFromList(id);
  cout<<"*Advisee Removed*"<<endl;
}

//exit function
void database::exit(){
  cout<<"Exiting the program."<<endl;
  saveDB();
  cout<<"Exiting the program..."<<endl;
}

//print the main menu function
void database::printMenu(){
  string menuinput;
  int numinput;
  bool true_ = true;
  int id;

  while(true){
    cout <<"*Please choose a menu option*" << endl;
    cout << 1 << ".  Print all student info by ascending id" << endl;
    cout << 2 << ".  Print all faculty info by ascending id" << endl;
    cout << 3 << ".  Print student info by student id" << endl;
    cout << 4 << ".  Print faculty info by faculty id" << endl;
    cout << 5 << ".  Print advisor info by student id" << endl;
    cout << 6 << ".  Print advisee info by faculty id" << endl;
    cout << 7 << ".  Add a new student" << endl;
    cout << 8 << ".  Delete a student by student id" << endl;
    cout << 9 << ".  Add a new faculty" << endl;
    cout << 10 << ". Delete faculty by faculty id" << endl;
    cout << 11 << ". Change advisor by student & faculty ids" << endl;
    cout << 12 << ". Remove advisee by student & faculty ids" << endl;
    cout << 13 << ". Rollback" << endl;
    cout << 14 << ". Exit" << endl;
    cout<<"*****************************************************"<<endl;

    cin >> menuinput;
    numinput = stoi(menuinput.c_str());

    switch (numinput) {
      case 1:
        printAllStudent();
        break;
      case 2:
        printAllFaculty();
        break;
      case 3:
        cout<<"Enter the student id..."<<endl;
        cin>>id;
        printStudent(id);
        break;
      case 4:
        cout<<"Enter the faculty id..."<<endl;
        cin>>id;
        printFaculty(id);
        break;
      case 5:
        cout<<"Enter the student id..."<<endl;
        cin>>id;
        printAdvisor(id);
        break;
      case 6:
        cout<<"Enter the faculty id..."<<endl;
        cin>>id;
        printAdvisees(id);
        break;
      case 7:
        addStudent();
        saveDB();
        break;
      case 8:
        cout<<"Enter the student id..."<<endl;
        cin>>id;
        deleteStudent(id);
        saveDB();
        break;
      case 9:
        addFaculty();
        saveDB();
        break;
      case 10:
        cout<<"Enter the faculty id..."<<endl;
        cin>>id;
        deleteFaculty(id);
        saveDB();
        break;
      case 11:
        changeAdvisor();
        saveDB();
        break;
      case 12:
        removeAdvisee(id);
        saveDB();
        break;
      case 13:
        //rollback();
        break;
      case 14:
        exit();
        return;
      default:
        cout<<"Please enter a valid menu option."<<endl;
        continue;
    }
  }
}
void database::debugDB(){
  printMenu();
}

database::~database(){

}

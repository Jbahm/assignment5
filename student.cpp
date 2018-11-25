#include <iostream>
#include "student.h"

using namespace std;



student::student(){
  name = "";
  id = -1;
  level = "";
  gpa = -1.0;
  advisor = 0;
}


student::student(int idNum, string n, string lev, double grade, int fac, string maj){
  id = idNum;
  name = n;
  level = lev;
  major = maj;
  gpa = grade;
  advisor = fac;
}

//get student name
string student::getName(){
  return name;
}

//get student grade
string student::getLevel(){
  return level;
}

//get student gpa
double student::getGPA(){
  return gpa;
}

//print all student info
void student::printInfo(){
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "Advisor: " << advisor << endl;
  cout << "----------" << endl;
}

//function to get advisor
int student::getAdvisor(){
  return advisor;
}

//function to get major
string student::getMajor(){
  return major;
}

//function to set a new advisor 
void student::setAdvisor(int newAdvisor){
  advisor = newAdvisor;
}

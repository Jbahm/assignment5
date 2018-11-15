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

string student::getName(){
  return name;
}

string student::getLevel(){
  return level;
}

double student::getGPA(){
  return gpa;
}

void student::printInfo(){
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "----------" << endl;
}

int student::getAdvisor(){
  return advisor;
}

string student::getMajor(){
  return major;
}

void student::changeAdvisor(int newAdvisor){
  advisor = newAdvisor;
}

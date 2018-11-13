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


student::student(int idNum, string n, string lev, double grade, int fac){
  id = idNum;
  name = n;
  level = lev;
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

int student::getAdvisor(){
  return advisor;
}

void student::changeAdvisor(int newAdvisor){
  advisor = newAdvisor;
}

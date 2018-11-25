#include <iostream>
#include "person.h"

using namespace std;



class student: public person{
  public:
    student();
    student(int idNum, string n, string lev, double grade, int fac, string maj);
    string name;
    string major;
    string level;
    double gpa;
    int advisor;

    string getName(); //get student name
    string getLevel();//print student level
    void printInfo(); //print student data
    double getGPA(); //get student gpa
    int getAdvisor(); //get student advisor
    string getMajor();  //get student major
    void setAdvisor(int newAdvisor); //set new advisor for student 

};

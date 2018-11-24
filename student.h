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

    string getName();
    void printData();
    string getLevel();
    void printInfo();
    double getGPA();
    int getAdvisor();
    string getMajor();
    void setAdvisor(int newAdvisor);

};

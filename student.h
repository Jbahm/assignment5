#include <iostream>
#include "person.h"

using namespace std;



class student: public person{
  public:
    student();
    student(int idNum, string n, string lev, double grade, int fac);
    string name;
    string level;
    double gpa;
    int advisor;

    string getName();
    string getLevel();
    double getGPA();
    int getAdvisor();
    void changeAdvisor(int newAdvisor);



};

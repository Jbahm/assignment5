#include <iostream>
#include "student.h"
#include "faculty.h"
#include "BST.h"

using namespace std;


class database
{
  public:
    database();
    ~database();

    void debugDB();
    void saveDB();
    void printAllStudent(); //Menu 1
    void printAllFaculty(); //Menu 2
    void printStudent(int id); //Menu 3
    void printFaculty(int id); //Menu 4
    void printAdvisor(int id); //Menu 5
    void printAdvisees(int id); //Menu 6





    BST<student> masterStudent;
    BST<faculty> masterFaculty;

};

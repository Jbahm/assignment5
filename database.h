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
    void printAllStudent();
    void printAllFaculty();
    void printStudent(int id);
    void printFaculty(int id);



    BST<student> masterStudent;
    BST<faculty> masterFaculty;

};

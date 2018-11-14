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




    BST<student> masterStudent;
    BST<faculty> masterFaculty;

};

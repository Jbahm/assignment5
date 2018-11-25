#include <iostream>
#include <string>
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
    void saveDB(); //saves the database
    void updateStuInfo(int id, string newName, string newLevel, double newGPA, int newAdvisor, string newMaj);  //updates the student info
    void updateFacInfo(int id, string newName, string newLevel, string newDepartment, DoublyLinkedList<int> newAdvisees); //updates the faculty info
    void repopulate(); //repopulates the tables of both student and faculty 

    void printMenu(); //print menu function
    void printAllStudent(); //Menu 1
    void printAllFaculty(); //Menu 2
    void printStudent(int id); //Menu 3
    void printFaculty(int id); //Menu 4
    void printAdvisor(int id); //Menu 5
    void printAdvisees(int id); //Menu 6
    void addStudent();//Menu 7
    void deleteStudent(int id); //menu 8
    void addFaculty();//Menu 9
    void deleteFaculty(int id);//menu 10
    void changeAdvisor();//Menu 11
    void removeAdvisee(int id);//menu 12
    void exit();//menu 14


    BST<student> masterStudent; //bst for students
    DoublyLinkedList<int> studentIDs; //doubly linked list for students
    DoublyLinkedList<int> facultyIDs; //doubly linked list for faculty
    BST<faculty> masterFaculty; //bst for faculty

};

#include <iostream>
#include "person.h"

using namespace std;



person::person(){
  id = -1;
}

//person class
person::person(int idNum){
  id = idNum;
}

//get id of person class
int person::getId(){
  return id;
}

//print data of person class
void person::printData(){
  cout << id << endl;
}

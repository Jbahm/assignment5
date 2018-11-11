#include <iostream>
#include "person.h"

using namespace std;



person::person(){
  id = -1;
}


person::person(int idNum){
  id = idNum;
}

int person::getId(){
  return id;
}

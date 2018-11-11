#include <iostream>
#include "faculty.h"

using namespace std;



faculty::faculty(){
  name = "";
  id = -1;
  level = "";
  department = "";
}


faculty::faculty(int idNum, string n, string lev, string depart){
  id = idNum;
  name = n;
  level = lev;
  department = depart;
}

string faculty::getName(){
  return name;
}

string faculty::getLevel(){
  return level;
}

string faculty::getDepartment(){
  return department;
}

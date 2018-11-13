#include <iostream>
#include "BST.h"
#include "TreeNode.h"
#include "student.h"



int main(int argc, char** argv){
  student bob(3, "bob", "freshman", 2.3, 22);
  student jeff(9, "jeff", "senior", 3.5, 18);
  student steve(2, "steve", "senior", 3.5, 34);
  BST<student> test;
  cout << test.isEmpty() << endl;
}

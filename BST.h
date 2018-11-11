#include <iostream>
#include "TreeNode.h"
using namespace std;

template <classT>
class BST(){

public:
  BST();
  virtual ~BST();

  void insert(int value);
  bool contains(int value);
  bool deleteNode(int value);
  bool deleteRec(TreeNode *node);
  bool isEmpty();

  void printTree();
  void recPrint(TreeNode *node); //in order traversal

private:
  TreeNode *root;

};

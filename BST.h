#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include "TreeNode.h"
#include "DoublyLinkedList.h"
using namespace std;

template <class T>
class BST{

public:
  BST();
  virtual ~BST();

  void insert(T data); //tested and working
  bool contains(T data); // tested and working
  T find(int target);
  bool deleteNode(T data); // Works but it refuses to delete the first person entered(Maybe insert a dummy at the top of each tree to fix w/ ID 0)
  TreeNode<T>* getSuccessor(TreeNode<T> *d);
  bool isEmpty(); //tested and works

  void outputTreeStudent(string filename, DoublyLinkedList<int> ids);
  void outputTreeFaculty(string filenam, DoublyLinkedList<int> ids);
  void facPrint();
  void stuPrint();
  void printTree(); //tested and works
  void recPrint(TreeNode<T> *node); //in order traversal
  void printStu(TreeNode<T> *node);
  void printFac(TreeNode<T> *node);
  void studentOutput(TreeNode<T> *node, bool isFirst, DoublyLinkedList<int> ids);
  void facultyOutput(TreeNode<T> *node, bool isFirst, DoublyLinkedList<int> ids);

private:
  TreeNode<T> *root;

};

template <class T>
BST<T>::BST()
{
  root = NULL;

}

template <class T>
BST<T>::~BST()
{

}

//prints the bst
template <class T>
void BST<T>::printTree()
{
  recPrint(root);
}

//prints student bst
template <class T>
void BST<T>::stuPrint()
{
  printStu(root);
}

//prints faculty bst
template <class T>
void BST<T>::facPrint()
{
  printFac(root);
}



//outputs the student bst into the file
template <class T>
void BST<T>::outputTreeStudent(string filename, DoublyLinkedList<int> ids)
{
  std::ofstream ofs;
  ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  studentOutput(root, true, ids);
}

//outputs the faculty bst into the file
template <class T>
void BST<T>::outputTreeFaculty(string filename, DoublyLinkedList<int> ids)
{
  std::ofstream ofs;
  ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  facultyOutput(root, true, ids);
}

//checks to see if bst is empty
template <class T>
bool BST<T>::isEmpty()
{
  return root == NULL;
}

//prints
template <class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
  if(node == NULL){
    return;
  }
  recPrint(node->left);
  //node->key.printData();
  recPrint(node->right);
}

//prints student bst
template <class T>
void BST<T>::printStu(TreeNode<T> *node)
{
  if(node == NULL){
    return;
  }
  printStu(node->left);
  node->key.printInfo();
  printStu(node->right);
}

//prints faculty bst
template <class T>
void BST<T>::printFac(TreeNode<T> *node)
{
  if(node == NULL){
    return;
  }
  printFac(node->left);
  node->key.printData();
  printFac(node->right);
}




template <class T>
void BST<T>::studentOutput(TreeNode<T> *node, bool isFirst, DoublyLinkedList<int> ids)
{
  if(node == NULL){
  return;
  }
  if(ids.contains(node->key.getId())){
  ofstream outfile;
  outfile.open("studentTable.txt", std::ios_base::app);
  if(isFirst == true){
  outfile << node->key.getName() << "\r\n";
  }else{
  outfile << "\r\n";
  outfile << node->key.getName() << "\r\n";
  }
  outfile << node->key.getId() << "\r\n";
  outfile << node->key.getLevel() << "\r\n";
  outfile << node->key.getGPA() << "\r\n";
  outfile << node->key.getMajor() << "\r\n";
  outfile << node->key.getAdvisor() << "\r\n";
  outfile << "+";
  outfile.close();
  }
  studentOutput(node->left, false, ids);
  studentOutput(node->right, false, ids);
}

template <class T>
void BST<T>::facultyOutput(TreeNode<T> *node, bool isFirst, DoublyLinkedList<int> ids)
{
    if(node == NULL){
    return;
    }
    if(ids.contains(node->key.getId())){
    ofstream outfile;
    outfile.open("facultyTable.txt", std::ios_base::app);
    if(isFirst == true){
    outfile << node->key.getName() << "\r\n";
    }else{
    outfile << "\r\n";
    outfile << node->key.getName() << "\r\n";
    }
    outfile << node->key.getId() << "\r\n";
    outfile << node->key.getLevel() << "\r\n";
    outfile << node->key.getDepartment() << "\r\n";
    outfile.close();
    DoublyLinkedList<int> currentAdvisees = node->key.getAdvisees();
    ofstream outfile2;
    outfile2.open("facultyTable.txt", std::ios_base::app);
    currentAdvisees.outputList("facultyTable.txt");
    outfile2 << "+";
    outfile2.close();
    }
    facultyOutput(node->left, false, ids);
    facultyOutput(node->right, false, ids);
}






//insert into bst
template <class T>
void BST<T>::insert(T data)
{
  //check for duplicates
  TreeNode<T> *node = new TreeNode<T>(data);

  if(isEmpty()){
    root = node;
  }else{//not an empty tree, find insertion point
    TreeNode<T> *current = root;
    TreeNode<T>  *parent; //empty TreeNode
    while(true){
      parent = current;
      int value1 = data.getId();
      int value2 = current->key.getId();
      if(value1 < value2){//go left
        current = current->left;

        if(current == NULL)//we found the insertion point
        {
          parent->left = node;
          break;
        }
      }
      else
      {
        current = current->right;

        if(current == NULL)//we found the insertion point
        {
          parent->right = node;
          break;
        }

      }
    }
  }

}





//search method
template <class T>
bool BST<T>::contains(T data)
{
  if(isEmpty()){
    return false;
  }else{//not an empty tree, continue to search
    TreeNode<T> *current = root;
    while(current != NULL){
      if(current == NULL){
        return false;
      }
      if(data.getId() < current->key.getId()){
        current = current->left;
      }else if(data.getId() == current->key.getId()){
        return true;
      }else{
          current = current->right;
        }
      }
    }
  }


//find in the bst
template <class T>
T BST<T>::find(int target)
  {
    if(isEmpty()){
      cout << "Empty!" << endl;
    }else{//not an empty tree, continue to search
      TreeNode<T> *current = root;
      while(current != NULL){
        if(target < current->key.getId()){
            current = current->left;
        }else if(target == current->key.getId()){
          return current->key;
          }else{
            current = current->right;
            }
          }
        }
      }


//delete a node in the bst
template <class T>
bool BST<T>::deleteNode(T data)
{
  //use contains method

  if(!contains(data)){
    return false;
  }
  //lets proceed to find the TreeNode
  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  while(current->key.getId() != data.getId()){
    parent = current;

    if(data.getId() < current->key.getId()){//go left
      isLeft = true;
      current = current->left;
    }else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    }
    //at this point we found the node to be deleted

    //lets check wether it is a leaf or not

    if(current->left == NULL && current->right == NULL){//then its a leaf
        if(current == root){
          root = NULL;
        }else if(isLeft){
          parent->left = NULL;
        }else{
          parent->right = NULL;
        }
    }else if(current->right = NULL){//no right child, must be isLeft
        if(current == root)
        {
          root = current->left;
        }else if(isLeft)
        {
          parent->left = current->left;
        }else{//right child
          parent->right = current->left;
        }
    }else if(current->left == NULL){//no left child, must be right
      if(current == root){
        root = current->right;
      }else if(isLeft){
        parent->left = current->right;
      }else{//right child
        parent->right = current->right;
      }

    }else{//it has two children, at this point we begin to cry and take a long nap
      TreeNode<T> *successor = getSuccessor(current);

      if(current == root){
        root = successor;
      }else if(isLeft){
        parent->left = successor;
      }else{
        parent->right = successor;
      }
    }

  }
  return true;
}

//get the successor in the bst 
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)
{
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;


  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){//descendant of right child, left most of right
    sp->left = successor->right;
    successor->right = d->right;

  }

  return successor;
}

#endif

#ifndef TreeNode_H
#define TreeNode_H


#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
  public:
    TreeNode();
    TreeNode(T d);
    ~TreeNode();

    T key;
    TreeNode *left;
    TreeNode *right;


};


//Constructor
template<class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

//constructor
template<class T>
TreeNode<T>::TreeNode(T d){
  key = d;
  left = NULL;
  right = NULL;
}

//deconstructor
template<class T>
TreeNode<T>::~TreeNode(){
  //
}

#endif

#ifndef TreeNode_H
#define TreeNode_H


#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
  public:
    TreeNode();
    TreeNode(int k);
    virtual ~TreeNode();//

    int key;
    TreeNode *left;
    TreeNode *right;


};



template<class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template<class T>
TreeNode<T>::TreeNode(int k){
  key = k;
  left = NULL;
  right = NULL;
}

#endif

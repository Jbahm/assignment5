#ifndef BST_H
#define BST_H



#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class T>
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

template <class T>
BST<T>::BST()
{
  root = NULL;

}

template <class T>
BST<T>::~BST()
{

}

template <class T>
void BST<T>::printTree()
{
  recPrint(root);
}

template <class T>
bool BST<T>::isEmpty()
{
  return root == NULL;
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
  if(node == NULL){
    return;
  }

  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}

template <class T>
void BST<T>::insert(T data)
{
  //check for duplicates
  TreeNode<T> *node = new TreeNode(data);

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

//STOPPED HERE




//search method
bool BST::contains(int value)
{
  if(isEmpty()){
    return false;
  }else{//not an empty tree, continue to search
    TreeNode *current = root;
    while(current->key != value){
      if(current == NULL){
        return false;
      }
      if(value < current->key){
        current = current->left;
      }else{
          current = current->right;
        }
      }
      return true;
    }
  }

bool BST::deleteRec(int k)
{
  //use contains method

  if(!contains(k)){
    return false;
  }
  //lets proceed to find the TreeNode
  TreeNode *current = root;
  TreeNode *parent = root;
  bool isLeft = true;

  while(current->key != k){
    parent = current;

    if(k < current->key){//go left
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
      TreeNode *successor = getSuccessor(current);

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

TreeNode* BST::getSuccessor(TreeNode *d)
{
  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *current = d->right;


  while(current != NULL){
    sp = succesor;
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

#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H


#include <iostream>
#include <fstream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList {

  public:
    unsigned int size;
    ListNode<T> *front;
    ListNode<T> *back;

    DoublyLinkedList(); //Constructor
    ~DoublyLinkedList(); //Destructor

    void insertBack(T data);
    T removeFront();
    ListNode<T>* getFront();

    void printList();
    void deletePos(int pos);
    T returnPos(int pos);
    void outputList(string filename);
    int returnLoc(int n);
    DoublyLinkedList<T> deleteFromList(T d);

    bool isEmpty();
    bool contains(T data);
    unsigned int getSize();
};

//constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  size = 0;
  front = NULL;
  back = NULL;
}

//deconstructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

}

//insert from the back
template <class T>
void DoublyLinkedList<T>::insertBack(T data) {
  ListNode<T> *node = new ListNode<T>(data);

   if(size == 0) { //if empty
       front = node;
   }

   else {  //Not Empty
       back->next = node;
       node->prev = back;
   }
   back = node;
   ++size;
}

//removes from the front
template <class T>
T DoublyLinkedList<T>::removeFront() {
  if(!isEmpty()) {
    ListNode<T> *node = front;

    if(front->next == NULL) { //Only Node in List
      front = NULL;
      back = NULL;
    }
    else {  //More than One
      front->next->prev = NULL;
      front = front->next;
    }

    T temp = node->data;
    delete node;
    size;
    return temp;
  }
  else {
    return T();
  }
}

//gets the front of the list 
template <class T>
ListNode<T>* DoublyLinkedList<T>::getFront() {
  return front;
}

//prints the list
template <class T>
void DoublyLinkedList<T>::printList() {
  ListNode<T> *curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//function to "find" in the list
template <class T>
bool DoublyLinkedList<T>::contains(T data){
  ListNode<T> *curr = front;
  while(curr != NULL){
    if(data == curr->data){
      return true;
    }
    curr = curr->next;
  }
  return false;
}

//returns the position in the list
template <class T>
T DoublyLinkedList<T>::returnPos(int pos){
  ListNode<T> *curr = front;
  for(int i = 0; i <= pos; i++){
    if(i == pos){
      return curr->data;
    }
    curr = curr->next;
  }
  return curr->data;
}


//deletes from the list
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::deleteFromList(T d){
  DoublyLinkedList<T> nList;
  ListNode<T> *curr = front;
  while(curr != NULL){
    if(curr->data != d){
    nList.insertBack(curr->data);
    }
    curr = curr->next;
  }
  return nList;
}

//outputs the list into a file
template <class T>
void DoublyLinkedList<T>::outputList(string filename) {
  ListNode<T> *curr = front;
  ofstream outfile;
  outfile.open("facultyTable.txt", std::ios_base::app);
  while(curr != NULL){
    outfile << curr->data << "\r\n";
    curr = curr->next;
  }
  outfile.close();
}

//delete at a position
template <class T>
void DoublyLinkedList<T>::deletePos(int pos) {
  pos--;
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

   while(idx != pos) {
     prev = curr;
     curr = curr->next;
     idx++;
   }

   prev->next = curr->next;
   curr->next->prev = prev;
   curr->next = NULL;
   //curr->prev = NULL;
   //curr->data = NULL;

   size--;
   delete curr;
}

//check to see if list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty() {
  return(size == 0);
}

//gets the size of the list
template <class T>
unsigned int DoublyLinkedList<T>::getSize() {
  return size;
}

#endif

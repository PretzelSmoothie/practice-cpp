/*

Implementation file for singly LinkedList object

Index starts at 1, not 0

*/

#include "LinkedList.hpp"

//Default Constructor
template <class T>
LinkedList<T>::LinkedList() {
 head = nullptr;
 tail = nullptr;
 size = 0;
}

//Constructor
template <class T>
LinkedList<T>::LinkedList(T val) {
  head = new ListNode(val);
  tail = head;
  size = 1;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList() {
  ListNode* ptr = head;
  while(ptr != nullptr){
    ListNode* garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

//Copy constructor
/*template <class T>
LinkedList<T>::LinkedList(const LinkedList &obj) {

}

//overloaded assignment operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &rhs) {

}*/

//Returns the size of LinkedList
template <class T>
int LinkedList<T>::getSize() const {
  return size;
}

//Returns True if list is empty
template <class T>
bool LinkedList<T>::isEmpty() const {
 if(head == nullptr){
    return true;
  }
  return false;
}

//Pushes a value at the given position (pos)
template <class T>
void LinkedList<T>::insert(int pos, T value) {

  if(head == nullptr || pos == 1){
    pushFront(value);

  }
  else if(pos > size){
    pushBack(value);
  }
  else{


    ListNode* ptr = head->next;
    ListNode* previousNode = head;
    int counter = 2; //as pos != 1, start at position 2
    while(ptr != nullptr && counter != pos){
      previousNode = ptr;
      ptr = ptr->next;
      counter++;
    }
    if(ptr == nullptr){ //if ptr is at null, reset tail
      tail = previousNode;
    }
    ListNode* temp = new ListNode(value, ptr);
    previousNode->next = temp;
    size++;
  }

}

//Pushes value to the front of the LinkedList
template <class T>
void LinkedList<T>::pushFront(T value) {
	ListNode* temp = new ListNode(value, head);
	if(isEmpty()) { tail = temp; }
	head = temp;
	size++;
}

//Pushes a value to the back of LinkedList
template <class T>
void LinkedList<T>::pushBack(T value){
  if(head == nullptr){
    pushFront(value);
  }
  else{
    ListNode* temp = new ListNode(value);
    tail->next = temp;
    tail = temp;
    size++;
  }
}

//Removes the value, throws error if it is not there
template <class T>
void LinkedList<T>::remove(T value) {
  if(head == nullptr){
    cout << endl << "List is empty.";
  }

  else if(head->value == value){
    ListNode* garbage = head;
    head = head->next;
    delete garbage;
  }

  else{
    ListNode* garbage = head->next;
    ListNode* previousNode = head;

    while(garbage != nullptr && garbage->value != value){
      previousNode = garbage;
      garbage = garbage->next;
    }
    if(garbage == nullptr){
      cout << endl << "Value does not exist in list, unable to remove";
    }
    else{ //Found node to be removed
      //check to see if tail needs to be reset
      if(garbage == tail){
	tail = garbage;
      }
      previousNode->next = garbage->next;
      delete garbage;
    }
  }
  size--;
}

//Reverse LinkedList
template <class T>
void LinkedList<T>::reverse() {
  if(isEmpty()){
    cout << endl << "List is empty.";
  }
  else{
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next;

    while(current != nullptr){
      next = current->next;
      current->next=prev;
      prev = current;
      current = next;
    }
    head = prev;
  }

}

template <class T>
void LinkedList<T>::display() {
  if(head == nullptr){
    cout << "List empty." << endl;
  }
  else{
    ListNode* ptr = head;
    while(ptr != nullptr){
      cout << ptr->value << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }
}

template class LinkedList<int>;
template class LinkedList<char>;
template class LinkedList<string>;
template class LinkedList<double>;

/*
      __       __
    .'  `'._.'`  '.
   |  .--;   ;--.  |
   |  (  /   \  )  |
    \  ;` /^\ `;  /
     :` .'._.'. `;
     '-`'.___.'`-'

*/

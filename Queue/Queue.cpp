/*
Implementation for a basic Queue data structure
*/

#include "Queue.hpp"

//Default Constructor
template<class T>
Queue<T>::Queue(){
  head = nullptr;
  tail = nullptr;
}
//Constructor
template<class T>
Queue<T>::Queue(T value){
  head = new Node(value);
  tail = head;
}
//Destructor
template<class T>
Queue<T>::~Queue(){
  Node* ptr = head;
  while(ptr != nullptr){
    Node* garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}
//pushes a value on to the back of the queue
template<class T>
void Queue<T>::enqueue(T value){
  if(isEmpty()){
    head = new Node(value);
    tail = head;
  }
  else{
    Node* temp = new Node(value);
    tail->next = temp;
    tail = temp;
  }
}
//removes and returns a value from the front of the queue
template<class T>
T Queue<T>::dequeue() {
  if(isEmpty()){
    throw std::standard_arg
  }
  Node* temp = head;
  head = head->next;
  T value = temp->value;
  delete temp;
  return value;
}
//returns true if Queue is empty
template<class T>
bool Queue<T>::isEmpty() const {
  if(head == nullptr){
    return true;
  }
  return false;
}

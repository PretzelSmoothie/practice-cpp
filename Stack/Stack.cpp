#include "Stack.hpp"

//Default Constructor
template <class T>
Stack<T>::Stack(){
 head = nullptr;
}

//Constructor
template <class T>
Stack<T>::Stack(T value){
  head = new Node(value);
}

//Destructor
template <class T>
Stack<T>::~Stack(){
  Node* ptr = head;
  while(ptr != nullptr){
    Node* garbage = ptr;
    ptr = ptr->next;
    delete garbage;
  }
}

//pushes value on to Stack
template <class T>
void Stack<T>::push(T value){
 if(isEmpty()){
   head = new Node(value);
 }
 else{
   Node* ptr = new Node(value, head);
   head = ptr;
 }
}

//pops value from Stack
template <class T>
void Stack<T>::pop(){
  if(isEmpty()){
    throw std::invalid_argument("Stack is empty");
  }
  else{
    Node* popped = head;
    head = head->next;
    delete popped;
  }
}

//returns top of the Stack
template <class T>
T Stack<T>::top() const{
  if(isEmpty()){
    throw std::invalid_argument("Stack is empty");
  }
  else{
    return head->value;
  }
}

//returns True if Stack is empty
template <class T>
bool Stack<T>::isEmpty() const{
  if(head == nullptr){
    return true;
  }
  return false;
}

template class Stack<int>;
template class Stack<char>;
template class Stack<double>;

/*
      __       __
    .'  `'._.'`  '.
   |  .--;   ;--.  |
   |  (  /   \  )  |
    \  ;` /^\ `;  /
     :` .'._.'. `;
     '-`'.___.'`-'

*/

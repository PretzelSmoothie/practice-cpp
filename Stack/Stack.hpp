/*

Header file for basic stack implementation.

*/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>


template <class T>
class Stack {
public:
  Stack(); //Default Constructor
  Stack(T); //Constructor
  ~Stack(); //Destructor
  void push(T); //pushes value on to Stack
  void pop(); //pops value from Stack
  T top() const; //returns top of the Stack
  bool isEmpty() const; //returns True if Stack is empty

private:
  struct Node{
    T value;
    Node* next;
    Node(T val, Node* nxt = nullptr){
      value = val;
      next = nxt;
    }
  };
  Node* head;
};

#endif

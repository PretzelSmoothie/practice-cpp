/*
Header file for my Queue data structure implementation
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template<class T>
class Queue{
public:
  Queue();
  Queue(T);
  ~Queue();
  void enqueue(T); //adds value at position at tail
  T dequeue(); //returns value and removes least recently added element(front)
  bool isEmpty() const; //returns true if empty
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
  Node* tail;
};

#endif

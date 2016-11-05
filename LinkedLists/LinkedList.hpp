/*
Header file for singly LinkedList object

*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

using namespace std;

template <class T>
class LinkedList {
public:
  LinkedList(); //default constructor
  LinkedList(T); //constructor
  ~LinkedList(); //destructor
  int getSize() const; //returns size of LinkedList
  bool isEmpty() const; //returns T if empty
  void insert(int, T); //pushes a value at a given position
  void pushFront(T); //pushes value to front of LinkedList
  void pushBack(T); //pushes value to back of LinkedList
  void remove(T); //removes value, throws error if not there
  void reverse(); //reverses LinkedList
  void display(); //displays list

private:

  struct ListNode{
    T value;
    ListNode* next;
    ListNode(T val, ListNode *nxt = nullptr){
      value = val;
      next = nxt;
    }
  };
  ListNode* head;
  ListNode* tail;
  int size;
};

#endif

/*
      __       __
    .'  `'._.'`  '.
   |  .--;   ;--.  |
   |  (  /   \  )  |
    \  ;` /^\ `;  /
     :` .'._.'. `;
     '-`'.___.'`-'

*/

/*
Main to test the LinkedList object.
*/
#include <iostream>
#include "LinkedList.hpp"

using std::cout;
using std::endl;
using std::string;

void pause(); 
void startMsg();


int main(){
  int n = 0, pos;
  LinkedList<int> l1;

  //start program w/welcome message
  startMsg();
  pause();

  cout << "Now testing the pushFront method.";

  /*while(n != -1){
    cout << endl
	 << "Please enter an integer (-1 to stop): ";
    cin >> n;
    if(n != -1) { l1.pushFront(n); }  
  } */

  cout << "Now testing the insert method.";

  while(n != -1){
    cout << endl
	 << "Please enter an integer (-1 to stop): ";
    cin >> n;
    if(n != -1) { 
      cout << "Please enter a position: ";
      cin >> pos;
      l1.insert(pos,n); 
    }  
  }
  
  l1.display();
  pause();
  
  cout << endl
       << "Please enter a value to delete from the list: ";
  cin >> n;

  l1.remove(n);

  l1.display();
  
  cout << endl << endl;
  return 0;
}

//pauses program
void pause(){
  cout << endl << "Press enter to continue...";
  cin.ignore();
}

//Display start message to tester
void startMsg(){
  cout << endl << endl << endl
       << "Welcome. This program tests the implementation of Connor Rice's LinkedList (singly)."
       << endl << endl;      
}
/*
      __       __
    .'  `'._.'`  '.
   |  .--;   ;--.  |
   |  (  /   \  )  |
    \  ;` /^\ `;  /
     :` .'._.'. `;
     '-`'.___.'`-'

*/

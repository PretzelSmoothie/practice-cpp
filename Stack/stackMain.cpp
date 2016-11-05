#include <iostream>
#include "stack.hpp"

using std::cout;
using std::cin;
using std::endl;

void pause();
void startMsg();
void displayMenu();

//change to test different variable types
typedef int testType;

int main(){
  Stack<testType> testStack;
  int choice = 0;
  testType input;

  startMsg();
  pause();

  //Display testing menu, continue until user quits
  while(choice != 5){
    displayMenu();
    cin >> choice;
    getchar();

    switch(choice){
      case 1: //push
        cout << endl << "Please enter a value to push on to the stack: ";
        cin >> input;
        getchar();
        testStack.push(input);
        break;
      case 2: //pop
        cout << endl << "Now popping off the top value of the stack: ";
        testStack.pop();
        cout << endl << "Pop complete";
        break;
      case 3: //top
        cout << endl << "The top value of the stack is: " << testStack.top();
        break;
      case 4: //isEmpty
        if(testStack.isEmpty()){
          cout << endl << "Stack is empty.";
        }
        else{
          cout << endl << "Stack is not empty.";
        }
        break;
      case 5: //quit
        break;
      default:
        cout << endl << "Please enter a vlid choice (1-5)";
        break;
    }
    pause();
  }

  cout << endl << "Thank you for testing Connor Rice's stack implementation"
       << endl << endl;

  return 0;
}

void pause(){
  cout << endl << "Press any key to continue... ";
  cin.get();
}

void startMsg(){
  cout << endl << endl
       << "Welcome to Connor Rice's basic Stack implementation."
       << endl << endl
       << "****************************************************"
       << endl;
}

void displayMenu(){
  cout << endl << endl
       << "****************************************************"
       << endl
       << "Testing menu for Stack implementation" << endl
       << "1. Push" << endl
       << "2. Pop" << endl
       << "3. Top" << endl
       << "4. isEmpty" << endl
       << "5. Quit testing" << endl
       << "*****************************************************"
       << endl
       << "Please ener your choice: ";
}

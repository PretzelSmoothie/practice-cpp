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
void displayMenu();

//change variable type based on testing interests
typedef int testType;

int main(){
  testType input;
  int choice = 0;
  LinkedList<testType> testList;

  //Display the welcome screen
  startMsg();
  pause();

  //Provide testing choices to user
  while(choice != 9) {
    displayMenu();
    cin >> choice;
    getchar();
    switch(choice){

      case 1: //insert method
        int position;
        cout << endl << "Please enter a value to insert: ";
        cin >> input;
        cout << "Please enter the position to insert " << input << ": ";
        cin >> position;
        testList.insert(position, input);
        break;

      case 2: //pushFront method
        cout << endl << "Please enter a value to insert: ";
        cin >> input;
        testList.pushFront(input);
        break;

      case 3: //pushBack method
        cout << endl << "Please enter a value to insert: ";
        cin >> input;
        testList.pushBack(input);
        break;

      case 4: //Remove method
        cout << endl << "Please enter a value to remove: ";
        cin >> input;
        testList.remove(input);
        break;

      case 5: //reverse method
        cout << endl << "Reversing list now...";
        testList.reverse();
        cout << endl << "List has been reversed";
        break;

      case 6: //getSize method
        cout << endl << "Current size of list: " << testList.getSize();
        break;

      case 7: //isEmpty method
        if(testList.isEmpty()){
          cout << endl << "List is empty";
        }
        else{
          cout << endl << "List is not empty";
        }
        break;

      case 8: //Display method
        cout << endl << "Displaying list now: " << endl;
        testList.display();
        break;

      case 9: //End program
        cout << "Thank you for testing the LinkedList, by Connor Rice"
             << endl << endl;
        break;

      default:
        cout << endl << "Please enter a valid choice (1-9)...";
        pause();
        break;
      }
      pause();
  }


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

//displays menu for user to select methods to test in LinkedList
void displayMenu(){
  cout << endl << endl
       << "********************************************" << endl
       << "TESTING MENU" << endl
       << "1. Insert" << endl
       << "2. pushFront" << endl
       << "3. pushBack" << endl
       << "4. Remove" << endl
       << "5. Reverse" << endl
       << "6. getSize" << endl
       << "7. isEmpty" << endl
       << "8. Display" << endl
       << "9. End Tests" << endl
       << "********************************************" << endl << endl
       << "Select the method you wish to test: ";

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

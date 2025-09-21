#include "student.h"
#include <iostream>
#include <string>
using namespace std;

int programming, tests, final;
bool condition = true;

int main() {
  cout << "Begin Setup for new semester!" << endl;

  do {
    cout << "Enter the number of programming assignments for this semester: ";
    cin >> programming;
    if (programming > 6) {
      cout << "You've exceeded the max limit of assignments.\n";
    }
  } while (programming > 6);

  do {
    cout << "Enter the number of tests for this semester: ";
    cin >> tests;
    if (tests > 4) {
      cout << "You've exceeded the max limit of tests.\n";
    }
  } while (tests > 4);

  do {
    cout << "Enter the number of final exams for this semester: ";
    cin >> final;
    if (final > 1) {
      cout << "You've exceeded the max limit of final exams.\n";
    } 
  } while (final > 1);

  
  return 0;
}
#include <iostream>
#include <fstream> // for dat file
#include <cctype> // for toupper, isalpha
#include "student.h"
using namespace std;

void menu();

// Global Variables

const int MAX_STUDENTS = 40;
Student roster[MAX_STUDENTS];
int rosterSize = 0;

int classSize = 0;
int num_Of_Programs, num_Of_Tests, num_Of_Finals = 0;
double programsW, testsW, finalsW = 0; //W for weight

const char* GRADES_DAT = "Grades.dat";
const char* GRADES_OUT = "Grades.out";

//Functions for Choices, which will call functions from Student.cpp
void setUpNewSemester(); // S - Call function in case/switch
void addStudent(); // A - Call function in case/switch
void recordProgramGrade(); // P - Call function in case/switch
void recordTestGrade(); // T - Call function in case/switch
void recordFinalGrade(); // F - Call function in case/switch
void changeGrade(); // C - Call function in case/switch
void calculateFinal(); // G - Call function in case/switch
void outputGrades(); // O - Call function in case/switch
//(Q) Quit - Call function to save dat file, then break loop in case/switch

// dat File functions

void openDat();
void saveDat();

int main() {
    
    menu();
    return 0;
}

void menu()
{
    //Print Menu
    cout << "================ GRADE BOOK ================" << endl;
    cout << "S). Set Up New Semester"
    << "A). Add A Student" << endl
    << "P). Record Programming Assignment Grade for All Students" << endl
    << "T). Record Test Grade for All Students" << endl
    << "F). Record Final Exam Grade for All Students" << endl
    << "C). Change a Grade for a Particular Student" << endl
    << "G). Calculate Final Grade" << endl
    << "O). Output Grade Data" << endl
    << "Q). Quit." << endl;
    
    while (true){ //While loop incase of input error
    
        string input;
        cin >> input;
        
        cout << "Enter choice: ";
        //TEST RUNS 1-3 LISTED BELOW
       
        // 1. If the string is longer than 1 character, it takes the first letter of the string.
        char choice = input[0];
        
        // 2. Repeat if it is not a letter
        if (!isalpha(choice))
        {
            cout << "ERROR! Letters only. Try again. " << endl << endl;
            continue;
        }
        
        // 3. Accepts lower case letters
        choice = toupper(choice); //Changes lower case to upper case
        
        //Function Call
        switch(choice)
        {
            case 'S': //Set Up New Semester
                setUpNewSemester();
                break;
            case 'A': // Add a Student
                addStudent();
                break;
            case 'P': // Record Program Grade
                recordProgramGrade();
                break;
            case 'T': // Record Test Grade
                recordTestGrade();
                break;
            case 'F': // Record Final Exam Grade
                recordFinalGrade();
                break;
            case 'C': // Change a Grade
                changeGrade();
                break;
            case 'G': // Calculate Final Grade
                calculateFinal();
                break;
            case 'O': // Print Grades
                outputGrades();
                break;
            case 'Q': // Quit
                saveDat();
                return;
            default: // Any letter outside of range
                cout << "ERROR! Enter T, F, C, G, O, or Q. Try again. " << endl << endl;
        }
    }
}

// Functions for Choices
void setUpNewSemester() // S - Call function in case/switch
{
    cout << "Begin Setup for new semester!" << endl;
    //Gather number of programming assignments
    do {
      cout << "Enter the number of programming assignments for this semester: ";
      cin >> num_Of_Programs;
      if (num_Of_Programs > 6) {
        cout << "You've exceeded the max limit of assignments.\n";
      }
    } while (num_Of_Programs > 6);

    // Gather number of tests
    do {
      cout << "Enter the number of tests for this semester: ";
      cin >> num_Of_Tests;
      if (num_Of_Tests > 4) {
        cout << "You've exceeded the max limit of tests.\n";
      }
    } while (num_Of_Tests > 4);

    // Gather number of final exams
    do {
      cout << "Enter the number of final exams for this semester: ";
      cin >> num_Of_Finals;
      if (num_Of_Finals > 1) {
        cout << "You've exceeded the max limit of final exams.\n";
      }
    } while (num_Of_Finals > 1);
    
    do {
        cout << "Enter program weight %: ";
        cin >> programsW;
        cout << "Enter tests weight %: ";
        cin >> testsW;
        cout << "Enter finals weight %: ";
        cin >> finalsW;
        
        if (programsW + testsW + finalsW != 100)
        {
            cout << "ERROR! Total grade weight must be equal to 100." << endl;
        }
        
    } while (programsW + testsW + finalsW != 100);
}
void addStudent() // A - Call function in case/switch
{
    //Gather student identifiers
    string last, first;
    int id;
    
    cout << "Enter first name: ";
    cin >> first;
    
    cout << "Enter last name: ";
    cin >> last;
    
    cout << "Enter ID number (any int): ";
    cin >> id;
    
    roster[rosterSize++] = Student(last, first, id); //Add data to student array
}
void recordProgramGrade() // P - Call function in case/switch
{
    int p; //Programming index - Select which programming assignment
    cout << "Enter programming assignment number: ";
    cin >> p;
    
    //Traverse the list, assign grade for each student
    for (int i = 0; i < rosterSize; i++)
    {
        double grade;
        cout << roster[i].getLastName() << ": ";
        cin >> grade;
        roster[i].setProgramGrade(p, grade);
    }
}
void recordTestGrade() // T - Call function in case/switch
{
    int t; //Tests index - Select which test
    cout << "Enter test number: ";
    cin >> t;
    
    //Traverse the list, assign grade for each student
    for (int i = 0; i < rosterSize; i++)
    {
        double grade;
        cout << roster[i].getLastName() << ": ";
        cin >> grade;
        roster[i].setTestGrade(t, grade);
    }
}
void recordFinalGrade() // F - Call function in case/switch
{
    //Only 1 final exam, no need for final index
    for (int i = 0; i < rosterSize; i++)
    {
        double grade;
        cout << roster[i].getLastName() << ": ";
        cin >> grade;
        roster[i].setFinalExamGrade(grade);
    }
}
void changeGrade() // C - Call function in case/switch
{
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    
    // Traverse through list of student ID's
    for (int i = 0; i < rosterSize; i++)
    {
        if (roster[i].getStudentNumber() == id)
        {
            char choice;
            cout << "Change Programming (P), Test (T), or Final (F) grades? ";
            cin >> choice;
            
            if (choice == 'P' || choice == 'p')
            {
                int index;
                double grade;
                
                //Update Grade by choosing an index, new grade, then calling setProgramGrade
                
                cout << "Enter program assignment number (index): ";
                cin >> index;
                
                cout << "Enter new grade: ";
                cin >> grade;
                
                roster[i].setProgramGrade(index, grade);
            }
            else if (choice == 'T' || choice == 't')
            {
                int index;
                double grade;
                
                //Update Grade by choosing an index, new grade, then calling setTestGrade
                cout << "Enter test number (index): ";
                cin >> index;
                
                cout << "Enter new grade: ";
                cin >> grade;
                
                roster[i].setTestGrade(index, grade);
            }
            else if (choice == 'F' || choice == 'f')
            {
                double grade;
                
                //Update Grade by new grade, then calling setFinalExamGrade
                
                cout << "Enter new final grade: ";
                cin >> grade;
                
                roster[i].setFinalExamGrade(grade);
            }
            return;
        }
    }
    
    //If not found, for loop is skipped.
    cout << "ERROR! Student not found. " << endl;
}
void calculateFinal() // G - Call function in case/switch
{
    for (int i = 0; i < rosterSize; i++) //Traverse through Student list
    {
        double avgProgramGrade = roster[i].calcProgramAverage(num_Of_Programs);
        double avgTestGrade = roster[i].calcTestAverage(num_Of_Tests);
        double finalGrade = roster[i].calcFinalGrade(programsW, testsW, finalsW, avgProgramGrade, avgTestGrade);
        cout << roster[i].getLastName() << ", " << roster[i].getFirstName()
        << " (Final Grade): " << finalGrade << endl;
    }
}
void outputGrades() // O - Call function in case/switch
{
    ofstream out(GRADES_OUT); //Print Grades.out
    
    //Traverse through student each student and display their data
    for (int i = 0; i < rosterSize; i++)
    {
        //W = weight
        roster[i].printInfo(out, num_Of_Programs, num_Of_Tests, num_Of_Finals,
                            programsW, testsW, finalsW);
    }
    
    cout << "(Grades.out Output)" << endl;
}
//(Q) Quit - Call function to save dat file, then break loop in case/switch

// dat File functions
void openDat()
{
    ifstream inputFile(GRADES_DAT);
    inputFile >> num_Of_Programs >> num_Of_Tests >> num_Of_Finals >> programsW >> testsW >> finalsW >> rosterSize;
    
    for (int i = 0; i < rosterSize; i++)
    {
        roster[i].readDat(inputFile, num_Of_Programs, num_Of_Tests, num_Of_Finals);
    }
}
void saveDat()
{
    ofstream outputFile(GRADES_DAT);
    outputFile << num_Of_Programs << num_Of_Tests << num_Of_Finals << programsW << testsW << finalsW << rosterSize;
    
    for (int i = 0; i < rosterSize; i++)
    {
        roster[i].writeDat(outputFile, num_Of_Programs, num_Of_Tests, num_Of_Finals);
    }
}

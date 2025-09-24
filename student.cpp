#include "Student.hpp"
#include <iostream>
using namespace std;

// Constructors
Student::Student():lastName(""), firstName(""), studentNumber(0), finalExam(0.0)
{
    //All assignments in program array iniitialized to 0.0 for each student
    for (int i = 0; i < MAX_PROGRAMS; i++)
    {
        programs[i] = 0.0; //Program Grades
    }
    for (int i = 0; i < MAX_TESTS; i++)
    {
        //All elements in tests array initialized to 0.0 for each student
        for (int i = 0; i < MAX_TESTS; i++)
        {
            tests[i] = 0.0;
        }
    }
}
Student::Student(const string& last, const string& first, int id):lastName(last), firstName(first), studentNumber(id), finalExam(0.0)
{
    //All assignments in program array iniitialized to 0.0 for each student
    for (int i = 0; i < MAX_PROGRAMS; i++)
    {
        programs[i] = 0.0; //Program Grades
    }
    for (int i = 0; i < MAX_TESTS; i++)
    {
        //All elements in tests array initialized to 0.0 for each student
        for (int i = 0; i < MAX_TESTS; i++)
        {
            tests[i] = 0.0;
        }
    }
}
// Student Data
void Student::setName(const string& last, const string& first){
    lastName = last;
    firstName = first;
}
void Student::setStudentNumber(int id)
{
    studentNumber = id;
}

const string& Student::getFirstName() const
{
    return firstName;
}

const string& Student::getLastName() const
{
    return lastName;
}

int Student::getStudentNumber() const
{
    return studentNumber;
}

/*
 ===============NEED HELP FINISHING THIS PART====================

// P). Program Grades
void setProgramGrade()
{
    
}
// T) Record Test Grade
void Student::setTestGrade(double g){
    
}

// F) Record Final Exam Grade
void Student::setFinalExamGrade(double grade){
    
}

// Calculations
double Student::calcFinalGrade(int testWeight, int finalWeight) const{
    
}

// O). Output Student/Grade Data
void Student::printInfo() const{
    
}

// Q). Quit (in main), no code required 

//File functions
void writeDat()
{
    
}

void readDat()
{
    
}

*/

#include "student.h"
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




// P). Program Grades


void Student::setProgramGrade(int i, double grade) {
    programs[i-1] = grade; // if programming assingment is i, index is i-1
}


// T) Record Test Grade
void Student::setTestGrade(int i, double grade) {
    tests[i-1] = grade; // if test is number i, index is i-1
}

// F) Record Final Exam Grade
void Student::setFinalExamGrade(double grade) {
    finalExam = grade;
}

// Calculations

double Student::calcProgramAverage(int num_Of_Programs) const {
    double sum; // holding sum of all grades
    for (int i = 0; i < num_Of_Programs; i++) {
        sum += programs[i];
    }
    return sum / num_Of_Programs; // returning avg grade of all prog
}

double Student::calcTestAverage(int num_Of_Tests) const {
    double sum; // holding sum of all grades
    for(int i = 0; i < num_Of_Tests; i++) { 
        sum += tests[i];
    }
    return sum / num_Of_Tests; // returning avg grade of all tests
}


double Student::calcFinalGrade(double programmingW, double testsW, double finalW, double avgTestGrade, double avgProgrammingGrade) const {
    // changing percentage to decimal
    programmingW = programmingW / 100;
    testsW = testsW / 100;
    finalW = finalW / 100;
    // calculating each final grade
    double finalTestGrade = testsW * avgTestGrade;
    double finalProgrammingGrade = programmingW * avgProgrammingGrade;
    double finalExamGrade = finalW * finalExam;
    // returning sum of grade for all categories
    return finalTestGrade + finalProgrammingGrade + finalExamGrade;

    
}

/*

 ===============NEED HELP FINISHING THIS PART====================
*/
// O). Output Student/Grade Data
void Student::printInfo(ofstream& out, int programs, int tests, int finals, int programmingW, int testsW, int finalW) const {
    
}

// Q). Quit (in main), no code required 

//File functions
void Student::writeDat(ofstream& out, int programs, int tests, int finals) const {
    
}

void Student::readDat(ifstream& in, int programs, int tests, int finals) const {
    
}



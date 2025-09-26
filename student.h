#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string>
using namespace std;

const int MAX_PROGRAMS = 6;
const int MAX_TESTS = 4;

class Student{
private:
    //Student Identifyers
    string firstName, lastName;
    int studentNumber;

    //Grades
    double programs[MAX_PROGRAMS];
    double tests[MAX_TESTS];
    double finalExam;
    
public:
    Student(); // Default constructor
    Student(const string& last, const string& first, int id); // Name


    // Student Data (Used by choice C and O)
    void setName(const string& last, const string& first);
    void setStudentNumber(int id);
    const string& getFirstName() const;
    const string& getLastName() const;
    int getStudentNumber() const;

    // P). Program Grades
    void setProgramGrade(int i, double grade); // i = index
    
    // T). Test Grades
    void setTestGrade(int i, double grade); // i = index

    // F). Final Exam Grades
    void setFinalExamGrade(double grade);

    // Calculations
    double calcProgramAverage(int num_Of_Programs) const; // Programming assignment average
    double calcTestAverage(int num_Of_Tests) const; // Exam average
    double calcFinalGrade(double programmingW, double testsW, double finalW, double avgTestGrade, double avgProgrammingGrade) const; //Weighted final grade, W = weight

    //O). Output Student/Grade Data
    void printInfo(ofstream& out, int programs, int tests, int finals, int programmingW, int testsW, int finalW) const;
    
    //Q. Quit (in main)
    
    // File functions
    void writeDat(ofstream& out, int programs, int tests, int finals) const;
    void readDat(ifstream& in, int programs, int tests, int finals) const;

};

#endif // STUDENT_H

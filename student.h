#include <iostream>
#include <string>
using namespace std;


class Student {
private: 
  int studentId;
  int p[6];
  int t[4];
  int f[1];
  string lastname;
  string firstname;

public:
  Student(int id, string ln, string fn) : lastname(ln), firstname(fn), studentId(id) {}


};
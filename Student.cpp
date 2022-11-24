#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "Student.hpp"
#include "Course.hpp"

using namespace std;

//Student constructor
Student::Student(string name, int id) {
    studentName = name;
    studentId = id;
}

//Sets a students name
void Student::setName(string name) {
    studentName = name;
}

//Sets a students id value
void Student::setId(int id) {
    studentId = id;
}

//Returns a students name
string Student::getName() {
    return studentName;
}

//Returns a students id value
int Student::getId() {
    return studentId;
}
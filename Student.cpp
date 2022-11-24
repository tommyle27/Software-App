#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "Student.hpp"

using namespace std;

Student::Student(string name, int id) {
    studentName = name;
    studentId = id;
}

void Student::setName(string name) {
    studentName = name;
}

void Student::setId(int id) {
    studentId = id;
}

string Student::getName() {
    return studentName;
}

int Student::getId() {
    return studentId;
}
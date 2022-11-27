#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Course.hpp"

using namespace std;

//Student constructor
Course::Course(string code, float t1, float t2, float t3, float t4) {
    courseCode = code;
    test1 = t1;
    test2 = t2;
    test3 = t3;
    exam = t4;
}

//Set test values
void Course::setTest(int testNum, float grade) {
    if(testNum == 1){
        test1 = grade;
    }
    else if (testNum == 2)
    {
        test2 = grade;
    }
    else if (testNum == 3)
    {
        test3 = grade;
    }
    else if(testNum == 4) {
        exam = grade;
    }
    else{
        cout << "Not a valid test number!";
    }

}

//Sets course code
void Course::setCourseCode(string code){
    courseCode = code;
}

//Returns course code
string Course::getCourseCode() {
    return courseCode;
}

//Calculates and returns final weight grade
float Course::overallGrade() {
    return (test1 * 0.2) + (test2 * 0.2) + (test3 * 0.2) + (exam * 0.4);
}

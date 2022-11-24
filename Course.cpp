#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Course.hpp"

using namespace std;

//Course Constructor
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
        std::cout << "Not a valid test number!";
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

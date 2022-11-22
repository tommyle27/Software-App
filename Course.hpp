#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
struct Course
{
    /* data */
    std::string courseCode;
    float test1, test2, test3, exam;
};

void setTest(int testNum, float grade);

std::string getCourseCode();

float overallGrade();
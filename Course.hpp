#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
struct Course
{
    /* data */
    string courseCode;
    float test1, test2, test3, exam;
}

void setTest(int testNum, float grade);

string getCourseCode();

float overallGrade();
#ifndef COURSE_HPP
#define COURSE_HPP

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

class Course
{
    //Declare course variables and methods
    private:
        std::string courseCode;
        float test1, test2, test3, exam;
    public:
        Course(std::string code = "", float t1 = 0, float t2 = 0, float t3 = 0, float t4 = 0);
        void setTest(int testNum, float grade);
        void setCourseCode(std::string code);
        std::string getCourseCode();
        float overallGrade();
};

#endif
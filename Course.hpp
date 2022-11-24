#ifndef COURSE_HPP
#define COURSE_HPP

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

class Course
{
    /* data */
    private:
        std::string courseCode;
        float test1, test2, test3, exam;
    public:
        void setTest(int testNum, float grade);
        void setCourseCode(std::string code);
        std::string getCourseCode();
        float overallGrade();
};

#endif
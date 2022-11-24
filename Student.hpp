#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

class Student
{
    //Declare student variables and methods
    private:
        std::string studentName;
        int studentId;
    public:
        Student(std::string name = "", int id = 0);
        void setName(std::string name);
        void setId(int id);
        std::string getName();
        int getId();
};

#endif




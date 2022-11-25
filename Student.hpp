#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "LinkedList.hpp"
#include "LinkedList.cpp"

class Student
{
    //Declare student variables and methods
    private:
        std::string studentName;
        int studentId;
    public:
        LinkedList courseData;
        Student(std::string name = "", int id = 0);
        void setName(std::string name);
        void setId(int id);
        std::string getName();
        int getId();
};

#endif




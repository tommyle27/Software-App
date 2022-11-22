#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "Course.hpp"

class Student {

private: 
    string studentName;
    int studentId;

public: 
    void setName(string name) {
        studentName = name;
    }

    void setId(int id) {
        studentId = id;
    }

    std::string getName() {
        return studentName;
    }

    int getId() {
        return studentId;
    }

}
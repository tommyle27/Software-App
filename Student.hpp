#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

struct Student
{
    /* data */
    std::string name;
    int id;
    void setName(std::string name);
    void setId(int id);
    std::string getName();
    int getId();
};




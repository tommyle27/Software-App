#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

class Course {

private:
    std::string courseCode;
    float finalGrade;
    float testGrade1;
    float testGrade2;
    float testGrade3;

public:

    void setTest(int testNum, float grade) {
        if(testNum == 1){
            testGrade1 = grade;
        }
        else if (testNum == 2)
        {
            testGrade2 = grade;
        }
        else if (testNum == 3)
        {
            testGrade3 = grade;
        }
        else{
            std::cout << "Not a valid test number!";
        }

    }

    void setCourseCode(std::string code){
        courseCode = code;
    }

    std::string getCourseCode() {
        return courseCode;
    }

    float overallGrade() {
        
    }
};
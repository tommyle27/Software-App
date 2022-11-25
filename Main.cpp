/* cp317
*/
#include <stdio.h>
#include "Student.hpp"
#include "Course.hpp"
#include "Student.cpp"
#include "Course.cpp"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	//Initialize variables
	string line;
	ifstream myfile ("NameFile.txt");
	Student *students = new Student[50];
	int count = 0;

	//Open file
	if(myfile.is_open()) {
		//Iterate through file line by line
		while(getline (myfile, line)) {
			//Initialize new variables for each iterations substring
			vector<string> result;
			stringstream s_stream(line);
			//Iterate through input stream and create substring delmitted by commas
			while(s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}
			//Assign substrings appropriately
			students[count].setId(stoi(result[0]));

			result[1] = result[1].substr(1, result[1].length());
			students[count].setName(result[1]);

			//Increment count to target next student
			count = count + 1;
		}
		//close file
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}

	ifstream myfile2 ("CourseFile.txt");
	if(myfile2.is_open()) {
		while(getline (myfile2, line)) {
			count = 0;
			vector<string> result;
			stringstream s_stream(line);
			while(s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}
			while(stoi(result[0]) != students[count].getId()) {
				count = count + 1;
			}
			students[count].courseData.insert(Course(result[1].substr(1, result[1].length()), stof(result[2].substr(1, result[2].length())), stof(result[3].substr(1, result[3].length())),
			stof(result[4].substr(1, result[4].length())), stof(result[5].substr(1, result[5].length()))));
		}
		myfile2.close();
	}
	else {
		cout << "Unable to open file";
	}

	count = 0;
	while(students[count].getId() != 0) {
		cout << students[count].getId() << "\n";
		cout << students[count].getName() << "\n";
		Course tempCourse = students[count].courseData.pop();
		while(tempCourse.getCourseCode() != "") {
			cout << tempCourse.getCourseCode() << "\n";
			cout << tempCourse.overallGrade() << "\n";
			tempCourse = students[count].courseData.pop();
		}
		count = count + 1;
	}
}
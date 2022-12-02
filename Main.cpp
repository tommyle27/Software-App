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
	string line, file1, file2;

	//Get user input for text files
	cout << "Enter the first filename: ";
	cin >> file1;
	cout << "Enter the second filename: ";
	cin >> file2;

	ifstream myfile (file1);
	Student *students = new Student[100];
	int count = 0;

	//Open first file to read student names and ids
	if(myfile.is_open()) {
		//Iterate through file line by line
		while(getline (myfile, line)) {
			//Initialize new variables for each iterations substring
			vector<string> result;
			stringstream s_stream(line);
			//Iterate through string stream and create substring delmitted by commas
			while(s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}
			//Resulting vector is [0] = studentid, [1] = student name
			//Assign substrings appropriately
			//Check that commas are valid
			if(result.size() == 2) {
				//Ensure that student Id is correct length
				if(result[0].length() <= 9) {
					students[count].setId(stoi(result[0]));
				}
				else {
					cout << "Invalid student Ids (File 2)";
					exit(4);
				}

				//Ensure that student name is correct length
				if(result[1].substr(1, result[1].length()).length() <= 20) {
					result[1] = result[1].substr(1, result[1].length());
					students[count].setName(result[1]);
				}
				else {
					cout << "Invalid student Names (File 1)";
					exit(4);
				}

				//Increment count to target next student
				count = count + 1;
			}
			else {
				cout << "Invalid input for file 1";
				exit(1);
			}
		}
		//close file
		myfile.close();
	}
	else {
		cout << "Unable to open file 1";
		exit(2);
	}

	//Open second file to match ids and assign course values
	ifstream myfile2 (file2);
	if(myfile2.is_open()) {
		//Iterate through file line by line
		while(getline (myfile2, line)) {
			//Initialize new variables for each iterations substring
			count = 0;
			vector<string> result;
			stringstream s_stream(line);
			//Iterate through string stream and create substring delmitted by commas
			while(s_stream.good()) {
				string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);
			}

			//Check if student ids are valid
			if(result[0].length() > 9) {
				cout << "Invalid student ids (file 2)";
				exit(4);
			}

			//Determine the count values of the correctly matched student ids
			while(stoi(result[0]) != students[count].getId() && students[count].getId() != 0) {
				count = count + 1;
			}
			//Resulting vector is [0] = studentid, [1] = student name, [2] = test1, [3] = test2, [4] = test3, [5] = final
			//Assign matched student with correct course data

			//Checks if commas are valid
			if(result.size() == 6) {
				//Check if course codes are valid
				if(result[1].substr(1, result[1].length()).length() > 6) {
					cout << "Invalid Course codes";
					exit(4);
				}
				students[count].courseData.insert(Course(result[1].substr(1, result[1].length()), stof(result[2].substr(1, result[2].length())), stof(result[3].substr(1, result[3].length())),
				stof(result[4].substr(1, result[4].length())), stof(result[5].substr(1, result[5].length()))));
			}
			else {
				cout << "Invalid input for file 2";
				exit(1);
			}
		}
		//close file
		myfile2.close();
	}
	else {
		cout << "Unable to open file 2";
		exit(2);
	}

	//Create and open output file
	ofstream outputFile ("Output.txt");
	if(outputFile.is_open()) {
		//Iterate through students array and write/format student data into output file "Output.txt"
		count = 0;
		while(students[count].getId() != 0) {
			Course tempCourse = students[count].courseData.pop();
			outputFile << students[count].getId() << ", ";
			outputFile << students[count].getName() << ", ";
			outputFile << tempCourse.getCourseCode() << ", ";
			outputFile << tempCourse.overallGrade() << "\n";
			while(students[count].courseData.getLength() != 0) {
				tempCourse = students[count].courseData.pop();
				outputFile << students[count].getId() << ", ";
				outputFile << students[count].getName() << ", ";
				outputFile << tempCourse.getCourseCode() << ", ";
				outputFile << tempCourse.overallGrade() << "\n";
			}
		//increment count
		count = count + 1;
		}
	}

	else {
		cout << "Unable to create/access output file!";
		exit(2);
	}

	cout << "Data successfully formatted!";
}
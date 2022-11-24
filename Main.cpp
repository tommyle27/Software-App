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
}
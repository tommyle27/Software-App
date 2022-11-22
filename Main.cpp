/* cp317
*/
#include <stdio.h>
#include "Student.hpp"
#include "Course.hpp"

int main() {
	Student test;

	test.setName("Mitchell Mackay");
	test.setId(200204510);

	std::cout << test.getName();
}

//Hello
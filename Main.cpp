/* cp317
*/
#include <GL/glut.h>
#include <stdio.h>
#include "Student.hpp"
#include "Course.hpp"

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Read Text Files");
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0); 
}

int main() {
	std::cout << "Hello World!";
	return 0;

	init();
}

//Hello
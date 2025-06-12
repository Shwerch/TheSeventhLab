#include "modules/koch_curve.hpp"

#include <GL/freeglut.h>

#include <GL/freeglut_std.h>
#include <cmath>

static int iterations = 0;

void drawSegment(double x1, double y1, double x2, double y2, int depth) {
	if (depth == 0) {
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		return;
	}

	double dx = (x2 - x1) / 3.0;
	double dy = (y2 - y1) / 3.0;

	double x3 = x1 + dx;
	double y3 = y1 + dy;
	double x5 = x2 - dx;
	double y5 = y2 - dy;

	double px = x3 + (dx * std::cos(M_PI / 3) - dy * std::sin(M_PI / 3));
	double py = y3 + (dx * std::sin(M_PI / 3) + dy * std::cos(M_PI / 3));

	drawSegment(x1, y1, x3, y3, depth - 1);
	drawSegment(x3, y3, px, py, depth - 1);
	drawSegment(px, py, x5, y5, depth - 1);
	drawSegment(x5, y5, x2, y2, depth - 1);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	drawSegment(-0.8, 0.0, 0.8, 0.0, iterations);
	glEnd();
	glFlush();
}

void drawKochCurve(int n) {
	iterations = (n < 0) ? 0 : n;
	int argc = 1;
	char *argv[1] = {(char *)"Koch"};
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Koch Curve");
	glutIgnoreKeyRepeat(1);
	gluOrtho2D(-1.0, 1.0, -0.5, 0.5);
	glutDisplayFunc(display);
	glutMainLoop();
}
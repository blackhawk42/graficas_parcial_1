#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

#include <stdio.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5000,5000,-5000,5000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(1.0);
}

Point p0 = Point(10*50, 10*50);
Point p1 = Point(5*50, 10*50);
Point p2 = Point(5*50, 5*50);
Point p3 = Point(10*50, 5*50);

Triangle t = Triangle(&p1, &p2, &p3);

void draw_function() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    t.draw();;

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Parcial 1");

    init();

    glutDisplayFunc(draw_function);
    glutIdleFunc(draw_function);
    glutMainLoop();

    return 0;
}

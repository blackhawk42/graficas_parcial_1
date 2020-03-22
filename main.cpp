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
#include "PointTransformer.h"

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <cmath>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5000,5000,-5000,5000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(1.0);
}

Point p0 = Point(10*70, 10*70);
Point p1 = Point(5*70, 10*70);
Point p2 = Point(5*70, 5*70);
Point p3 = Point(10*70, 5*70);

Circle t = Circle(&p0, 500, 200);

double degree2radians(double degree) {
    return degree*(M_PI/180);
}

double scale = 1.5;

void draw_function() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    t.draw();
    t.translation(-50, -50);
    //if(scale < 2) {
    //    scale = 2;
    //}
    //else {
     //   scale = 0.5;
    //}
    //t.scaling(scale);
    //t.rotation(degree2radians(45));

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

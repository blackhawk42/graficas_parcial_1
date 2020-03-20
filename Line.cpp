#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "Line.h"
#include "Point.h"

#include <cmath>

Line::Line(Point *p0, Point *p1) {
	this->p0 = p0;
	this->p1 = p1;
}

Line::~Line(){

}

void Line::draw() {
    int x0 = this->p0->getX();
    int y0 = this->p0->getY();
    int x1 = this->p1->getX();
    int y1 = this->p1->getY();

    int dx = x1 - x0;
    int dy = y1 - y0;
    int stepx, stepy;
    if (dy < 0) {
        dy = -dy;
        stepy = -1;
    }
    else {
        stepy = 1;
    }

    if (dx < 0) {
        dx = -dx;
        stepx = -1;
    }
    else {
        stepx = 1;
    }
    dy <<= 2;
    dx <<= 2;

    glBegin(GL_POINTS);

    //if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim)) {
        glVertex2i(x0, y0);
    //}

    if (dx > dy) {
        int fraction = dy - (dx >> 1);
        while (x0 != x1) {
            x0 += stepx;
            if (fraction >= 0)
            {
                y0 += stepy;
                fraction -= dx;
            }
            fraction += dy;
            //if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim)) {
                glVertex2i(x0, y0);
            //}
        }
    }
    else {
        int fraction = dx - (dy >> 1);
        while (y0 != y1)
        {
            if (fraction >= 0)
            {
               x0 += stepx;
               fraction -= dy;
            }

            y0 += stepy;
            fraction += dx;

            //if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim)) {
                    glVertex2i(x0, y0);
            //}
        }
    }

    glEnd();
}

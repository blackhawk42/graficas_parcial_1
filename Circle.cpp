#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "Circle.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "Point.h"
#include "Line.h"
#include "PointTransformer.h"

Circle::Circle(Point *origin, int radius, int resolution):
    pt(origin)
{
	this->origin = origin;
	this->radius = radius;
	this->resolution = resolution;

	this->points = new Point*[this->resolution];

	double angle_step = (2*M_PI)/this->resolution;
	double current_angle = 0;
	for(int i = 0; i < this->resolution; i++) {
		this->points[i] = new Point( round(radius*cos(current_angle)), round(radius*sin(current_angle)) );

		current_angle += angle_step;
	}

	this->lines = new Line*[this->resolution];

	for(int i = 0; i < this->resolution; i++) {
		this->lines[i] = new Line(this->points[i], this->points[(i + 1) % this->resolution]);
	}
}

Circle::~Circle() {
	for(int i = 0; i < this->resolution; i++) {
		delete this->lines[i];
	}
	delete[] this->lines;

	for(int i = 0; i < this->resolution; i++) {
		delete this->points[i];
	}
	delete[] this->points;
}

Point *Circle::getOrigin(){
	return this->origin;
}
int Circle::getRadius(){
	return this->radius;
}
int Circle::getResolution(){
	return this->resolution;
}
Point **Circle::getPoints() {
	return this->points;
}
Line **Circle::getLines(){
	return this->lines;
}

void Circle::draw() {
    for(int i = 0; i < this->resolution; i++) {
        this->lines[i]->draw();
    }
}

void Circle::translation(int dx, int dy) {
    this->pt.translation(dx, dy);

    for(int i = 0; i < this->resolution; i++) {
        this->pt.apply(this->points[i]);
    }
}

void Circle::scaling(double factor) {
    this->pt.scaling(factor, factor);

    for(int i = 0; i < this->resolution; i++) {
        this->pt.apply(this->points[i]);
    }
}

void Circle::rotation(double angle) {
    this->pt.rotation(angle);

    for(int i = 0; i < this->resolution; i++) {
        this->pt.apply(this->points[i]);
    }
}

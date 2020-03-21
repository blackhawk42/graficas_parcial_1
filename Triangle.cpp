#include "Triangle.h"

#include "Point.h"
#include "Line.h"

Triangle::Triangle(Point *p0, Point *p1, Point *p2) {
	this->p0 = p0;
	this->p1 = p1;
	this->p2 = p2;

	this->l0 = new Line(this->p0, this->p1);
	this->l1 = new Line(this->p1, this->p2);
	this->l2 = new Line(this->p2, this->p0);
}

Triangle::~Triangle() {
	delete this->l0;
	delete this->l1;
	delete this->l2;
}

Point *Triangle::getPoint0() {
	return this->p0;
}
Point *Triangle::getPoint1() {
	return this->p1;
}
Point *Triangle::getPoint2() {
	return this->p2;
}

void Triangle::draw() {
    this->l0->draw();
    this->l1->draw();
    this->l2->draw();
}

#include "Square.h"

#include "Point.h"
#include "Line.h"

Square::Square(Point *p0, Point *p1, Point *p2, Point *p3) {
	this->p0 = p0;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;

	this->l0 = new Line(this->p0, this->p1);
	this->l0 = new Line(this->p1, this->p2);
	this->l0 = new Line(this->p2, this->p3);
	this->l0 = new Line(this->p3, this->p0);
}

Square::~Square() {
	delete this->l0;
	delete this->l1;
	delete this->l2;
	delete this->l3;
}

Point *Square::getPoint0() {
	return this->p0;
}
Point *Square::getPoint1() {
	return this->p1;
}
Point *Square::getPoint2() {
	return this->p2;
}
Point *Square::getPoint3() {
	return this->p3;
}
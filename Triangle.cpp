#include "Triangle.h"

#include "Point.h"
#include "Line.h"

Triangle::Triangle(Point *p0, Point *p1, Point *p2):
    p0(p0->getX(), p0->getY()),
	p1(p1->getX(), p1->getY()),
	p2(p2->getX(), p2->getY()),

	l0(&this->p0, &this->p1),
	l1(&this->p1, &this->p2),
	l2(&this->p2, &this->p0)
{
}

Triangle::~Triangle() {

}

Point *Triangle::getPoint0() {
	return &this->p0;
}
Point *Triangle::getPoint1() {
	return &this->p1;
}
Point *Triangle::getPoint2() {
	return &this->p2;
}

void Triangle::draw() {
    this->l0.draw();
    this->l1.draw();
    this->l2.draw();
}

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "Square.h"

#include "Point.h"
#include "Line.h"


Square::Square(Point *p0, int length) {
    this->length = length;


    this->p0 = new Point(p0->getX(), p0->getY());
	this->p1 = new Point(p0->getX() + length, p0->getY());
	this->p2 = new Point(this->p1->getX(), this->p1->getY() + length);
	this->p3 = new Point(this->p2->getX() - length, this->p2->getY());

	this->l0 = new Line(this->p0, this->p1);
	this->l1 = new Line(this->p1, this->p2);
	this->l2 = new Line(this->p2, this->p3);
	this->l3 = new Line(this->p3, this->p0);

}

Square::~Square() {
    delete this->p0;
    delete this->p1;
    delete this->p2;
    delete this->p3;

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

int Square::getLength() {
    return this->length;
}

void Square::setLength(int length) {
    this->length = length;

	this->p1->setX(p0->getX() + length);
	this->p1->setY(p0->getY());
	this->p2->setX(this->p1->getX());
	this->p2->setY(this->p1->getY() + length);
	this->p3->setX(this->p2->getX() - length);
	this->p3->setY(this->p2->getY());
}

void Square::draw() {
    this->l0->draw();
    this->l1->draw();
    this->l2->draw();
    this->l3->draw();
}

#include "Square.h"

#include "Point.h"
#include "Line.h"
#include "PointTransformer.h"


Square::Square(Point *p0, int length):
    p0(p0->getX(), p0->getY()),
	p1(p0->getX() + length, p0->getY()),
	p2(this->p1.getX(), this->p1.getY() + length),
	p3(this->p2.getX() - length, this->p2.getY()),

	pt(&this->p0),

	l0(&this->p0, &this->p1),
	l1(&this->p1, &this->p2),
	l2(&this->p2, &this->p3),
	l3(&this->p3, &this->p0)
{

    this->length = length;
}

Square::~Square() {
}

Point *Square::getPoint0() {
	return &this->p0;
}
Point *Square::getPoint1() {
	return &this->p1;
}
Point *Square::getPoint2() {
	return &this->p2;
}
Point *Square::getPoint3() {
	return &this->p3;
}

int Square::getLength() {
    return this->length;
}

void Square::setLength(int length) {
    this->length = length;

	this->p1.setX(this->p0.getX() + length);
	this->p1.setY(this->p0.getY());
	this->p2.setX(this->p1.getX());
	this->p2.setY(this->p1.getY() + length);
	this->p3.setX(this->p2.getX() - length);
	this->p3.setY(this->p2.getY());
}

void Square::draw() {
    this->l0.draw();
    this->l1.draw();
    this->l2.draw();
    this->l3.draw();
}

void Square::translation(int dx, int dy) {
    this->pt.translation(dx, dy);

    this->pt.apply(&this->p0);
    this->pt.apply(&this->p1);
    this->pt.apply(&this->p2);
    this->pt.apply(&this->p3);
}

void Square::scaling(double factor) {
    this->pt.scaling(factor, factor);

    this->pt.apply(&this->p0);
    this->pt.apply(&this->p1);
    this->pt.apply(&this->p2);
    this->pt.apply(&this->p3);
}

void Square::rotation(double angle) {
    this->pt.rotation(angle);

    this->pt.apply(&this->p0);
    this->pt.apply(&this->p1);
    this->pt.apply(&this->p2);
    this->pt.apply(&this->p3);
}

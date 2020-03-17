#include "Point.h"

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::~Point() {

}

int Point::getX() {
	return this->x;
}

void Point::setX(int val) {
	this->x = val;
}

int Point::getY() {
	return this->y;
}

void Point::setY(int val) {
	this->y = val;
}
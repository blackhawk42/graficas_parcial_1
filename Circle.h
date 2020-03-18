#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Line.h"

class Circle
{
	private:
		int resolution;
		int radius;
		Point *origin;

		Point **points;
		Line **lines;

	public:
		Circle(Point *origin, int radius, int resolution);
		~Circle();

		Point *getOrigin();
		int getRadius();
		int getResolution();
		Point **getPoints();
		Line **getLines();
};

#endif // CIRCLE_H

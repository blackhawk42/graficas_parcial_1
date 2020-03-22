#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Line.h"
#include "PointTransformer.h"

class Circle
{
	private:
		int resolution;
		int radius;
		Point *origin;

		PointTransformer pt;

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

		void draw();

		void translation(int dx, int dy);
		void scaling(double factor);
		void rotation(double angle);
};

#endif // CIRCLE_H

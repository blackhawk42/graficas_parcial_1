#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Line.h"
#include "PointTransformer.h"

class Triangle {
	private:
	    PointTransformer pt;

		Point p0, p1, p2;

		Line l0, l1, l2;

	public:
		Triangle(Point *p0, Point *p1, Point *p2);
		~Triangle();

		Point *getPoint0();
		Point *getPoint1();
		Point *getPoint2();

		void draw();

		void translation(int dx, int dy);
		void scaling(double factor);
		void rotation(double angle);
};

#endif // TRIANGLE_H

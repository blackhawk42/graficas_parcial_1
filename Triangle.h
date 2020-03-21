#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Line.h"

class Triangle {
	private:
		Point p0, p1, p2;

		Line l0, l1, l2;

	public:
		Triangle(Point *p0, Point *p1, Point *p2);
		~Triangle();

		Point *getPoint0();
		Point *getPoint1();
		Point *getPoint2();

		void draw();
};

#endif // TRIANGLE_H

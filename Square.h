#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "Line.h"
#include "PointTransformer.h"

class Square {
	private:
	    int length;
	    PointTransformer pt;

		Point p0, p1, p2, p3;
		Line l0, l1, l2, l3;

	public:
		Square(Point *p0, int length);
		~Square();

		Point *getPoint0();
		Point *getPoint1();
		Point *getPoint2();
		Point *getPoint3();

		int getLength();
		void setLength(int length);

		void draw();

		void translation(int dx, int dy);
		void scaling(double factor);
		void rotation(double angle);
};


#endif // SQUARE_H

#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "Line.h"

class Square {
	private:
	    int length;

		Point *p0, *p1, *p2, *p3;
		Line *l0, *l1, *l2, *l3;

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
};


#endif // SQUARE_H

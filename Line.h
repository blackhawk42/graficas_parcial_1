#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line{
	private:
		Point *p0, *p1;

	public:
		Line(Point *p0, Point *p1);
		~Line();

		void draw();
};

#endif // LINE_H

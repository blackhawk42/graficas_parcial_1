#ifndef POINT_H
#define POINT_H

#include "Matrix.h"

class Point{
	private:
		int x, y;

	public:
		Point(int x, int y);
		~Point();

		int getX();
		void setX(int val);

		int getY();
		void setY(int val);

		void draw();
};

#endif // POINT_H

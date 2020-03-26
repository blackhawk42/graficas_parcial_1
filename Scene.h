#ifndef SCENE_H
#define SCENE_H

#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Point.h"

class Scene {
    private:

        Point p0, p1, p2, p3;

        Square houseSquares0;
        Square houseSquares1;
        Square houseSquares2;
        Square houseSquares3;
        Square houseSquares4;
        Square houseSquares5;
        Square houseSquares6;
        Triangle houseTriangles0;
        Triangle houseTriangles1;
        Circle houseCircles0;
        Circle houseCircles1;

        Square carSquares0;
        Square carSquares1;
        Square carSquares2;
        Square carSquares3;
        Square carSquares4;
        Triangle carTriangles0;
        Circle carCircles0;
        Circle carCircles1;

        Square treeSquares0;
        Square treeSquares1;
        Triangle treeTriangles0;

        Triangle leaveTriangles0;

        int carTimes;
        int carDelta;
        int carLimit;

        int treeTimes;
        double treeDelta;
        int treeTransDelta;
        int treeLimit;
        Point treeTriangles0p0;
        Point treeTriangles0p1;
        Point treeTriangles0p2;

        int leafTimes;
        double leafAngleDelta;
        int leafXDelta;
        int leafYDelta;
        int leafLimit;
        Point leaveTriangles0p0;
        Point leaveTriangles0p1;
        Point leaveTriangles0p2;

    public:
        Scene();
        ~Scene();

        void update();
};

#endif // SCENE_H

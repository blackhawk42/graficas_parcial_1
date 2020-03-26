#include "Scene.h"

#include "Point.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

#define _USE_MATH_DEFINES
#include <cmath>


double degree2radians(double degree) {
    return degree*(M_PI/180);
}

Scene::Scene():
    p0(0, 0),
    p1(0, 0),
    p2(0, 0),
    p3(0, 0),

    houseSquares0(&p0, 2500),
    houseSquares1(&p0, 500),
    houseSquares2(&p0, 500),
    houseSquares3(&p0, 200),
    houseSquares4(&p0, 200),
    houseSquares5(&p0, 200),
    houseSquares6(&p0, 200),
    houseTriangles0(&p0, &p1, &p2),
    houseTriangles1(&p0, &p1, &p2),
    houseCircles0(&p0, 100, 100),
    houseCircles1(&p0, 50, 100),

    carSquares0(&p0, 500),
    carSquares1(&p0, 500),
    carSquares2(&p0, 500),
    carSquares3(&p0, 500),
    carSquares4(&p0, 500),
    carTriangles0(&p0, &p1, &p2),
    carCircles0(&p0, 300, 100),
    carCircles1(&p0, 300, 100),

    treeSquares0(&p0, 500),
    treeSquares1(&p0, 500),
    treeTriangles0(&p0, &p1, &p2),
    treeTriangles0p0(0, 0),
    treeTriangles0p1(0, 0),
    treeTriangles0p2(0, 0),

    leaveTriangles0(&p0, &p1, &p2),
    leaveTriangles0p0(0, 0),
    leaveTriangles0p1(0, 0),
    leaveTriangles0p2(0, 0)
{
    // control variables
    this->carTimes = 0;
    this->carDelta = 20;
    this->carLimit = 100;

    this->treeTimes = 0;
    this->treeDelta = 1.2;
    this->treeTransDelta = 70;
    this->treeLimit = 4;

    this->leafTimes = 0;
    this->leafAngleDelta = degree2radians(45);
    this->leafXDelta = -500;
    this->leafYDelta = 500;
    this->leafLimit = this->treeLimit;

    // House
    // main structure
    houseSquares0.translation(-4500, -2000);
    // door
    houseSquares1.translation(-3500, -2000);
    houseSquares2.translation(-3500, -1500);
    // windows
    houseSquares3.translation(-2700, -500);
    houseSquares4.translation(-2500, -500);
    houseSquares5.translation(-2500, -300);
    houseSquares6.translation(-2700, -300);
    // round window
    houseCircles0.translation(-3200, 1100);
    // knob
    houseCircles1.translation(-3050, -1450);
    // roof
    houseTriangles0.getPoint0()->setX(houseTriangles0.getPoint0()->getX() - 4500);
    houseTriangles0.getPoint0()->setY(houseTriangles0.getPoint0()->getY() + 500);
    houseTriangles0.getPoint1()->setX(houseTriangles0.getPoint1()->getX() - 2000);
    houseTriangles0.getPoint1()->setY(houseTriangles0.getPoint1()->getY() + 500);
    houseTriangles0.getPoint2()->setX(houseTriangles0.getPoint2()->getX() - 3200);
    houseTriangles0.getPoint2()->setY(houseTriangles0.getPoint2()->getY() + 1500);
    // triangle in circle window
    houseTriangles1.getPoint0()->setX(houseTriangles1.getPoint0()->getX() - 3300);
    houseTriangles1.getPoint0()->setY(houseTriangles1.getPoint0()->getY() + 1050);
    houseTriangles1.getPoint1()->setX(houseTriangles1.getPoint1()->getX() - 3100);
    houseTriangles1.getPoint1()->setY(houseTriangles1.getPoint1()->getY() + 1050);
    houseTriangles1.getPoint2()->setX(houseTriangles1.getPoint2()->getX() - 3190);
    houseTriangles1.getPoint2()->setY(houseTriangles1.getPoint2()->getY() + 1200);


    // Car
    carSquares0.translation(-1500, -1500);
    carSquares1.translation(-1000, -1500);
    carSquares2.translation(-500, -1500);
    carSquares3.translation(0, -1500);
    carSquares4.translation(-500, -1000);

    carCircles0.translation(-1000, -1600);
    carCircles1.translation(0, -1600);

    carTriangles0.getPoint0()->setX(carTriangles0.getPoint0()->getX() + 400);
    carTriangles0.getPoint0()->setY(carTriangles0.getPoint0()->getY() - 1200);
    carTriangles0.getPoint1()->setX(carTriangles0.getPoint1()->getX() + 600);
    carTriangles0.getPoint1()->setY(carTriangles0.getPoint1()->getY() - 1200);
    carTriangles0.getPoint2()->setX(carTriangles0.getPoint2()->getX() + 500);
    carTriangles0.getPoint2()->setY(carTriangles0.getPoint2()->getY() - 850);

    // Tree
    treeSquares0.translation(3500, -2000);
    treeSquares1.translation(3500, -1500);


    treeTriangles0.getPoint0()->setX(treeTriangles0.getPoint0()->getX() + 4200);
    treeTriangles0.getPoint0()->setY(treeTriangles0.getPoint0()->getY() - 1200);

    treeTriangles0.getPoint1()->setX(treeTriangles0.getPoint1()->getX() + 3300);
    treeTriangles0.getPoint1()->setY(treeTriangles0.getPoint1()->getY() - 1200);

    treeTriangles0.getPoint2()->setX(treeTriangles0.getPoint2()->getX() + 3740);
    treeTriangles0.getPoint2()->setY(treeTriangles0.getPoint2()->getY() - 200);

    treeTriangles0p0.setX(treeTriangles0.getPoint0()->getX());
    treeTriangles0p0.setY(treeTriangles0.getPoint0()->getY());
    treeTriangles0p1.setX(treeTriangles0.getPoint1()->getX());
    treeTriangles0p1.setY(treeTriangles0.getPoint1()->getY());
    treeTriangles0p2.setX(treeTriangles0.getPoint2()->getX());
    treeTriangles0p2.setY(treeTriangles0.getPoint2()->getY());

    // Flying leaf
    leaveTriangles0.getPoint0()->setX(leaveTriangles0.getPoint0()->getX() + 3000);
    leaveTriangles0.getPoint0()->setY(leaveTriangles0.getPoint0()->getY() - 500);
    leaveTriangles0.getPoint1()->setX(leaveTriangles0.getPoint1()->getX() + 3300);
    leaveTriangles0.getPoint1()->setY(leaveTriangles0.getPoint1()->getY() - 500);
    leaveTriangles0.getPoint2()->setX(leaveTriangles0.getPoint2()->getX() + 3120);
    leaveTriangles0.getPoint2()->setY(leaveTriangles0.getPoint2()->getY() - 100);

    leaveTriangles0p0.setX(leaveTriangles0.getPoint0()->getX());
    leaveTriangles0p0.setY(leaveTriangles0.getPoint0()->getY());
    leaveTriangles0p1.setX(leaveTriangles0.getPoint1()->getX());
    leaveTriangles0p1.setY(leaveTriangles0.getPoint1()->getY());
    leaveTriangles0p2.setX(leaveTriangles0.getPoint2()->getX());
    leaveTriangles0p2.setY(leaveTriangles0.getPoint2()->getY());

}

Scene::~Scene() {
}

void Scene::update() {
    houseSquares0.draw();
    houseSquares1.draw();
    houseSquares2.draw();
    houseSquares3.draw();
    houseSquares4.draw();
    houseSquares5.draw();
    houseSquares6.draw();
    houseTriangles0.draw();
    houseTriangles1.draw();
    houseCircles0.draw();
    houseCircles1.draw();

    carSquares0.draw();
    carSquares1.draw();
    carSquares2.draw();
    carSquares3.draw();
    carSquares4.draw();
    carTriangles0.draw();
    carCircles0.draw();
    carCircles1.draw();

    treeSquares0.draw();
    treeSquares1.draw();
    treeTriangles0.draw();

    leaveTriangles0.draw();


    // Move car
    carSquares0.translation(this->carDelta, 0);
    carSquares1.translation(this->carDelta, 0);
    carSquares2.translation(this->carDelta, 0);
    carSquares3.translation(this->carDelta, 0);
    carSquares4.translation(this->carDelta, 0);
    carTriangles0.translation(this->carDelta, 0);
    carCircles0.translation(this->carDelta, 0);
    carCircles1.translation(this->carDelta, 0);
    this->carTimes++;
    if(this->carTimes > this->carLimit) {
        this->carDelta = -this->carDelta;
        this->carTimes = 0;
    }

    // Grow tree
    treeTriangles0.scaling(treeDelta);
    treeTriangles0.translation(this->treeTransDelta, 0);
    this->treeTimes++;
    if(this->treeTimes > this->treeLimit) {
        treeTriangles0.getPoint0()->setX(treeTriangles0p0.getX());
        treeTriangles0.getPoint0()->setY(treeTriangles0p0.getY());
        treeTriangles0.getPoint1()->setX(treeTriangles0p1.getX());
        treeTriangles0.getPoint1()->setY(treeTriangles0p1.getY());
        treeTriangles0.getPoint2()->setX(treeTriangles0p2.getX());
        treeTriangles0.getPoint2()->setY(treeTriangles0p2.getY());

        this->treeTimes = 0;
    }

    // Move leaf
    leaveTriangles0.rotation(this->leafAngleDelta);
    leaveTriangles0.translation(this->leafXDelta, leafYDelta);
    this->leafTimes++;
    if(this->leafTimes > this->treeLimit) {
        leaveTriangles0.getPoint0()->setX(leaveTriangles0p0.getX());
        leaveTriangles0.getPoint0()->setY(leaveTriangles0p0.getY());
        leaveTriangles0.getPoint1()->setX(leaveTriangles0p1.getX());
        leaveTriangles0.getPoint1()->setY(leaveTriangles0p1.getY());
        leaveTriangles0.getPoint2()->setX(leaveTriangles0p2.getX());
        leaveTriangles0.getPoint2()->setY(leaveTriangles0p2.getY());

        this->leafTimes = 0;
    }
}

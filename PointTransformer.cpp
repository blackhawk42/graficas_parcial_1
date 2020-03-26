#include "PointTransformer.h"

#include "Matrix.h"
#include "Point.h"

#include <cmath>

#include <stdio.h>

void print_matrix(Matrix *m) {
    for(int i = 0; i < m->getRows(); i++) {
        for(int j = 0; j < m->getCols(); j++) {
            printf("%f ", m->getValue(i, j));
        }
        printf("\n");
    }
    printf("\n");
}

Matrix PointTransformer::standardIdentity = Matrix(3, 3);
Matrix PointTransformer::translationIdentity = Matrix(3, 3);
Matrix PointTransformer::scalingIdentity = Matrix(3, 3);
Matrix PointTransformer::rotationIdentity = Matrix(3, 3);

PointTransformer::PointTransformer(Point *pivot)
{
    this->pivot = pivot;
    this->current = 0;

    this->standardIdentity.setValue(0, 0, 1);
    this->standardIdentity.setValue(0, 1, 0);
    this->standardIdentity.setValue(0, 2, 0);
    this->standardIdentity.setValue(1, 0, 0);
    this->standardIdentity.setValue(1, 1, 1);
    this->standardIdentity.setValue(1, 2, 0);
    this->standardIdentity.setValue(2, 0, 0);
    this->standardIdentity.setValue(2, 1, 0);
    this->standardIdentity.setValue(2, 2, 1);

    this->translationIdentity.setValue(0, 2, 0);
    this->translationIdentity.setValue(0, 0, 1);
    this->translationIdentity.setValue(0, 1, 0);
    this->translationIdentity.setValue(1, 2, 0);
    this->translationIdentity.setValue(1, 0, 0);
    this->translationIdentity.setValue(1, 1, 1);
    this->translationIdentity.setValue(2, 0, 0);
    this->translationIdentity.setValue(2, 1, 0);
    this->translationIdentity.setValue(2, 2, 1);

    this->scalingIdentity.setValue(0, 0, 0);
    this->scalingIdentity.setValue(0, 1, 0);
    this->scalingIdentity.setValue(0, 2, 0);
    this->scalingIdentity.setValue(1, 0, 0);
    this->scalingIdentity.setValue(1, 1, 0);
    this->scalingIdentity.setValue(1, 2, 0);
    this->scalingIdentity.setValue(2, 0, 0);
    this->scalingIdentity.setValue(2, 1, 0);
    this->scalingIdentity.setValue(2, 2, 1);

    this->rotationIdentity.setValue(0, 0, 0);
    this->rotationIdentity.setValue(0, 1, 0);
    this->rotationIdentity.setValue(0, 2, 0);
    this->rotationIdentity.setValue(1, 0, 0);
    this->rotationIdentity.setValue(1, 1, 0);
    this->rotationIdentity.setValue(1, 2, 0);
    this->rotationIdentity.setValue(2, 0, 0);
    this->rotationIdentity.setValue(2, 1, 0);
    this->rotationIdentity.setValue(2, 2, 1);
}

PointTransformer::~PointTransformer() {
    delete this->current;
}

void PointTransformer::translation(int dx, int dy) {
    this->translationIdentity.setValue(0, 2, dx);
    this->translationIdentity.setValue(1, 2, dy);

    delete this->current;
    this->current = (&translationIdentity)->multiply(&this->standardIdentity);
}

void PointTransformer::scaling(double sx, double sy) {
    this->translationIdentity.setValue(0, 2, this->pivot->getX());
    this->translationIdentity.setValue(1, 2, this->pivot->getY());

    this->scalingIdentity.setValue(0, 0, sx);
    this->scalingIdentity.setValue(1, 1, sy);

    delete this->current;
    this->current = (&this->translationIdentity)->multiply(&this->scalingIdentity);

    Matrix *temp = this->current;

    this->translationIdentity.setValue(0, 2, -this->pivot->getX());
    this->translationIdentity.setValue(1, 2, -this->pivot->getY());
    this->current = this->current->multiply(&this->translationIdentity);
    delete temp;
}

void PointTransformer::rotation(double angle) {
    this->translationIdentity.setValue(0, 2, this->pivot->getX());
    this->translationIdentity.setValue(1, 2, this->pivot->getY());

    this->rotationIdentity.setValue(0, 0, cos(angle));
    this->rotationIdentity.setValue(0, 1, -sin(angle));
    this->rotationIdentity.setValue(1, 0, sin(angle));
    this->rotationIdentity.setValue(1, 2, cos(angle));

    delete this->current;
    this->current = (&this->translationIdentity)->multiply(&this->rotationIdentity);


    Matrix *temp = this->current;

    this->translationIdentity.setValue(0, 2, -this->pivot->getX());
    this->translationIdentity.setValue(1, 2, -this->pivot->getY());
    this->current = this->current->multiply(&this->translationIdentity);
    delete temp;
}

void PointTransformer::apply(Point *p) {
    Matrix point = Matrix(3, 1);
    point.setValue(0, 0, p->getX());
    point.setValue(1, 0, p->getY());
    point.setValue(2, 0, 1);

    Matrix *result = this->current->multiply(&point);

    p->setX( round(result->getValue(0, 0)) );
    p->setY( round(result->getValue(1, 0)) );

    delete result;
}

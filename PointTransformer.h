#ifndef POINTTRANSFORMER_H
#define POINTTRANSFORMER_H

#include "Matrix.h"
#include "Point.h"

class PointTransformer {
    private:
        static Matrix standardIdentity;
        static Matrix translationIdentity, scalingIdentity, rotationIdentity;

        Point *pivot;

        Matrix *current;

    public:
        PointTransformer(Point *pivot);
        ~PointTransformer();

        Point *getPivot();
        void setPivot(Point *p);

        void translation(int dx, int dy);
        void scaling(double sx, double sy);
        void rotation(double angle);

        void apply(Point *p);
};

#endif // POINTTRANSFORMER_H

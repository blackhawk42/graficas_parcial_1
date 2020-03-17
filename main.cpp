#include "Matrix.h"
#include <stdio.h>

void print_matrix(Matrix *m) {
    for(int i = 0; i < m->getRows(); i++) {
        for(int j = 0; j < m->getCols(); j++) {
            printf("%d ", m->getValue(i, j));
        }

        printf("\n");
    }
}

int main(int argc, char **argv) {
    Matrix a(3, 3);
    Matrix b(3, 4);

    a.setValue(0, 0, 1);
    a.setValue(0, 1, 0);
    a.setValue(0, 2, 2);
    a.setValue(1, 0, 0);
    a.setValue(1, 1, 1);
    a.setValue(1, 2, 3);
    a.setValue(2, 0, 0);
    a.setValue(2, 1, 0);
    a.setValue(2, 2, 1);

    print_matrix(&a);
    printf("\n");

    b.setValue(0, 0, 5);
    b.setValue(0, 1, 6);
    b.setValue(0, 2, 7);
    b.setValue(0, 3, 9);
    b.setValue(1, 0, 4);
    b.setValue(1, 1, 2);
    b.setValue(1, 2, 8);
    b.setValue(1, 3, 3);
    b.setValue(2, 0, 1);
    b.setValue(2, 1, 1);
    b.setValue(2, 2, 1);
    b.setValue(2, 3, 1);

    print_matrix(&b);
    printf("\n");

    Matrix *c = a.multiply(&b);
    print_matrix(c);

    return 0;
}
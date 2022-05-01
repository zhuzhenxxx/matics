#include <stdio.h>
#include "cmathematics.h"
#include "vec.h"
#include "matrix.h"

int main()
{
    mat m = newMatrixMat(4, 4,
         2.0f, -1.0f, 3.0f, 5.0f,
         1.0f, 3.0f, 0.0f, 4.0f,
         3.0f, 0.0f, -1.0f, -2.0f,
         0.0f, 0.0f, 0.0f, 1.0f);
    printMat(m);

    vec v = vector(2.0f, 0.0f, -1.0f, 1.0f);

    vec res = matVecMutiplication(m, v);
    printVec(res);

    mat m1 = newMatrixMat(2, 3,
                          2.0f, 1.0f, 4.0f,
                          0.0f, 1.0f, 1.0f);

    mat m2 = newMatrixMat(3, 4,
                          6.0f, 3.0f, -1.0f, 0.0f,
                          1.0f, 1.0f, 0.0f, 4.0f,
                          -2.0f, 5.0f, 0.0f, 2.0f);
    printMat(m2);
    matMatMutiplication(m1, m2);


    return 0;
}
#include <stdio.h>
#include "cmathematics.h"
#include "vec.h"
#include "matrix.h"

int main()
{
    mat m = newMatrixMat(3, 3,
                         7.0f, 2.0f, 0.0f,
                         3.0f, -15.0f, 0.0f,
                         6.0f, -4.0f, 2.0f);
    printMat(m);

    printf("%f\n", determinant(m));

    return 0;
}
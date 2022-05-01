#include <stdio.h>
#include "cmathematics.h"
#include "vec.h"
#include "matrix.h"

int main()
{
    mat m2 = newMatrixMat(3, 4,
                          6.0f, 3.0f, -1.0f, 0.0f,
                          1.0f, 1.0f, 0.0f, 4.0f,
                          -2.0f, 5.0f, 0.0f, 2.0f);
    printMat(m2);
    printMat(transpose(&m2));

    return 0;
}
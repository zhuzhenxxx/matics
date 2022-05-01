#include <stdio.h>
#include "cmathematics.h"
#include "vec.h"
#include "matrix.h"

int main()
{
    vec v = vector(1.02f, 3.1415f, 6.28f);

    printMat(toRowVec(&v));
    printMat(toColVec(&v));

    return 0;
}
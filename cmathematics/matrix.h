#ifndef CMATHEMATICS_MATRIX_H
#define CMATHEMATICS_MATRIX_H
#include <stdarg.h>
#include <stdio.h>
#include "cmathematics.h"
#include "vec.h"

typedef struct {
    unsigned int rows;
    unsigned int cols;
    float **elements;
}mat;

extern const mat MAT_UNDEFINED;

mat allocateMat(unsigned int rows, unsigned int cols);

mat identityMat(unsigned int dim);

mat zeroMatrixMat(unsigned int rows, unsigned int cols);

mat newMatrixMat(unsigned int rows, unsigned int cols, ...);

mat copyMat(mat m);

mat copyPtrMat(mat* m);

void printMat(mat m);

vec getMatRow(mat* m, unsigned int row);

vec getMatCol(mat* m, unsigned int col);

mat toRowVec(vec* v);

mat toColVec(vec* v);
#endif //CMATHEMATICS_MATRIX_H

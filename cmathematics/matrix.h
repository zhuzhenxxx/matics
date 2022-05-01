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

mat matScalarAddition(mat m, float k);

void matScalarAdditionTo(mat* m, float k);

mat matAdd(mat m1, mat m2);

bool matAddTo(mat* m1, mat* m2);

vec matVecMutiplication(mat m, vec v);

mat matMatMutiplication(mat m1, mat m2);

mat transpose(mat* m);
#endif //CMATHEMATICS_MATRIX_H

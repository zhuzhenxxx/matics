#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

const mat MAT_UNDEFINED = {0, 0, NULL};

mat allocateMat(unsigned int rows, unsigned int cols)
{
    mat ret;

    ret.rows = rows;
    ret.cols = cols;
    ret.elements = malloc(rows * cols * sizeof(float));
    for (unsigned int i = 0; i < rows; i++)
    {
        ret.elements[i] = malloc(cols * sizeof(float));
    }
    return ret;
}

mat identityMat(unsigned int dim)
{
    mat ret = allocateMat(dim, dim);

    for (unsigned int r = 0; r < dim; r++)
    {
        for (unsigned int c = 0; c < dim; c++)
        {
            ret.elements[r][c] = (r == c) ? 1.0f : 0.0f;
        }
    }
    return ret;
}

mat zeroMatrixMat(unsigned int rows, unsigned int cols)
{
    mat ret = allocateMat(rows, cols);

    for (unsigned int r = 0; r < rows; r++)
    {
        for (unsigned int c = 0; c < cols; c++)
        {
            ret.elements[r][c] = 0.0f;
        }
    }
    return ret;
}

mat newMatrixMat(unsigned int rows, unsigned int cols, ...)
{
    mat ret = allocateMat(rows, cols);

    va_list list;
    unsigned int size = rows * cols;
    va_start(list, size);

    for (unsigned int r = 0; r < rows; r++)
    {
        for (unsigned int c = 0; c < cols; c++)
        {
            ret.elements[r][c] = va_arg(list, double);
        }
    }

    va_end(list);
    return ret;
}

mat copyMat(mat m)
{
    return m;
}

mat copyPtrMat(mat* m)
{
    mat ret = allocateMat(m->rows, m->cols);
    memcpy(&ret, m, sizeof(mat));

    return ret;
}

void printMat(mat m)
{
    printf("\n");
    for (unsigned int r = 0; r < m.rows; r++)
    {
        printf("\n");
        printf("|");
        for (unsigned int c = 0; c < m.cols; c++)
        {
            printf(" %f", m.elements[r][c]);
        }
        printf("|");
    }
    printf("\n");
}

vec getMatRow(mat* m, unsigned int row)
{
    row--;
    if (row < 0 && row >= m->rows)
    {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m->cols);

    for (unsigned int i = 0; i < ret.dim; i++)
    {
        ret.elements[i] = m->elements[row][i];
    }

    return ret;
}

vec getMatCol(mat* m, unsigned int col)
{
    col--;
    if (col < 0  || col >= m->cols)
    {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m->cols);
    for (unsigned int i = 0; i < ret.dim; i++)
    {
        ret.elements[i] = m->elements[i][col];
    }

    return ret;
}

mat toRowVec(vec* v)
{
    mat ret = allocateMat(1, v->dim);

    for (unsigned int i = 0; i < v->dim; i++)
    {
        ret.elements[0][i]  =  v->elements[i];
    }

    return ret;
}

mat toColVec(vec* v)
{
    mat ret = allocateMat(v->dim, 1);

    for (unsigned int i = 0; i < v->dim; i++)
    {
        ret.elements[i][0]  = v->elements[i];
    }

    return ret;
}

mat matScalarAddition(mat m, float k)
{
    mat ret = allocateMat(m.rows, m.cols);

    for (unsigned int r = 0; r < ret.rows; r++)
    {
        for (unsigned int c = 0; c < ret.cols; c++)
        {
            ret.elements[r][c] = m.elements[r][c]  + k;
        }
    }
    return ret;
}

void matScalarAdditionTo(mat* m, float k)
{
    for (unsigned int r = 0; r < m->rows; r++)
    {
        for (unsigned int c = 0; c < m->cols; c++)
        {
            m->elements[r][c] += k;
        }
    }
}

mat matAdd(mat  m1, mat m2)
{
    if (m1.rows != m2.rows || m1.cols != m2.cols)
    {
        return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m1.rows,  m1.rows);

    for (unsigned int r = 0; r < ret.rows; r++)
    {
        for (unsigned int c = 0; c < ret.cols; c++)
        {
            ret.elements[r][c] = m1.elements[r][c] + m2.elements[r][c];
        }
    }
    return ret;
}

bool matAddTo(mat* m1, mat* m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }

    for (unsigned int r = 0; r < m1->rows; r++)
    {
        for (unsigned int c = 0; c < m1->cols; c++)
        {
            m1->elements[r][c] += m2->elements[r][c];
        }
    }

    return true;
}

vec matVecMutiplication(mat m, vec v)
{
    if (m.cols != v.dim)
    {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m.rows);

    for (unsigned int r = 0; r < ret.dim; r++)
    {
        ret.elements[r] = dotVec(v, getMatCol(&m, r + 1));
    }

    return ret;
}

mat matMatMutiplication(mat m1, mat m2)
{
    if (m1.cols != m2.rows)
    {
        return MAT_UNDEFINED;
    }

    vec* m1Rows = malloc(m1.rows * sizeof(vec));
    vec* m2Cols = malloc(m2.cols * sizeof(vec));

    for (unsigned int r = 0; r < m1.rows; r++)
    {
        m1Rows[r] = getMatRow(&m1, r + 1);
        printf("%d row of m1:\n", r);
        printVec(m1Rows[r]);
    }

    for (unsigned int c = 0; c < m2.cols; c++)
    {
        m2Cols[c] = getMatCol(&m2, c + 1);
        printf("%d col of m2:\n", c);
        printVec(m2Cols[c]);
    }

    return MAT_UNDEFINED;
}
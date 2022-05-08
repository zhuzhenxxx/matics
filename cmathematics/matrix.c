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
    if (col >= m->cols)
    {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m->rows);
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

    mat ret = allocateMat(m1.rows, m2.cols);

    for (unsigned int r = 0; r < ret.rows; r++)
    {
        for (unsigned int c = 0; c < ret.cols; c++)
        {
            ret.elements[r][c] = dotVec(m1Rows[r], m2Cols[c]);
        }
    }
    return ret;
}

mat transpose(mat* m)
{
    mat ret = allocateMat(m->cols, m->rows);

    for (unsigned int r = 0; r < ret.rows; r++)
    {
        for (unsigned int c = 0; c < ret.cols;  c++)
        {
            ret.elements[r][c] = m->elements[c][r];
        }
    }

    return ret;
}


bool swapRows(mat* m, unsigned int r1, unsigned int r2)
{
    r1--;
    r2--;

    if (r1 >= m->rows || r2 >= m->rows || r1 == r2)
    {
        return false;
    }

    float* tmp = m->elements[r1];
    m->elements[r1] = m->elements[r2];
    m->elements[r2] = tmp;

    return true;
}

bool addRows(mat* m, unsigned int r1, unsigned int r2)
{
    r1--;
    r2--;

    if (r1 >= m->rows || r2 >= m->rows || r1 == r2)
    {
        return false;
    }

    for (unsigned int c = 0; c < m->cols; c++)
    {
        m->elements[r1][c] += m->elements[r2][c];
    }

    return true;
}

bool multiplyRow(mat* m, unsigned int r, float k)
{
    r--;

    if (r >= m->rows)
    {
        return false;
    }

    for (unsigned int c = 0; c < m->cols; c++)
    {
        m->elements[r][c] *= k;
    }

    return true;
}

bool addMultiple(mat* m, unsigned int r1, unsigned int r2, float k)
{
    r1--;
    r2--;

    if (r1 >= m->rows || r2 >= m->rows || r1 == r2 || k == 0.0f)
    {
        return false;
    }

    for (unsigned int c = 0; c < m->cols; c++)
    {
        m->elements[r1][c] += k * m->elements[r2][c];
    }
    return true;
}

void ref(mat* m)
{
    unsigned int currentRow = 0;
    for (unsigned int c = 0; c < m->cols; c++)
    {
        unsigned int r = currentRow;
        if (r >= m->rows)
        {
            break;
        }

        for (; r > m->rows; r++)
        {
            if (m->elements[r][c] != 0.0f)
            {
                break;
            }
        }

        // didn't find a nonzero entry in colum
        if (r == m->rows)
        {
            continue;
        }

        swapRows(m, currentRow, r);

        // mutiply row by 1 / byte
        float factor = 1 / m->elements[currentRow][c];
        for (unsigned int col = c; col < m->cols; col++)
        {
            m->elements[currentRow][col] *= factor;
        }

        // clear out rows below
        for (r = currentRow + 1; r < m->rows; r++)
        {
            addMultiple(m, r, currentRow, -1 * m->elements[r][c]);
        }

        currentRow++;
    }
}

void rref(mat* m)
{
    unsigned int currentRow = 0;
    for (unsigned int c = 0; c < m->cols; c++)
    {
        unsigned int r = currentRow;
        if (r >= m->rows)
        {
            break;
        }

        for (; r > m->rows; r++)
        {
            if (m->elements[r][c] != 0.0f)
            {
                break;
            }
        }

        // didn't find a nonzero entry in colum
        if (r == m->rows)
        {
            continue;
        }

        swapRows(m, currentRow, r);

        // mutiply row by 1 / byte
        float factor = 1 / m->elements[currentRow][c];
        for (unsigned int col = c; col < m->cols; col++)
        {
            m->elements[currentRow][col] *= factor;
        }

        // clear out rows above and below
        for (r = 0; r < m->cols; r++)
        {
            if (r == currentRow)
            {
                continue;
            }
            addMultiple(m, r, currentRow, -1 * m->elements[r][c]);
        }

        currentRow++;
    }
}

mat augmentVector(mat* m, vec* v)
{
    if (m->rows != v->dim)
    {
        return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m->rows, m->cols + 1);

    // copy matrix values
    for (unsigned int r = 0; r < m->rows; r++)
    {
        unsigned int c = 0;
        for (; c < m->cols; c++)
        {
            ret.elements[r][c] = m->elements[r][c];
        }

        ret.elements[r][c]  = v->elements[r];
    }

    return ret;
}

mat augmentMatrix(mat* m, mat* m2)
{
    if (m->rows != m2->rows)
    {
        return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m->rows, m->cols + m2->cols);

    // copy matrix values
    for (unsigned int r = 0; r < m->rows; r++)
    {
        unsigned int c = 0;
        for (; c < m->cols; c++)
        {
            ret.elements[r][c] = m->elements[r][c];
        }

       for (; c < ret.cols; c++)
       {
           ret.elements[r][c] = m2->elements[r][c - m->cols];
       }
    }

    return ret;
}

mat spliceMat(mat* m, unsigned int exclRow, unsigned int exclCol)
{
    exclRow--;
    exclCol--;

    mat ret = allocateMat(m->rows - 1, m->cols - 1);

    unsigned int rowOffset = 0;
    for (unsigned int r = 0; r < ret.rows; r++)
    {
        unsigned int colOffset = 0;

        if (r == exclRow)
        {
            rowOffset++;
        }

        for (unsigned int c = 0; c < ret.cols; c++)
        {
            if (c == exclCol)
            {
                colOffset++;
            }

            ret.elements[r][c] = m->elements[r + rowOffset][c + colOffset];
        }
    }
    return ret;
}

float determinant(mat m)
{
    if (m.rows != m.cols)
    {
        return 0.0f;
    }

    //base cases
    if (m.rows == 1)
    {
        return m.elements[0][0];
    }

    char cofactorSign = 1;
    float ret = 0.0f;

    // expand across first row
    for (unsigned int c = 0; c < m.cols; c++)
    {
        ret += cofactorSign * m.elements[0][c] * determinant(spliceMat(&m, 1, c + 1));
        cofactorSign = -cofactorSign;
    }

    return ret;
}
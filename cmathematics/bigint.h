#ifndef CMATHEMATICS_BIGINT_H
#define CMATHEMATICS_BIGINT_H
#include "cmathematics.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct
{
    bool sign;
    unsigned int capacity;
    unsigned int noDigits;
    char* digists;
}bigint;

extern const bigint BIGINT_ZERO;

bigint allocateBigint(unsigned int capacity);

bigint strToBigint(char* str);

bigint newBigint(int i);

bigint newPositiveBigint(unsigned int i);
#endif //CMATHEMATICS_BIGINT_H

#include "bigint.h"
#include <stdlib.h>
#include <string.h>

const bigint BIGINT_ZERO = { true, 0, 0, NULL};

bigint allocateBigint(unsigned int capacity)
{
    bigint ret;
    ret.capacity = capacity;
    ret.noDigits = 0;
    ret.sign = true;
    ret.digists = malloc(capacity * sizeof(char));
    return ret;
}

bigint strToBigint(char* str)
{
    unsigned int len = strlen(str);
    unsigned int noDigits = len;
    bool sign = true;
    if (str[0] == '-')
    {
        sign = false;
        noDigits--;
    }

    if (noDigits == 0)
    {
        return BIGINT_ZERO;
    }

    // check for empty string
    bigint ret = allocateBigint(noDigits);
    ret.noDigits = noDigits;
    ret.sign = sign;

    for (unsigned int idx = 0; idx < noDigits; idx++)
    {
        char c = str[len - idx];
        if (c >= '0' && c <= '9')
        {
            ret.digists[idx] = c - '0';
        }
        else
        {
            // return 0 int
        }
    }
    return ret;
}

bigint newBigint(int i)
{
    bool sign = true;
    if (i < 0)
    {
        sign = false;
        i *= -1;
    }

    bigint ret = newPositiveBigint(i);
    ret.sign = sign;

    return ret;
}

bigint newPositiveBigint(unsigned int i)
{
    // get number of digits
    unsigned int copy = i;
    unsigned int noDigits = 0;
    while (copy > 0)
    {
        noDigits++;
        copy /= 10;
    }

    bigint ret = allocateBigint(noDigits);
    ret.noDigits = noDigits;
    for (unsigned int idx = 0; idx < noDigits; idx++, i /= 10)
    {
        ret.digists[idx] = i % 10;
    }

    return ret;
}
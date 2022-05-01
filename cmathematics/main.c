#include <stdio.h>
#include "cmathematics.h"
#include "vec.h"

int main()
{
    printf("hello world\n");
    printf("%d\n", NUMARGS(int, 3, 4, 5, 6));

    vec v1 = vector(1.0f, 2.0f, -3.0f);
    print(v1);

    printf("%f\n", magnitude(v1));
    printf("%f\n", magnitudeSquared(v1));

    vec v2 = vector(2.0f, 3.0f, -4.0f);
    print(v2);

    vec v3 = add(v1, v2);
    print(v3);

    subtract(v1, v2);
    print(v1);

    return 0;
}
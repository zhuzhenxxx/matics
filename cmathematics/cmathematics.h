#ifndef CMATHETMATICS_CMATHEMATICS_H
#define CMATHETMATICS_CMATHEMATICS_H
typedef unsigned char bool;
#define false 0
#define true 1

#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) /  sizeof(float)  - 1)


#endif //CMATHETMATICS_CMATHEMATICS_H

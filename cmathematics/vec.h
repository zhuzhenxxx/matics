#include <stdarg.h>
#include <stdio.h>
#include "cmathematics.h"
#ifndef CMATHETMATICS_VEC_H
#define CMATHETMATICS_VEC_H

#define vector(...) newVector(NUMARGS(float, __VA_ARGS__), ##__VA_ARGS__)

typedef struct {
    unsigned int dim;  //维度
    float *elements;   //向量元素
} vec;

extern const vec VEC_UNDEFINED;

//分配几维的单位向量
vec allocate(unsigned int dim);

//构造向量，分配+赋值
vec constructDefaultVector(unsigned int dim, float val);

//构造空向量，赋值0
vec constructEmptyVector(unsigned int dim);

//分配一个自定义值的向量
vec newVector(unsigned int dim, ...);

//拷贝一个向量  值传递
vec copy(vec v);

//拷贝一个向量， 地址传递  内存拷贝
vec copyPtr(vec* v);

//输出向量
void print(vec v);

//判断两个向量是否相等
bool equals(vec v1, vec v2);

//数乘运算 向量v 每个元素乘以k（新分配）
vec scalarMultiplication(vec v, float k);

//数乘运算 向量v 每个元素乘以k（已存在）
void scalarMultiplicationBy(vec* v, float k);

//除运算 向量v 每个元素除以k（新分配）
vec scalarDivision(vec v, float k);

//除运算 向量v 每个元素除以k（已存在）
void scalarDivisionBy(vec* v, float k);

//指数运算
vec power(vec v, float k);

//指数运算 已存在
void powerOf(vec* v, float k);

//向量加
vec add(vec v1, vec v2);

//将v2加至v1
bool addTo(vec* v1, vec v2);

//向量减
vec subtract(vec v1, vec v2);

//v1 - v2 结果赋值于v1
bool subtractFrom(vec* v1, vec v2);

//乘法  v1第一行 * v2第一行
vec multiply(vec v1, vec v2);

//乘法  v1第一行 * v2第一行 以此类推， 值赋值v1
bool mutiplyBy(vec* v1, vec v2);

//同上面乘法
vec devide(vec v1, vec v2);

bool divideBy(vec* v1, vec v2);

// 两个向量点乘之积
float dot(vec v1, vec v2);

// 判断维度是否相同 相同返回积
bool orthogonal(vec v1, vec v2);

//三维向量，叉积叉积的定义： c =a x b  其中a,b,c均为向量。即两个向量的叉积得到的还是向量！
vec cross(vec v1, vec v2);

//向量内积
float magnitude(vec v);

float magnitudeSquared(vec v);

//单位化
vec normalized(vec v);

void normalize(vec* v);

#endif //CMATHETMATICS_VEC_H

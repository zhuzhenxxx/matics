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
vec allocateVec(unsigned int dim);

//构造向量，分配+赋值
vec constructDefaultVector(unsigned int dim, float val);

//构造空向量，赋值0
vec constructEmptyVector(unsigned int dim);

//分配一个自定义值的向量
vec newVector(unsigned int dim, ...);

//拷贝一个向量  值传递
vec copyVec(vec v);

//拷贝一个向量， 地址传递  内存拷贝
vec copyPtrVec(vec* v);

//输出向量
void printVec(vec v);

//判断两个向量是否相等
bool equalsVec(vec v1, vec v2);

//数乘运算 向量v 每个元素乘以k（新分配）
vec scalarMultiplicationVec(vec v, float k);

//数乘运算 向量v 每个元素乘以k（已存在）
void scalarMultiplicationByVec(vec* v, float k);

//除运算 向量v 每个元素除以k（新分配）
vec scalarDivisionVec(vec v, float k);

//除运算 向量v 每个元素除以k（已存在）
void scalarDivisionByVec(vec* v, float k);

//指数运算
vec powerVec(vec v, float k);

//指数运算 已存在
void powerOfVec(vec* v, float k);

//向量加
vec addVec(vec v1, vec v2);

//将v2加至v1
bool addToVec(vec* v1, vec v2);

//向量减
vec subtractVec(vec v1, vec v2);

//v1 - v2 结果赋值于v1
bool subtractFromVec(vec* v1, vec v2);

//乘法  v1第一行 * v2第一行
vec multiplyVec(vec v1, vec v2);

//乘法  v1第一行 * v2第一行 以此类推， 值赋值v1
bool mutiplyByVec(vec* v1, vec v2);

//同上面乘法
vec devidVece(vec v1, vec v2);

bool divideByVec(vec* v1, vec v2);

// 两个向量点乘之积
float dotVec(vec v1, vec v2);

// 判断维度是否相同 相同返回积
bool orthogonalVec(vec v1, vec v2);

//三维向量，叉积叉积的定义： c =a x b  其中a,b,c均为向量。即两个向量的叉积得到的还是向量！
vec crossVec(vec v1, vec v2);

//向量内积
float magnitudeVec(vec v);

float magnitudeSquaredVec(vec v);

//单位化
vec normalizedVec(vec v);

void normalizeVec(vec* v);

#endif //CMATHETMATICS_VEC_H

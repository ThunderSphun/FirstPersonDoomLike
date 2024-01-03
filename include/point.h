#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <stdio.h>

#pragma region TYPES
typedef struct float2Point {
	float x;
	float y;
} pointF2_t;

typedef struct float3Point {
	float x;
	float y;
	float z;
} pointF3_t;

typedef struct int2Point {
	int x;
	int y;
} pointI2_t;

typedef struct int3Point {
	int x;
	int y;
	int z;
} pointI3_t;

typedef struct uint2Point {
	unsigned int x;
	unsigned int y;
} pointU2_t;

typedef struct uint3Point {
	unsigned int x;
	unsigned int y;
	unsigned int z;
} pointU3_t;

#pragma region CONSTRUCT
#define float2(_x, _y) ({ \
    /* ensuring type */\
    float __x = (_x);     \
    float __y = (_y);     \
    (pointF2_t) {.x = __x, .y = __y};\
})

#define float3(_x, _y, _z) ({ \
    /* ensuring type */\
    float __x = (_x);     \
    float __y = (_y);     \
    float __z = (_z);     \
    (pointF3_t) {.x = __x, .y = __y, .z = __z};\
})

#define int2(_x, _y) ({ \
    /* ensuring type */\
    int __x = (_x);     \
    int __y = (_y);     \
    (pointI2_t) {.x = __x, .y = __y};\
})

#define int3(_x, _y, _z) ({ \
    /* ensuring type */\
    int __x = (_x);     \
    int __y = (_y);     \
    int __z = (_z);     \
    (pointI3_t) {.x = __x, .y = __y, .z = __z};\
})

#define uint2(_x, _y) ({ \
    /* ensuring type */\
    unsigned int __x = (_x);     \
    unsigned int __y = (_y);     \
    (pointU2_t) {.x = __x, .y = __y};\
})

#define uint3(_x, _y, _z) ({ \
    /* ensuring type */\
    unsigned int __x = (_x);     \
    unsigned int __y = (_y);     \
    unsigned int __z = (_z);     \
    (pointU3_t) {.x = __x, .y = __y, .z = __z};\
})
#pragma endregion CONSTRUCT
#pragma endregion TYPES

#pragma region OPERATORS
#pragma region ADD
pointF2_t addF2F2(pointF2_t lhs, pointF2_t rhs);
pointF3_t addF3F3(pointF3_t lhs, pointF3_t rhs);
pointI2_t addI2I2(pointI2_t lhs, pointI2_t rhs);
pointI3_t addI3I3(pointI3_t lhs, pointI3_t rhs);
pointU2_t addU2U2(pointU2_t lhs, pointU2_t rhs);
pointU3_t addU3U3(pointU3_t lhs, pointU3_t rhs);

pointF2_t addF2I2(pointF2_t lhs, pointI2_t rhs);
pointF3_t addF3I3(pointF3_t lhs, pointI3_t rhs);
pointF2_t addF2U2(pointF2_t lhs, pointU2_t rhs);
pointF3_t addF3U3(pointF3_t lhs, pointU3_t rhs);

pointI2_t addI2U2(pointI2_t lhs, pointU2_t rhs);
pointI3_t addI3U3(pointI3_t lhs, pointU3_t rhs);
#pragma endregion ADD
#pragma region SUB
pointF2_t subF2F2(pointF2_t lhs, pointF2_t rhs);
pointF3_t subF3F3(pointF3_t lhs, pointF3_t rhs);
pointI2_t subI2I2(pointI2_t lhs, pointI2_t rhs);
pointI3_t subI3I3(pointI3_t lhs, pointI3_t rhs);
pointU2_t subU2U2(pointU2_t lhs, pointU2_t rhs);
pointU3_t subU3U3(pointU3_t lhs, pointU3_t rhs);

pointF2_t subF2I2(pointF2_t lhs, pointI2_t rhs);
pointF3_t subF3I3(pointF3_t lhs, pointI3_t rhs);
pointF2_t subI2F2(pointI2_t lhs, pointF2_t rhs);
pointF3_t subI3F3(pointI3_t lhs, pointF3_t rhs);

pointU2_t subU2I2(pointU2_t lhs, pointI2_t rhs);
pointU3_t subU3I3(pointU3_t lhs, pointI3_t rhs);
pointI2_t subI2U2(pointI2_t lhs, pointU2_t rhs);
pointI3_t subI3U3(pointI3_t lhs, pointU3_t rhs);

pointF2_t subF2U2(pointF2_t lhs, pointU2_t rhs);
pointF3_t subF3U3(pointF3_t lhs, pointU3_t rhs);
pointF2_t subU2F2(pointU2_t lhs, pointF2_t rhs);
pointF3_t subU3F3(pointU3_t lhs, pointF3_t rhs);
#pragma endregion SUB
#pragma endregion OPERATORS

#endif // POINT_H
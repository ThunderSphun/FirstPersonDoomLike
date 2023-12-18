#ifndef POINT_H
#define POINT_H

#include <math.h>

#pragma region TYPES
#pragma region CAST
#define toFloat2(_point) ({ \
    pointI2_t __point = (_point);     \
    (pointF2_t) {.x = __point.x, .y = __point.y};\
})

#define toFloat3(_point) ({ \
    pointI3_t __point = (_point);                \
    (pointF3_t) {.x = __point.x, .y = __point.y, .z = __point.z};\
})

#define toInt2(_point) ({ \
    pointF2_t __point = (_point);     \
    (pointI2_t) {.x = __point.x, .y = __point.y};\
})

#define toInt3(_point) ({ \
    pointF3_t __point = (_point);                \
    (pointI3_t) {.x = __point.x, .y = __point.y, .z = __point.z};\
})
#pragma endregion CAST
#pragma region CONSTRUCT
#define float2(_x, _y) ({ \
    float __x = (_x);     \
    float __y = (_y);     \
    (pointF2_t) {.x = __x, .y = __y};\
})

#define float3(_x, _y, _z) ({ \
    float __x = (_x);     \
    float __y = (_y);     \
    float __z = (_z);     \
    (pointF3_t) {.x = __x, .y = __y, .z = __z};\
})

#define int2(_x, _y) ({ \
    float __x = (_x);     \
    float __y = (_y);     \
    (pointI2_t) {.x = __x, .y = __y};\
})

#define int3(_x, _y, _z) ({ \
    float __x = (_x);     \
    float __y = (_y);     \
    float __z = (_z);     \
    (pointI3_t) {.x = __x, .y = __y, .z = __z};\
})
#pragma endregion CONSTRUCT

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
#pragma endregion TYPES

#pragma region OPERATORS
#pragma region ADD
pointF2_t addF2F2(pointF2_t a, pointF2_t b);
pointF3_t addF3F3(pointF3_t a, pointF3_t b);
pointI2_t addI2I2(pointI2_t a, pointI2_t b);
pointI3_t addI3I3(pointI3_t a, pointI3_t b);

pointF2_t addF2I2(pointF2_t a, pointI2_t b);
pointF3_t addF3I3(pointF3_t a, pointI3_t b);
#pragma endregion ADD
#pragma region SUB
pointF2_t subF2F2(pointF2_t a, pointF2_t b);
pointF3_t subF3F3(pointF3_t a, pointF3_t b);
pointI2_t subI2I2(pointI2_t a, pointI2_t b);
pointI3_t subI3I3(pointI3_t a, pointI3_t b);

pointF2_t subF2I2(pointF2_t a, pointI2_t b);
pointF3_t subF3I3(pointF3_t a, pointI3_t b);
#pragma endregion SUB
#pragma endregion OPERATORS

#endif // POINT_H
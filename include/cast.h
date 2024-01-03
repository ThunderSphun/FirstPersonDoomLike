#ifndef CAST_H
#define CAST_H

// TODO make it work with not including other lib files
#include "point.h"

#define CAST(_a, type) (*((type*)&_a))
#define CAST_FROM(_a, from, to) from : (to) CAST(_a, from)

#define toFloat(_a) ({                                          \
    __typeof(_a) __a = (_a);                                    \
    _Generic(__a,                                               \
        CAST_FROM(__a, char, float),                            \
        CAST_FROM(__a, signed char, float),                     \
        CAST_FROM(__a, short, float),                           \
        CAST_FROM(__a, int, float),                             \
        CAST_FROM(__a, long, float),                            \
        CAST_FROM(__a, long long, float),                       \
        CAST_FROM(__a, unsigned char, float),                   \
        CAST_FROM(__a, unsigned short, float),                  \
        CAST_FROM(__a, unsigned int, float),                    \
        CAST_FROM(__a, unsigned long, float),                   \
        CAST_FROM(__a, unsigned long long, float),              \
        pointI2_t : (pointF2_t) {                               \
            .x = CAST(__a, pointI2_t).x,                        \
            .y = CAST(__a, pointI2_t).y},                       \
        pointU2_t : (pointF2_t) {                               \
            .x = CAST(__a, pointU2_t).x,                        \
            .y = CAST(__a, pointU2_t).y},                       \
        pointI3_t : (pointF3_t) {                               \
            .x = CAST(__a, pointI3_t).x,                        \
            .y = CAST(__a, pointI3_t).y,                        \
            .z = CAST(__a, pointI3_t).z},                       \
        pointU3_t : (pointF3_t) {                               \
            .x = CAST(__a, pointU3_t).x,                        \
            .y = CAST(__a, pointU3_t).y,                        \
            .z = CAST(__a, pointU3_t).z}                        \
    );                                                          \
})

#define toInt(_a) ({                                            \
    __typeof(_a) __a = (_a);                                    \
    _Generic(__a,                                               \
        CAST_FROM(__a, float, int),                             \
        CAST_FROM(__a, double, int),                            \
        CAST_FROM(__a, long double, int),                       \
        pointF2_t : (pointI2_t) {                               \
            .x = CAST(__a, pointF2_t).x,                        \
            .y = CAST(__a, pointF2_t).y},                       \
        pointF3_t : (pointI3_t) {                               \
            .x = CAST(__a, pointF3_t).x,                        \
            .y = CAST(__a, pointF3_t).y,                        \
            .z = CAST(__a, pointF3_t).z}                        \
    );                                                          \
})

#define toUInt(_a) ({                                           \
    __typeof(_a) __a = (_a);                                    \
    _Generic(__a,                                               \
        CAST_FROM(__a, float, unsigned int),                    \
        CAST_FROM(__a, double, unsigned int),                   \
        CAST_FROM(__a, long double, unsigned int),              \
        pointF2_t : (pointU2_t) {                               \
            .x = CAST(__a, pointF2_t).x,                        \
            .y = CAST(__a, pointF2_t).y},                       \
        pointF3_t : (pointU3_t) {                               \
            .x = CAST(__a, pointF3_t).x,                        \
            .y = CAST(__a, pointF3_t).y,                        \
            .z = CAST(__a, pointF3_t).z}                        \
    );                                                          \
})

#define toSigned(_a) ({                                         \
    __typeof(_a) __a = (_a);                                    \
    _Generic(__a,                                               \
        CAST_FROM(__a, unsigned char, signed char),             \
        CAST_FROM(__a, unsigned short, signed short),           \
        CAST_FROM(__a, unsigned int, signed int),               \
        CAST_FROM(__a, unsigned long, signed long),             \
        CAST_FROM(__a, unsigned long long, signed long long),   \
        pointU2_t : (pointI2_t) {                               \
            .x = CAST(__a, pointU2_t).x,                        \
            .y = CAST(__a, pointU2_t).y},                       \
        pointU3_t : (pointI3_t) {                               \
            .x = CAST(__a, pointU3_t).x,                        \
            .y = CAST(__a, pointU3_t).y,                        \
            .z = CAST(__a, pointU3_t).z}                        \
    );                                                          \
})

#define toUnsigned(_a) ({                                       \
    __typeof(_a) __a = (_a);                                    \
    _Generic(__a,                                               \
        CAST_FROM(__a, char, unsigned char),                    \
        CAST_FROM(__a, signed char, unsigned char),             \
        CAST_FROM(__a, short, unsigned short),                  \
        CAST_FROM(__a, int, unsigned int),                      \
        CAST_FROM(__a, long, unsigned long),                    \
        CAST_FROM(__a, long long, unsigned long long),          \
        pointI2_t : (pointU2_t) {                               \
            .x = CAST(__a, pointI2_t).x,                        \
            .y = CAST(__a, pointI2_t).y},                       \
        pointI3_t : (pointU3_t) {                               \
            .x = CAST(__a, pointI3_t).x,                        \
            .y = CAST(__a, pointI3_t).y,                        \
            .z = CAST(__a, pointI3_t).z}                        \
    );                                                          \
})

#define toString(_s) ({                                         \
    __typeof(_s) __s = (_s);                                    \
    char __max = 75;                                            \
    char __value[75];                                           \
    _Generic(__s,                                               \
        pointF2_t : snprintf(__value, __max, "(%#g, %#g)",      \
            ((pointF2_t*)&__s)->x,                              \
            ((pointF2_t*)&__s)->y),                             \
        pointI2_t : snprintf(__value, __max, "(%i, %i)",        \
            ((pointI2_t*)&__s)->x,                              \
            ((pointI2_t*)&__s)->y),                             \
        pointU2_t : snprintf(__value, __max, "(%u, %u)",        \
            ((pointU2_t*)&__s)->x,                              \
            ((pointU2_t*)&__s)->y),                             \
        pointF3_t : snprintf(__value, __max, "(%#g, %#g, %#g)", \
            ((pointF3_t*)&__s)->x,                              \
            ((pointF3_t*)&__s)->y,                              \
            ((pointF3_t*)&__s)->z),                             \
        pointI3_t : snprintf(__value, __max, "(%i, %i, %i)",    \
            ((pointI3_t*)&__s)->x,                              \
            ((pointI3_t*)&__s)->y,                              \
            ((pointI3_t*)&__s)->z),                             \
        pointU3_t : snprintf(__value, __max, "(%u, %u, %u)",    \
            ((pointU3_t*)&__s)->x,                              \
            ((pointU3_t*)&__s)->y,                              \
            ((pointU3_t*)&__s)->z)                              \
    );                                                          \
    (const char*) __value;                                      \
})

#endif // CAST_H
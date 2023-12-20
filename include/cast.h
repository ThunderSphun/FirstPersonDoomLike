#ifndef CAST_H
#define CAST_H

#define CAST(_a, type) (*((type*)&_a))
#define CAST_FROM(_a, from, to) from : (to) CAST(_a, from)

#define toFloat(_a) ({                                       \
    __typeof(_a) __a = (_a);                                 \
    _Generic(__a,                                            \
        CAST_FROM(__a, char, float),                         \
        CAST_FROM(__a, short, float),                        \
        CAST_FROM(__a, long, float),                         \
        CAST_FROM(__a, int, float),                          \
        CAST_FROM(__a, long long, float),                    \
        CAST_FROM(__a, unsigned char, float),                \
        CAST_FROM(__a, unsigned short, float),               \
        CAST_FROM(__a, unsigned long, float),                \
        CAST_FROM(__a, unsigned int, float),                 \
        CAST_FROM(__a, unsigned long long, float),           \
        pointI2_t : (pointF2_t) {                            \
            .x = CAST(__a, pointI2_t).x,                     \
            .y = CAST(__a, pointI2_t).y},                    \
        pointU2_t : (pointF2_t) {                            \
            .x = CAST(__a, pointU2_t).x,                     \
            .y = CAST(__a, pointU2_t).y},                    \
        pointI3_t : (pointF3_t) {                            \
            .x = CAST(__a, pointI3_t).x,                     \
            .y = CAST(__a, pointI3_t).y,                     \
            .z = CAST(__a, pointI3_t).z},                    \
        pointU3_t : (pointF3_t) {                            \
            .x = CAST(__a, pointU3_t).x,                     \
            .y = CAST(__a, pointU3_t).y,                     \
            .z = CAST(__a, pointU3_t).z}                     \
    );                                                       \
})

#define toInt(_a) ({                                         \
    __typeof(_a) __a = (_a);                                 \
    _Generic(__a,                                            \
        CAST_FROM(__a, float, int),                          \
        CAST_FROM(__a, double, int),                         \
        CAST_FROM(__a, long double, int),                    \
        pointF2_t : (pointI2_t) {                            \
            .x = CAST(__a, pointF2_t).x,                     \
            .y = CAST(__a, pointF2_t).y},                    \
        pointF3_t : (pointI3_t) {                            \
            .x = CAST(__a, pointF3_t).x,                     \
            .y = CAST(__a, pointF3_t).y,                     \
            .z = CAST(__a, pointF3_t).z}                     \
    );                                                       \
})

#define toSigned(_a) ({                                      \
    __typeof(_a) __a = (_a);                                 \
    _Generic(__a,                                            \
        CAST_FROM(__a, unsigned char, char),                 \
        CAST_FROM(__a, unsigned short, short),               \
        CAST_FROM(__a, unsigned int, int),                   \
        CAST_FROM(__a, unsigned long, long),                 \
        CAST_FROM(__a, unsigned long long, long long),       \
        pointU2_t : (pointI2_t) {                            \
            .x = CAST(__a, pointU2_t).x,                     \
            .y = CAST(__a, pointU2_t).y},                    \
        pointU3_t : (pointI3_t) {                            \
            .x = CAST(__a, pointU3_t).x,                     \
            .y = CAST(__a, pointU3_t).y,                     \
            .z = CAST(__a, pointU3_t).z}                     \
    );                                                       \
})

#define toUnsigned(_a) ({                                    \
    __typeof(_a) __a = (_a);                                 \
    _Generic(__a,                                            \
        CAST_FROM(__a, char, unsigned char),                 \
        CAST_FROM(__a, short, unsigned short),               \
        CAST_FROM(__a, int, unsigned int),                   \
        CAST_FROM(__a, long, unsigned long),                 \
        CAST_FROM(__a, long long, unsigned long long),       \
        pointI2_t : (pointU2_t) {                            \
            .x = CAST(__a, pointI2_t).x,                     \
            .y = CAST(__a, pointI2_t).y},                    \
        pointI3_t : (pointU3_t) {                            \
            .x = CAST(__a, pointI3_t).x,                     \
            .y = CAST(__a, pointI3_t).y,                     \
            .z = CAST(__a, pointI3_t).z}                     \
    );                                                       \
})

#define toString(_s) ({                                      \
    __typeof(_s) __s = (_s);                                 \
    char __max = 75;                                         \
    char __value[75];                                        \
    _Generic(__s,                                            \
        pointF2_t : snprintf(__value, __max, "(%f, %f)",     \
            ((pointF2_t*)&__s)->x,                           \
            ((pointF2_t*)&__s)->y),                          \
        pointI2_t : snprintf(__value, __max, "(%i, %i)",     \
            ((pointI2_t*)&__s)->x,                           \
            ((pointI2_t*)&__s)->y),                          \
        pointU2_t : snprintf(__value, __max, "(%u, %u)",     \
            ((pointU2_t*)&__s)->x,                           \
            ((pointU2_t*)&__s)->y),                          \
        pointF3_t : snprintf(__value, __max, "(%f, %f, %f)", \
            ((pointF3_t*)&__s)->x,                           \
            ((pointF3_t*)&__s)->y,                           \
            ((pointF3_t*)&__s)->z),                          \
        pointI3_t : snprintf(__value, __max, "(%i, %i, %i)", \
            ((pointI3_t*)&__s)->x,                           \
            ((pointI3_t*)&__s)->y,                           \
            ((pointI3_t*)&__s)->z),                          \
        pointU3_t : snprintf(__value, __max, "(%u, %u, %u)", \
            ((pointU3_t*)&__s)->x,                           \
            ((pointU3_t*)&__s)->y,                           \
            ((pointU3_t*)&__s)->z)                           \
    );                                                       \
    (const char*) __value;                                   \
})

#if 0
// make sure it is at all times included just once
#if __COUNTER__ < 1

#include <stdio.h>
#include "point.h"

void castTest() {
	int i = -1;
	char c = -1;
	short s = -1;
	long l = -1;
	long long ll = -1;
	pointI2_t i2 = int2(i, i);
	pointI3_t i3 = int3(i, i, i);

	unsigned int ui = UINT32_MAX;
	unsigned char uc = UINT8_MAX;
	unsigned short us = UINT16_MAX;
	unsigned long ul = (unsigned long) UINT64_MAX;
	unsigned long long ull = UINT64_MAX;
	pointU2_t u2 = uint2(ui, ui);
	pointU3_t u3 = uint3(ui, ui, ui);

	float f = -123.123f;
	double d = -123456.123456;
	long double ld = -123456789.123456789;
	pointF2_t f2 = float2(f, f);
	pointF3_t f3 = float3(f, f, f);

	pointI2_t i_u2 = toSigned(u2);
	pointI3_t i_u3 = toSigned(u3);
	pointU2_t u_i2 = toUnsigned(i2);
	pointU3_t u_i3 = toUnsigned(i3);

	pointF2_t f_i2 = toFloat(i2);
	pointF2_t f_u2 = toFloat(u2);
	pointF3_t f_i3 = toFloat(i3);
	pointF3_t f_u3 = toFloat(u3);

	pointI2_t i_f2 = toInt(f2);
	pointI3_t i_f3 = toInt(f3);

	toFloat(i);
	toFloat(c);
	toFloat(s);
	toFloat(l);
	toFloat(ll);
	toFloat(i2);
	toFloat(i3);

	toFloat(ui);
	toFloat(uc);
	toFloat(us);
	toFloat(ul);
	toFloat(ull);
	toFloat(u2);
	toFloat(u3);

	toInt(f);
	toInt(d);
	toInt(ld);
	toInt(f2);
	toInt(f3);

	toUnsigned(i);
	toUnsigned(c);
	toUnsigned(s);
	toUnsigned(l);
	toUnsigned(ll);
	toUnsigned(i2);
	toUnsigned(i3);

	toSigned(ui);
	toSigned(uc);
	toSigned(us);
	toSigned(ul);
	toSigned(ull);
	toSigned(u2);
	toSigned(u3);

	printf("i:   %i\n", i);
	printf("c:   %hhi\n", c);
	printf("s:   %hi\n", s);
	printf("l:   %li\n", l);
	printf("ll:  %lli\n", ll);

	printf("ui:  %u\n", ui);
	printf("uc:  %hhu\n", uc);
	printf("us:  %hu\n", us);
	printf("ul:  %lu\n", ul);
	printf("ull: %llu\n", ull);

	printf("-i:  %u\n", toUnsigned(i));
	printf("-c:  %hhu\n", toUnsigned(c));
	printf("-s:  %hu\n", toUnsigned(s));
	printf("-l:  %lu\n", toUnsigned(l));
	printf("-ll: %llu\n", toUnsigned(ll));

	printf("+i:  %i\n", toSigned(ui));
	printf("+c:  %hhi\n", toSigned(uc));
	printf("+s:  %hi\n", toSigned(us));
	printf("+l:  %li\n", toSigned(ul));
	printf("+ll: %lli\n", toSigned(ull));

	printf("f:   %f\n", f);
	printf("d:   %f\n", d);
	printf("ld:  %Lf\n", ld);

	printf("f:   %i\n", toInt(f));
	printf("d:   %i\n", toInt(d));
	printf("ld:  %i\n", toInt(ld));

	printf("i:   %f\n", toFloat(i));
	printf("c:   %f\n", toFloat(c));
	printf("s:   %f\n", toFloat(s));
	printf("l:   %f\n", toFloat(l));
	printf("ll:  %f\n", toFloat(ll));

	printf("ui:  %f\n", toFloat(ui));
	printf("uc:  %f\n", toFloat(uc));
	printf("us:  %f\n", toFloat(us));
	printf("ul:  %f\n", toFloat(ul));
	printf("ull: %f\n", toFloat(ull));

	printf("i2:  %s\n", toString(i2));
	printf("u2:  %s\n", toString(u2));
	printf("f2:  %s\n", toString(f2));

	printf("i3:  %s\n", toString(i3));
	printf("u3:  %s\n", toString(u3));
	printf("f3:  %s\n", toString(f3));

	printf("-i2: %s\n", toString(u_i2));
	printf("+u2: %s\n", toString(i_u2));
	printf("-i3: %s\n", toString(u_i3));
	printf("+u3: %s\n", toString(i_u3));

	printf("i2:  %s\n", toString(f_i2));
	printf("u2:  %s\n", toString(f_u2));
	printf("f2:  %s\n", toString(i_f2));
	printf("i3:  %s\n", toString(f_i3));
	printf("u3:  %s\n", toString(f_u3));
	printf("f3:  %s\n", toString(i_f3));
}

#endif // counter
#endif

#undef CAST_FROM
#undef CAST

#endif // CAST_H
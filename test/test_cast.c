#include "cast.h"

#include "unity_wrapper.h"
#include <float.h>

// included to prevent compilation error in some cases
void setUp(void) {}

void tearDown(void) {}

void test_canCastWithoutPointIncluded() {
	int i = 1;
	toFloat(i);
}

#include "point.h"

void test_canCastWithPointIncluded() {
	int i = 1;
	toFloat(i);

	pointI3_t i3 = int3(1, 2, 3);
	toFloat(i3);
}

void test_canCastSignedByteToFloat() {
	const signed char a = +0;
	const signed char b = +1;
	const signed char c = -1;
	const signed char d = INT8_MAX;
	const signed char e = INT8_MIN;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
}

void test_canCastByteToFloat() {
	const char a = +0;
	const char b = +1;
	const char c = -1;
	const char d = INT8_MAX;
	const char e = INT8_MIN;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
}

void test_canCastUnsignedByteToFloat() {
	const unsigned char a = +0;
	const unsigned char b = +1;
	const unsigned char c = -1;
	const unsigned char d = INT8_MAX;
	const unsigned char e = INT8_MIN;
	const unsigned char f = UINT8_MAX;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
	TEST_ASSERT_EQUAL_MESSAGE((float) f, toFloat(f), "f");
}

void test_canCastSignedShortToFloat() {
	const signed short a = +0;
	const signed short b = +1;
	const signed short c = -1;
	const signed short d = INT16_MAX;
	const signed short e = INT16_MIN;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
}

void test_canCastUnsignedShortToFloat() {
	const unsigned short a = +0;
	const unsigned short b = +1;
	const unsigned short c = -1;
	const unsigned short d = INT16_MAX;
	const unsigned short e = INT16_MIN;
	const unsigned short f = UINT16_MAX;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
	TEST_ASSERT_EQUAL_MESSAGE((float) f, toFloat(f), "f");
}

void test_canCastSignedIntToFloat() {
	const signed int a = +0;
	const signed int b = +1;
	const signed int c = -1;
	const signed int d = INT32_MAX;
	const signed int e = INT32_MIN;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
}

void test_canCastUnsignedIntToFloat() {
	const unsigned int a = +0;
	const unsigned int b = +1;
	const unsigned int c = -1;
	const unsigned int d = INT32_MAX;
	const unsigned int e = INT32_MIN;
	const unsigned int f = UINT32_MAX;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
	TEST_ASSERT_EQUAL_MESSAGE((float) f, toFloat(f), "f");
}

void test_canCastSignedLongToFloat() {
	const signed long a = +0;
	const signed long b = +1;
	const signed long c = -1;
	const signed long d = (signed long) INT64_MAX;
	const signed long e = (signed long) INT64_MIN;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
}

void test_canCastUnsignedLongToFloat() {
	const unsigned long a = +0;
	const unsigned long b = +1;
	const unsigned long c = -1;
	const unsigned long d = (unsigned long) INT64_MAX;
	const unsigned long e = (unsigned long) INT64_MIN;
	const unsigned long f = (unsigned long) UINT64_MAX;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
	TEST_ASSERT_EQUAL_MESSAGE((float) f, toFloat(f), "f");
}

void test_canCastSignedLongLongToFloat() {
	const signed long long a = +0;
	const signed long long b = +1;
	const signed long long c = -1;
	const signed long long d = INT64_MAX;
	const signed long long e = INT64_MIN;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
}

void test_canCastUnsignedLongLongToFloat() {
	const unsigned long long a = +0;
	const unsigned long long b = +1;
	const unsigned long long c = -1;
	const unsigned long long d = INT64_MAX;
	const unsigned long long e = INT64_MIN;
	const unsigned long long f = UINT64_MAX;

	TEST_ASSERT_EQUAL_MESSAGE((float) a, toFloat(a), "a");
	TEST_ASSERT_EQUAL_MESSAGE((float) b, toFloat(b), "b");
	TEST_ASSERT_EQUAL_MESSAGE((float) c, toFloat(c), "c");
	TEST_ASSERT_EQUAL_MESSAGE((float) d, toFloat(d), "d");
	TEST_ASSERT_EQUAL_MESSAGE((float) e, toFloat(e), "e");
	TEST_ASSERT_EQUAL_MESSAGE((float) f, toFloat(f), "f");
}

void test_canCastFloatToInt() {
	const float a = +0.0f;
	const float b = -0.0f;
	const float c = +1.0f;
	const float d = -1.0f;
	const float e = FLT_MIN;
	const float f = FLT_MAX;
	const float g = HUGE_VALF; // inf
	const float h = -HUGE_VALF; // -inf
	const float i = NAN; // nan

	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) a, toInt(a), "a");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) b, toInt(b), "b");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) c, toInt(c), "c");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) d, toInt(d), "d");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) e, toInt(e), "e");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) f, toInt(f), "f");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) g, toInt(g), "g");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) h, toInt(h), "h");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) i, toInt(i), "i");
}

void test_canCastDoubleToInt() {
	const double a = +0.0;
	const double b = -0.0;
	const double c = +1.0;
	const double d = -1.0;
	const double e = DBL_MIN;
	const double f = DBL_MAX;
	const double g = HUGE_VAL; // inf
	const double h = -HUGE_VAL; // -inf
	const double i = NAN; // nan

	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) a, toInt(a), "a");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) b, toInt(b), "b");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) c, toInt(c), "c");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) d, toInt(d), "d");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) e, toInt(e), "e");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) f, toInt(f), "f");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) g, toInt(g), "g");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) h, toInt(h), "h");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) i, toInt(i), "i");
}

void test_canCastLongDoubleToInt() {
	const long double a = +0.0l;
	const long double b = -0.0l;
	const long double c = +1.0l;
	const long double d = -1.0l;
	const long double e = LDBL_MIN;
	const long double f = LDBL_MAX;
	const long double g = HUGE_VALL; // inf
	const long double h = -HUGE_VALL; // -inf
	const long double i = NAN; // nan

	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) a, toInt(a), "a");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) b, toInt(b), "b");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) c, toInt(c), "c");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) d, toInt(d), "d");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) e, toInt(e), "e");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) f, toInt(f), "f");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) g, toInt(g), "g");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) h, toInt(h), "h");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((int) i, toInt(i), "i");
}

void test_canCastFloatToUnsignedInt() {
	const float a = +0.0f;
	const float b = -0.0f;
	const float c = +1.0f;
	const float d = -1.0f;
	const float e = FLT_MIN;
	const float f = FLT_MAX;
	const float g = HUGE_VALF; // inf
	const float h = -HUGE_VALF; // -inf
	const float i = NAN; // nan

	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) a, toUInt(a), "a");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) b, toUInt(b), "b");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) c, toUInt(c), "c");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) d, toUInt(d), "d");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) e, toUInt(e), "e");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) f, toUInt(f), "f");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) g, toUInt(g), "g");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) h, toUInt(h), "h");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) i, toUInt(i), "i");
}

void test_canCastDoubleToUnsignedInt() {
	const double a = +0.0;
	const double b = -0.0;
	const double c = +1.0;
	const double d = -1.0;
	const double e = DBL_MIN;
	const double f = DBL_MAX;
	const double g = HUGE_VAL; // inf
	const double h = -HUGE_VAL; // -inf
	const double i = NAN; // nan

	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) a, toUInt(a), "a");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) b, toUInt(b), "b");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) c, toUInt(c), "c");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) d, toUInt(d), "d");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) e, toUInt(e), "e");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) f, toUInt(f), "f");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) g, toUInt(g), "g");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) h, toUInt(h), "h");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) i, toUInt(i), "i");
}

void test_canCastLongDoubleToUnsignedInt() {
	const long double a = +0.0l;
	const long double b = -0.0l;
	const long double c = +1.0l;
	const long double d = -1.0l;
	const long double e = LDBL_MIN;
	const long double f = LDBL_MAX;
	const long double g = HUGE_VALL; // inf
	const long double h = -HUGE_VALL; // -inf
	const long double i = NAN; // nan

	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) a, toUInt(a), "a");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) b, toUInt(b), "b");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) c, toUInt(c), "c");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) d, toUInt(d), "d");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) e, toUInt(e), "e");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) f, toUInt(f), "f");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) g, toUInt(g), "g");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) h, toUInt(h), "h");
	TEST_ASSERT_EQUAL_UINT_MESSAGE((unsigned int) i, toUInt(i), "i");
}

void test_canCastInt2ToFloat2() {
	pointI2_t i_a = int2(1, 2);
	pointF2_t f_a = toFloat(i_a);

	TEST_ASSERT_EQUAL_FLOAT2(float2((float) i_a.x, (float) i_a.y), f_a);
}

void test_canCastInt3ToFloat3() {
	pointI3_t i_a = int3(1, 2, 3);
	pointF3_t f_a = toFloat(i_a);

	TEST_ASSERT_EQUAL_FLOAT3(float3((float) i_a.x, (float) i_a.y, (float) i_a.z), f_a);
}

void test_canCastUInt2ToFloat2() {
	pointU2_t u_a = uint2(1, 2);
	pointF2_t f_a = toFloat(u_a);

	TEST_ASSERT_EQUAL_FLOAT2(float2((float) u_a.x, (float) u_a.y), f_a);
}

void test_canCastUInt3ToFloat3() {
	pointU3_t u_a = uint3(1, 2, 3);
	pointF3_t f_a = toFloat(u_a);

	TEST_ASSERT_EQUAL_FLOAT3(float3((float) u_a.x, (float) u_a.y, (float) u_a.z), f_a);
}

void test_canCastFloat2ToInt2() {
	const pointF2_t f_a = float2(+1.0f, +2.0f);
	const pointF2_t f_b = float2(+1.5f, +2.5f);
	const pointF2_t f_c = float2(-1.0f, -2.0f);
	const pointF2_t f_d = float2(-1.5f, -2.5f);
	const pointI2_t i_a = toInt(f_a);
	const pointI2_t i_b = toInt(f_b);
	const pointI2_t i_c = toInt(f_c);
	const pointI2_t i_d = toInt(f_d);

	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2((signed int) f_a.x, (signed int) f_a.y), i_a, "i_a");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2((signed int) f_b.x, (signed int) f_b.y), i_b, "i_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2((signed int) f_c.x, (signed int) f_c.y), i_c, "i_c");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2((signed int) f_d.x, (signed int) f_d.y), i_d, "i_d");
}

void test_canCastFloat2ToUInt2() {
	const pointF2_t f_a = float2(+1.0f, +2.0f);
	const pointF2_t f_b = float2(+1.5f, +2.5f);
	const pointF2_t f_c = float2(-1.0f, -2.0f);
	const pointF2_t f_d = float2(-1.5f, -2.5f);
	const pointU2_t u_a = toUInt(f_a);
	const pointU2_t u_b = toUInt(f_b);
	const pointU2_t u_c = toUInt(f_c);
	const pointU2_t u_d = toUInt(f_d);

	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2((unsigned int) f_a.x, (unsigned int) f_a.y), u_a, "u_a");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2((unsigned int) f_b.x, (unsigned int) f_b.y), u_b, "u_b");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2((unsigned int) f_c.x, (unsigned int) f_c.y), u_c, "u_c");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2((unsigned int) f_d.x, (unsigned int) f_d.y), u_d, "u_d");
}

void test_canCastFloat3ToInt3() {
	const pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	const pointF3_t f_b = float3(+1.5f, +2.5f, +3.5f);
	const pointF3_t f_c = float3(-1.0f, -2.0f, -3.0f);
	const pointF3_t f_d = float3(-1.5f, -2.5f, -3.5f);
	const pointI3_t i_a = toInt(f_a);
	const pointI3_t i_b = toInt(f_b);
	const pointI3_t i_c = toInt(f_c);
	const pointI3_t i_d = toInt(f_d);

	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3((signed int) f_a.x, (signed int) f_a.y, (signed int) f_a.z), i_a, "i_a");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3((signed int) f_b.x, (signed int) f_b.y, (signed int) f_b.z), i_b, "i_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3((signed int) f_c.x, (signed int) f_c.y, (signed int) f_c.z), i_c, "i_c");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3((signed int) f_d.x, (signed int) f_d.y, (signed int) f_d.z), i_d, "i_d");
}

void test_canCastFloat3ToUInt3() {
	const pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	const pointF3_t f_b = float3(+1.5f, +2.5f, +3.5f);
	const pointF3_t f_c = float3(-1.0f, -2.0f, -3.0f);
	const pointF3_t f_d = float3(-1.5f, -2.5f, -3.5f);
	const pointU3_t u_a = toUInt(f_a);
	const pointU3_t u_b = toUInt(f_b);
	const pointU3_t u_c = toUInt(f_c);
	const pointU3_t u_d = toUInt(f_d);

	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3((unsigned int) f_a.x, (unsigned int) f_a.y, (signed int) f_a.z), u_a, "u_a");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3((unsigned int) f_b.x, (unsigned int) f_b.y, (signed int) f_b.z), u_b, "u_b");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3((unsigned int) f_c.x, (unsigned int) f_c.y, (signed int) f_c.z), u_c, "u_c");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3((unsigned int) f_d.x, (unsigned int) f_d.y, (signed int) f_d.z), u_d, "u_d");
}

void test_canCastSignedByteToUnsignedByte() {
	const signed char a = +0;
	const signed char b = +1;
	const signed char c = -1;
	const signed char d = INT8_MAX;
	const signed char e = INT8_MIN;

	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) a, toUnsigned(a), "a");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) b, toUnsigned(b), "b");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) c, toUnsigned(c), "c");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) d, toUnsigned(d), "d");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) e, toUnsigned(e), "e");
}

void test_canCastByteToUnsignedByte() {
	const char a = +0;
	const char b = +1;
	const char c = -1;
	const char d = INT8_MAX;
	const char e = INT8_MIN;

	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) a, toUnsigned(a), "a");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) b, toUnsigned(b), "b");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) c, toUnsigned(c), "c");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) d, toUnsigned(d), "d");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE((unsigned char) e, toUnsigned(e), "e");
}

void test_canCastSignedShortToUnsignedShort() {
	const signed short a = +0;
	const signed short b = +1;
	const signed short c = -1;
	const signed short d = INT16_MAX;
	const signed short e = INT16_MIN;

	TEST_ASSERT_EQUAL_UINT16_MESSAGE((unsigned short) a, toUnsigned(a), "a");
	TEST_ASSERT_EQUAL_UINT16_MESSAGE((unsigned short) b, toUnsigned(b), "b");
	TEST_ASSERT_EQUAL_UINT16_MESSAGE((unsigned short) c, toUnsigned(c), "c");
	TEST_ASSERT_EQUAL_UINT16_MESSAGE((unsigned short) d, toUnsigned(d), "d");
	TEST_ASSERT_EQUAL_UINT16_MESSAGE((unsigned short) e, toUnsigned(e), "e");
}

void test_canCastSignedIntToUnsignedInt() {
	const signed int a = +0;
	const signed int b = +1;
	const signed int c = -1;
	const signed int d = INT32_MAX;
	const signed int e = INT32_MIN;

	TEST_ASSERT_EQUAL_UINT32_MESSAGE((unsigned int) a, toUnsigned(a), "a");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE((unsigned int) b, toUnsigned(b), "b");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE((unsigned int) c, toUnsigned(c), "c");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE((unsigned int) d, toUnsigned(d), "d");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE((unsigned int) e, toUnsigned(e), "e");
}

void test_canCastSignedLongToUnsignedLong() {
	const signed long a = +0;
	const signed long b = +1;
	const signed long c = -1;
	const signed long d = (long) INT64_MAX;
	const signed long e = (long) INT64_MIN;

	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long) a, toUnsigned(a), "a");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long) b, toUnsigned(b), "b");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long) c, toUnsigned(c), "c");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long) d, toUnsigned(d), "d");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long) e, toUnsigned(e), "e");
}

void test_canCastSignedLongLongToUnsignedLongLong() {
	const signed long long a = +0;
	const signed long long b = +1;
	const signed long long c = -1;
	const signed long long d = INT64_MAX;
	const signed long long e = INT64_MIN;

	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long long) a, toUnsigned(a), "a");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long long) b, toUnsigned(b), "b");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long long) c, toUnsigned(c), "c");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long long) d, toUnsigned(d), "d");
	TEST_ASSERT_EQUAL_UINT64_MESSAGE((unsigned long long) e, toUnsigned(e), "e");
}

void test_canCastInt2ToUInt2() {
	const pointI2_t i_a = int2(+1, +2);
	const pointI2_t i_b = int2(-1, -2);
	const pointU2_t u_a = toUnsigned(i_a);
	const pointU2_t u_b = toUnsigned(i_b);

	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2((unsigned int) i_a.x, (unsigned int) i_a.y), u_a, "u_a");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2((unsigned int) i_b.x, (unsigned int) i_b.y), u_b, "u_b");
}

void test_canCastInt3ToUInt3() {
	const pointI3_t i_a = int3(+1, +2, +3);
	const pointI3_t i_b = int3(-1, -2, -3);
	const pointU3_t u_a = toUnsigned(i_a);
	const pointU3_t u_b = toUnsigned(i_b);

	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3((unsigned int) i_a.x, (unsigned int) i_a.y, (unsigned int) i_a.z), u_a, "u_a");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3((unsigned int) i_b.x, (unsigned int) i_b.y, (unsigned int) i_b.z), u_b, "u_b");
}

void test_canCastUnsignedByteToSignedByte() {
	const unsigned char a = +0;
	const unsigned char b = +1;
	const unsigned char c = -1;
	const unsigned char d = INT8_MAX;
	const unsigned char e = INT8_MIN;
	const unsigned char f = UINT8_MAX;

	TEST_ASSERT_EQUAL_INT8_MESSAGE((signed char) a, toSigned(a), "a");
	TEST_ASSERT_EQUAL_INT8_MESSAGE((signed char) b, toSigned(b), "b");
	TEST_ASSERT_EQUAL_INT8_MESSAGE((signed char) c, toSigned(c), "c");
	TEST_ASSERT_EQUAL_INT8_MESSAGE((signed char) d, toSigned(d), "d");
	TEST_ASSERT_EQUAL_INT8_MESSAGE((signed char) e, toSigned(e), "e");
	TEST_ASSERT_EQUAL_INT8_MESSAGE((signed char) f, toSigned(f), "f");
}

void test_canCastUnsignedShortToSignedShort() {
	const unsigned short a = +0;
	const unsigned short b = +1;
	const unsigned short c = -1;
	const unsigned short d = INT16_MAX;
	const unsigned short e = INT16_MIN;
	const unsigned short f = UINT16_MAX;

	TEST_ASSERT_EQUAL_INT16_MESSAGE((signed short) a, toSigned(a), "a");
	TEST_ASSERT_EQUAL_INT16_MESSAGE((signed short) b, toSigned(b), "b");
	TEST_ASSERT_EQUAL_INT16_MESSAGE((signed short) c, toSigned(c), "c");
	TEST_ASSERT_EQUAL_INT16_MESSAGE((signed short) d, toSigned(d), "d");
	TEST_ASSERT_EQUAL_INT16_MESSAGE((signed short) e, toSigned(e), "e");
	TEST_ASSERT_EQUAL_INT16_MESSAGE((signed short) f, toSigned(f), "f");
}

void test_canCastUnsignedIntToSignedInt() {
	const unsigned int a = +0;
	const unsigned int b = +1;
	const unsigned int c = -1;
	const unsigned int d = INT32_MAX;
	const unsigned int e = INT32_MIN;
	const unsigned int f = UINT32_MAX;

	TEST_ASSERT_EQUAL_INT32_MESSAGE((signed int) a, toSigned(a), "a");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((signed int) b, toSigned(b), "b");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((signed int) c, toSigned(c), "c");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((signed int) d, toSigned(d), "d");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((signed int) e, toSigned(e), "e");
	TEST_ASSERT_EQUAL_INT32_MESSAGE((signed int) f, toSigned(f), "f");
}

void test_canCastUnsignedLongToSignedLong() {
	const unsigned long a = +0;
	const unsigned long b = +1;
	const unsigned long c = -1;
	const unsigned long d = (long) INT64_MAX;
	const unsigned long e = (long) INT64_MIN;
	const unsigned long f = (long) UINT64_MAX;

	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long) a, toSigned(a), "a");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long) b, toSigned(b), "b");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long) c, toSigned(c), "c");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long) d, toSigned(d), "d");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long) e, toSigned(e), "e");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long) f, toSigned(f), "f");
}

void test_canCastUnsignedLongLongToSignedLongLong() {
	const unsigned long long a = +0;
	const unsigned long long b = +1;
	const unsigned long long c = -1;
	const unsigned long long d = INT64_MAX;
	const unsigned long long e = INT64_MIN;
	const unsigned long long f = UINT64_MAX;

	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long long) a, toSigned(a), "a");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long long) b, toSigned(b), "b");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long long) c, toSigned(c), "c");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long long) d, toSigned(d), "d");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long long) e, toSigned(e), "e");
	TEST_ASSERT_EQUAL_INT64_MESSAGE((signed long long) f, toSigned(f), "f");
}

void test_canCastUInt2ToInt2() {
	const pointU2_t u_a = uint2(1, 2);
	const pointI2_t i_a = toSigned(u_a);

	TEST_ASSERT_EQUAL_INT2(int2((signed int) u_a.x, (signed int) u_a.y), i_a);
}

void test_canCastUInt3ToInt3() {
	const pointU3_t u_a = uint3(1, 2, 3);
	const pointI3_t i_a = toSigned(u_a);

	TEST_ASSERT_EQUAL_INT3(int3((signed int) u_a.x, (signed int) u_a.y, (signed int) u_a.z), i_a);
}

void test_canCastInt2ToString() {
	const pointI2_t i_a = int2(+0, +0);
	const pointI2_t i_b = int2(+1, +2);
	const pointI2_t i_c = int2(-1, -2);
	const pointI2_t i_d = int2(INT32_MAX, INT32_MIN);

	TEST_ASSERT_EQUAL_STRING_MESSAGE("(0, 0)", toString(i_a), "i_a");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1, 2)", toString(i_b), "i_b");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-1, -2)", toString(i_c), "i_c");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(2147483647, -2147483648)", toString(i_d), "i_d");
}

void test_canCastUInt2ToString() {
	const pointU2_t u_a = uint2(+0, +0);
	const pointU2_t u_b = uint2(+1, +2);
	const pointU2_t u_c = uint2(-1, -2);
	const pointU2_t u_d = uint2(INT32_MAX, INT32_MIN);
	const pointU2_t u_e = uint2(UINT32_MAX, UINT32_MAX);

	TEST_ASSERT_EQUAL_STRING_MESSAGE("(0, 0)", toString(u_a), "u_a");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1, 2)", toString(u_b), "u_b");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(4294967295, 4294967294)", toString(u_c), "u_c");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(2147483647, 2147483648)", toString(u_d), "u_d");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(4294967295, 4294967295)", toString(u_e), "u_e");
}

void test_canCastFloat2ToString() {
	const pointF2_t f_a = float2(+0.0f, +0.0f);
	const pointF2_t f_b = float2(-0.0f, -0.0f);
	const pointF2_t f_c = float2(+1.0f, +2.0f);
	const pointF2_t f_d = float2(-1.0f, -2.0f);
	const pointF2_t f_e = float2(+1.5f, +2.5f);
	const pointF2_t f_f = float2(-1.5f, -2.5f);
	const pointF2_t f_g = float2(FLT_MIN, FLT_MAX);
	const pointF2_t f_h = float2(HUGE_VALF, -HUGE_VALF);
	const pointF2_t f_i = float2(NAN, NAN);

	TEST_ASSERT_EQUAL_STRING_MESSAGE("(0.00000, 0.00000)", toString(f_a), "f_a");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-0.00000, -0.00000)", toString(f_b), "f_b");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1.00000, 2.00000)", toString(f_c), "f_c");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-1.00000, -2.00000)", toString(f_d), "f_d");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1.50000, 2.50000)", toString(f_e), "f_e");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-1.50000, -2.50000)", toString(f_f), "f_f");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1.17549e-38, 3.40282e+38)", toString(f_g), "f_g");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(inf, -inf)", toString(f_h), "f_h");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(nan, nan)", toString(f_i), "f_i");
}

void test_canCastInt3ToString() {
	const pointI3_t i_a = int3(+0, +0, +0);
	const pointI3_t i_b = int3(+1, +2, +3);
	const pointI3_t i_c = int3(-1, -2, -3);
	const pointI3_t i_d = int3(INT32_MAX, INT32_MIN, INT32_MAX);

	TEST_ASSERT_EQUAL_STRING_MESSAGE("(0, 0, 0)", toString(i_a), "i_a");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1, 2, 3)", toString(i_b), "i_b");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-1, -2, -3)", toString(i_c), "i_c");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(2147483647, -2147483648, 2147483647)", toString(i_d), "i_d");
}

void test_canCastUInt3ToString() {
	const pointU3_t u_a = uint3(+0, +0, +0);
	const pointU3_t u_b = uint3(+1, +2, +3);
	const pointU3_t u_c = uint3(-1, -2, -3);
	const pointU3_t u_d = uint3(INT32_MAX, INT32_MIN, INT32_MAX);
	const pointU3_t u_e = uint3(UINT32_MAX, UINT32_MAX, UINT32_MAX);

	TEST_ASSERT_EQUAL_STRING_MESSAGE("(0, 0, 0)", toString(u_a), "u_a");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1, 2, 3)", toString(u_b), "u_b");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(4294967295, 4294967294, 4294967293)", toString(u_c), "u_c");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(2147483647, 2147483648, 2147483647)", toString(u_d), "u_d");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(4294967295, 4294967295, 4294967295)", toString(u_e), "u_e");
}

void test_canCastFloat3ToString() {
	const pointF3_t f_a = float3(+0.0f, +0.0f, +0.0f);
	const pointF3_t f_b = float3(-0.0f, -0.0f, -0.0f);
	const pointF3_t f_c = float3(+1.0f, +2.0f, +3.0f);
	const pointF3_t f_d = float3(-1.0f, -2.0f, -3.0f);
	const pointF3_t f_e = float3(+1.5f, +2.5f, +3.5f);
	const pointF3_t f_f = float3(-1.5f, -2.5f, -3.5f);
	const pointF3_t f_g = float3(FLT_MIN, FLT_MAX, FLT_EPSILON);
	const pointF3_t f_h = float3(HUGE_VALF, -HUGE_VALF, NAN);

	TEST_ASSERT_EQUAL_STRING_MESSAGE("(0.00000, 0.00000, 0.00000)", toString(f_a), "f_a");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-0.00000, -0.00000, -0.00000)", toString(f_b), "f_b");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1.00000, 2.00000, 3.00000)", toString(f_c), "f_c");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-1.00000, -2.00000, -3.00000)", toString(f_d), "f_d");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1.50000, 2.50000, 3.50000)", toString(f_e), "f_e");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(-1.50000, -2.50000, -3.50000)", toString(f_f), "f_f");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(1.17549e-38, 3.40282e+38, 1.19209e-07)", toString(f_g), "f_g");
	TEST_ASSERT_EQUAL_STRING_MESSAGE("(inf, -inf, nan)", toString(f_h), "f_h");
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_canCastWithoutPointIncluded);
	RUN_TEST(test_canCastWithPointIncluded);

	RUN_TEST(test_canCastSignedByteToFloat);
	RUN_TEST(test_canCastByteToFloat);
	RUN_TEST(test_canCastUnsignedByteToFloat);
	RUN_TEST(test_canCastSignedShortToFloat);
	RUN_TEST(test_canCastUnsignedShortToFloat);
	RUN_TEST(test_canCastSignedIntToFloat);
	RUN_TEST(test_canCastUnsignedIntToFloat);
	RUN_TEST(test_canCastSignedLongToFloat);
	RUN_TEST(test_canCastUnsignedLongToFloat);
	RUN_TEST(test_canCastSignedLongLongToFloat);
	RUN_TEST(test_canCastUnsignedLongLongToFloat);

	RUN_TEST(test_canCastFloatToInt);
	RUN_TEST(test_canCastDoubleToInt);
	RUN_TEST(test_canCastLongDoubleToInt);
	RUN_TEST(test_canCastFloatToUnsignedInt);
	RUN_TEST(test_canCastDoubleToUnsignedInt);
	RUN_TEST(test_canCastLongDoubleToUnsignedInt);

	RUN_TEST(test_canCastInt2ToFloat2);
	RUN_TEST(test_canCastUInt2ToFloat2);
	RUN_TEST(test_canCastInt3ToFloat3);
	RUN_TEST(test_canCastUInt3ToFloat3);
	RUN_TEST(test_canCastFloat2ToInt2);
	RUN_TEST(test_canCastFloat2ToUInt2);
	RUN_TEST(test_canCastFloat3ToInt3);
	RUN_TEST(test_canCastFloat3ToUInt3);

	RUN_TEST(test_canCastSignedByteToUnsignedByte);
	RUN_TEST(test_canCastByteToUnsignedByte);
	RUN_TEST(test_canCastSignedShortToUnsignedShort);
	RUN_TEST(test_canCastSignedIntToUnsignedInt);
	RUN_TEST(test_canCastSignedLongToUnsignedLong);
	RUN_TEST(test_canCastSignedLongLongToUnsignedLongLong);
	RUN_TEST(test_canCastInt2ToUInt2);
	RUN_TEST(test_canCastInt3ToUInt3);

	RUN_TEST(test_canCastUnsignedByteToSignedByte);
	RUN_TEST(test_canCastUnsignedShortToSignedShort);
	RUN_TEST(test_canCastUnsignedIntToSignedInt);
	RUN_TEST(test_canCastUnsignedLongToSignedLong);
	RUN_TEST(test_canCastUnsignedLongLongToSignedLongLong);
	RUN_TEST(test_canCastUInt2ToInt2);
	RUN_TEST(test_canCastUInt3ToInt3);

	RUN_TEST(test_canCastInt2ToString);
	RUN_TEST(test_canCastUInt2ToString);
	RUN_TEST(test_canCastFloat2ToString);
	RUN_TEST(test_canCastInt3ToString);
	RUN_TEST(test_canCastUInt3ToString);
	RUN_TEST(test_canCastFloat3ToString);

	return UNITY_END();
}
#include "point.h"

#include "unity_wrapper.h"

// included to prevent compilation error in some cases
void setUp() {}
void tearDown() {}

void test_canConstructInt2() {
	pointI2_t i_a = int2(1, 2);

	TEST_ASSERT_EQUAL_INT32_MESSAGE(1, i_a.x, "i_a.x");
	TEST_ASSERT_EQUAL_INT32_MESSAGE(2, i_a.y, "i_a.y");
}

void test_canConstructUInt2() {
	pointU2_t u_a = uint2(1, 2);

	TEST_ASSERT_EQUAL_UINT32_MESSAGE(1, u_a.x, "u_a.x");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(2, u_a.y, "u_a.y");
}

void test_canConstructFloat2() {
	pointF2_t f_a = float2(1.0f, 2.0f);

	TEST_ASSERT_EQUAL_MESSAGE(1.0f, f_a.x, "f_a.x");
	TEST_ASSERT_EQUAL_MESSAGE(2.0f, f_a.y, "f_a.y");
}

void test_canConstructInt3() {
	pointI3_t i_a = int3(1, 2, 3);

	TEST_ASSERT_EQUAL_INT32_MESSAGE(1, i_a.x, "i_a.x");
	TEST_ASSERT_EQUAL_INT32_MESSAGE(2, i_a.y, "i_a.y");
	TEST_ASSERT_EQUAL_INT32_MESSAGE(3, i_a.z, "i_a.z");
}

void test_canConstructUInt3() {
	pointU3_t u_a = uint3(1, 2, 3);

	TEST_ASSERT_EQUAL_UINT32_MESSAGE(1, u_a.x, "u_a.x");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(2, u_a.y, "u_a.y");
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(3, u_a.z, "u_a.z");
}

void test_canConstructFloat3() {
	pointF3_t f_a = float3(1.0f, 2.0f, 3.0f);

	TEST_ASSERT_EQUAL_MESSAGE(1.0f, f_a.x, "f_a.x");
	TEST_ASSERT_EQUAL_MESSAGE(2.0f, f_a.y, "f_a.y");
	TEST_ASSERT_EQUAL_MESSAGE(3.0f, f_a.z, "f_a.z");
}

void test_canAddF2F2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + +1.0f, +2.0f + +2.0f), addF2F2(f_a, f_a), "f_a + f_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + -1.0f, +2.0f + -2.0f), addF2F2(f_a, f_b), "f_a + f_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + +0.0f, +2.0f + +0.0f), addF2F2(f_a, f_c), "f_a + f_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + +0.5f, +2.0f + -0.5f), addF2F2(f_a, f_d), "f_a + f_d");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f + -1.0f, -2.0f + -2.0f), addF2F2(f_b, f_b), "f_b + f_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.5f + +0.5f, -0.5f + -0.5f), addF2F2(f_d, f_d), "f_d + f_d");
}

void test_canAddF3F3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + +1.0f, +2.0f + +2.0f, +3.0f + +3.0f), addF3F3(f_a, f_a), "f_a + f_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + -1.0f, +2.0f + -2.0f, +3.0f + -3.0f), addF3F3(f_a, f_b), "f_a + f_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + +0.0f, +2.0f + +0.0f, +3.0f + +0.0f), addF3F3(f_a, f_c), "f_a + f_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + +0.5f, +2.0f + -0.5f, +3.0f + +0.5f), addF3F3(f_a, f_d), "f_a + f_d");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f + -1.0f, -2.0f + -2.0f, -3.0f + -3.0f), addF3F3(f_b, f_b), "f_b + f_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.5f + +0.5f, -0.5f + -0.5f, +0.5f + +0.5f), addF3F3(f_d, f_d), "f_d + f_d");
}

void test_canAddI2I2() {
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);

	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 + +1, +2 + +2), addI2I2(i_a, i_a), "i_a + i_a");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 + -1, +2 + -2), addI2I2(i_a, i_b), "i_a + i_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 + +0, +2 + +0), addI2I2(i_a, i_c), "i_a + i_c");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(-1 + -1, -2 + -2), addI2I2(i_b, i_b), "i_b + i_b");
}

void test_canAddI3I3() {
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);

	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 + +1, +2 + +2, +3 + +3), addI3I3(i_a, i_a), "i_a + i_a");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 + -1, +2 + -2, +3 + -3), addI3I3(i_a, i_b), "i_a + i_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 + +0, +2 + +0, +3 + +0), addI3I3(i_a, i_c), "i_a + i_c");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(-1 + -1, -2 + -2, -3 + -3), addI3I3(i_b, i_b), "i_b + i_b");
}

void test_canAddU2U2() {
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 + +1, +2 + +2), addU2U2(u_a, u_a), "u_a + u_a");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 + -1, +2 + -2), addU2U2(u_a, u_b), "u_a + u_b");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 + +0, +2 + +0), addU2U2(u_a, u_c), "u_a + u_c");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(-1 + -1, -2 + -2), addU2U2(u_b, u_b), "u_b + u_b");
}

void test_canAddU3U3() {
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 + +1, +2 + +2, +3 + +3), addU3U3(u_a, u_a), "u_a + u_a");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 + -1, +2 + -2, +3 + -3), addU3U3(u_a, u_b), "u_a + u_b");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 + +0, +2 + +0, +3 + +0), addU3U3(u_a, u_c), "u_a + u_c");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(-1 + -1, -2 + -2, -3 + -3), addU3U3(u_b, u_b), "u_b + u_b");
}

void test_canAddF2I2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + +1, +2.0f + +2), addF2I2(f_a, i_a), "f_a + i_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f + -1, -2.0f + -2), addF2I2(f_b, i_b), "f_b + i_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.0f + +0, +0.0f + +0), addF2I2(f_c, i_c), "f_c + i_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.5f + +1, -0.5f + +2), addF2I2(f_d, i_a), "f_d + i_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + -1, +2.0f + -2), addF2I2(f_a, i_b), "f_a + i_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f + +1, -2.0f + +2), addF2I2(f_b, i_a), "f_b + i_a");
}

void test_canAddF3I3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + +1, +2.0f + +2, +3.0f + +3), addF3I3(f_a, i_a), "f_a + i_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f + -1, -2.0f + -2, -3.0f + -3), addF3I3(f_b, i_b), "f_b + i_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.0f + +0, +0.0f + +0, +0.0f + +0), addF3I3(f_c, i_c), "f_c + i_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.5f + +1, -0.5f + +2, +0.5f + +3), addF3I3(f_d, i_a), "f_d + i_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + -1, +2.0f + -2, +3.0f + -3), addF3I3(f_a, i_b), "f_a + i_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f + +1, -2.0f + +2, -3.0f + +3), addF3I3(f_b, i_a), "f_b + i_a");
}

void test_canAddF2U2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + +1, +2.0f + +2), addF2U2(f_a, u_a), "f_a + u_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f + n1, -2.0f + n2), addF2U2(f_b, u_b), "f_b + u_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.0f + +0, +0.0f + +0), addF2U2(f_c, u_c), "f_c + u_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.5f + +1, -0.5f + +2), addF2U2(f_d, u_a), "f_d + u_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f + n1, +2.0f + n2), addF2U2(f_a, u_b), "f_a + u_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f + +1, -2.0f + +2), addF2U2(f_b, u_a), "f_b + u_a");
}

void test_canAddF3U3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;
	unsigned int n3 = -3;

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + +1, +2.0f + +2, +3.0f + +3), addF3U3(f_a, u_a), "f_a + u_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f + n1, -2.0f + n2, -3.0f + n3), addF3U3(f_b, u_b), "f_b + u_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.0f + +0, +0.0f + +0, +0.0f + +0), addF3U3(f_c, u_c), "f_c + u_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.5f + +1, -0.5f + +2, +0.5f + +3), addF3U3(f_d, u_a), "f_d + u_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f + n1, +2.0f + n2, +3.0f + n3), addF3U3(f_a, u_b), "f_a + u_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f + +1, -2.0f + +2, -3.0f + +3), addF3U3(f_b, u_a), "f_b + u_a");
}

void test_canAddI2U2() {
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;

	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 + +1, +2 + +2), addI2U2(i_a, u_a), "i_a + u_a");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(-1 + n1, -2 + n2), addI2U2(i_b, u_b), "i_b + u_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+0 + +0, +0 + +0), addI2U2(i_c, u_c), "i_c + u_c");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 + n1, +2 + n2), addI2U2(i_a, u_b), "i_a + u_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(-1 + +1, -2 + +2), addI2U2(i_b, u_a), "i_b + u_a");
}

void test_canAddI3U3() {
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;
	unsigned int n3 = -3;

	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 + +1, +2 + +2, +3 + +3), addI3U3(i_a, u_a), "i_a + u_a");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(-1 + n1, -2 + n2, -3 + n3), addI3U3(i_b, u_b), "i_b + u_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+0 + +0, +0 + +0, +0 + +0), addI3U3(i_c, u_c), "i_c + u_c");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 + n1, +2 + n2, +3 + n3), addI3U3(i_a, u_b), "i_a + u_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(-1 + +1, -2 + +2, -3 + +3), addI3U3(i_b, u_a), "i_b + u_a");
}

void test_canSubtractF2F2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - +1.0f, +2.0f - +2.0f), subF2F2(f_a, f_a), "f_a - f_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - -1.0f, +2.0f - -2.0f), subF2F2(f_a, f_b), "f_a - f_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - +0.0f, +2.0f - +0.0f), subF2F2(f_a, f_c), "f_a - f_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - +0.5f, +2.0f - -0.5f), subF2F2(f_a, f_d), "f_a - f_d");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f - -1.0f, -2.0f - -2.0f), subF2F2(f_b, f_b), "f_b - f_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.5f - +0.5f, -0.5f - -0.5f), subF2F2(f_d, f_d), "f_d - f_d");
}

void test_canSubtractF3F3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - +1.0f, +2.0f - +2.0f, +3.0f - +3.0f), subF3F3(f_a, f_a), "f_a - f_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - -1.0f, +2.0f - -2.0f, +3.0f - -3.0f), subF3F3(f_a, f_b), "f_a - f_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - +0.0f, +2.0f - +0.0f, +3.0f - +0.0f), subF3F3(f_a, f_c), "f_a - f_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - +0.5f, +2.0f - -0.5f, +3.0f - +0.5f), subF3F3(f_a, f_d), "f_a - f_d");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f - -1.0f, -2.0f - -2.0f, -3.0f - -3.0f), subF3F3(f_b, f_b), "f_b - f_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.5f - +0.5f, -0.5f - -0.5f, +0.5f - +0.5f), subF3F3(f_d, f_d), "f_d - f_d");
}

void test_canSubtractI2I2() {
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);

	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 - +1, +2 - +2), subI2I2(i_a, i_a), "i_a - i_a");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 - -1, +2 - -2), subI2I2(i_a, i_b), "i_a - i_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 - +0, +2 - +0), subI2I2(i_a, i_c), "i_a - i_c");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(-1 - -1, -2 - -2), subI2I2(i_b, i_b), "i_b - i_b");
}

void test_canSubtractI3I3() {
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);

	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 - +1, +2 - +2, +3 - +3), subI3I3(i_a, i_a), "i_a - i_a");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 - -1, +2 - -2, +3 - -3), subI3I3(i_a, i_b), "i_a - i_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 - +0, +2 - +0, +3 - +0), subI3I3(i_a, i_c), "i_a - i_c");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(-1 - -1, -2 - -2, -3 - -3), subI3I3(i_b, i_b), "i_b - i_b");
}

void test_canSubtractU2U2() {
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 - +1, +2 - +2), subU2U2(u_a, u_a), "u_a - u_a");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 - -1, +2 - -2), subU2U2(u_a, u_b), "u_a - u_b");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 - +0, +2 - +0), subU2U2(u_a, u_c), "u_a - u_c");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(-1 - -1, -2 - -2), subU2U2(u_b, u_b), "u_b - u_b");
}

void test_canSubtractU3U3() {
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 - +1, +2 - +2, +3 - +3), subU3U3(u_a, u_a), "u_a - u_a");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 - -1, +2 - -2, +3 - -3), subU3U3(u_a, u_b), "u_a - u_b");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 - +0, +2 - +0, +3 - +0), subU3U3(u_a, u_c), "u_a - u_c");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(-1 - -1, -2 - -2, -3 - -3), subU3U3(u_b, u_b), "u_b - u_b");
}

void test_canSubtractF2I2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - +1, +2.0f - +2), subF2I2(f_a, i_a), "f_a - i_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f - -1, -2.0f - -2), subF2I2(f_b, i_b), "f_b - i_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.0f - +0, +0.0f - +0), subF2I2(f_c, i_c), "f_c - i_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.5f - +1, -0.5f - +2), subF2I2(f_d, i_a), "f_d - i_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - -1, +2.0f - -2), subF2I2(f_a, i_b), "f_a - i_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f - +1, -2.0f - +2), subF2I2(f_b, i_a), "f_b - i_a");
}

void test_canSubtractF3I3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - +1, +2.0f - +2, +3.0f - +3), subF3I3(f_a, i_a), "f_a - i_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f - -1, -2.0f - -2, -3.0f - -3), subF3I3(f_b, i_b), "f_b - i_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.0f - +0, +0.0f - +0, +0.0f - +0), subF3I3(f_c, i_c), "f_c - i_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.5f - +1, -0.5f - +2, +0.5f - +3), subF3I3(f_d, i_a), "f_d - i_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - -1, +2.0f - -2, +3.0f - -3), subF3I3(f_a, i_b), "f_a - i_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f - +1, -2.0f - +2, -3.0f - +3), subF3I3(f_b, i_a), "f_b - i_a");
}

void test_canSubtractI2F2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1 - +1.0f, +2 - +2.0f), subI2F2(i_a, f_a), "i_a - f_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1 - -1.0f, -2 - -2.0f), subI2F2(i_b, f_b), "i_b - f_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0 - +0.0f, +0 - +0.0f), subI2F2(i_c, f_c), "i_c - f_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1 - +0.5f, +2 - -0.5f), subI2F2(i_a, f_d), "i_a - f_d");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1 - +1.0f, -2 - +2.0f), subI2F2(i_b, f_a), "i_b - f_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1 - -1.0f, +2 - -2.0f), subI2F2(i_a, f_b), "i_a - f_b");
}

void test_canSubtractI3F3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1 - +1.0f, +2 - +2.0f, +3 - +3.0f), subI3F3(i_a, f_a), "i_a - f_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1 - -1.0f, -2 - -2.0f, -3 - -3.0f), subI3F3(i_b, f_b), "i_b - f_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0 - +0.0f, +0 - +0.0f, +0 - +0.0f), subI3F3(i_c, f_c), "i_c - f_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1 - +0.5f, +2 - -0.5f, +3 - +0.5f), subI3F3(i_a, f_d), "i_a - f_d");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1 - +1.0f, -2 - +2.0f, -3 - +3.0f), subI3F3(i_b, f_a), "i_b - f_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1 - -1.0f, +2 - -2.0f, +3 - -3.0f), subI3F3(i_a, f_b), "i_a - f_b");
}

void test_canSubtractU2I2() {
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;

	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 - +1, +2 - +2), subU2I2(u_a, i_a), "u_a + i_a");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(-1 - n1, -2 - n2), subU2I2(u_b, i_b), "u_b + i_b");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+0 - +0, +0 - +0), subU2I2(u_c, i_c), "u_c + i_c");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(+1 - n1, +2 - n2), subU2I2(u_a, i_b), "u_a + i_b");
	TEST_ASSERT_EQUAL_UINT2_MESSAGE(uint2(-1 - +1, -2 - +2), subU2I2(u_b, i_a), "u_b + i_a");
}

void test_canSubtractU3I3() {
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;
	unsigned int n3 = -3;

	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 - +1, +2 - +2, +3 - +3), subU3I3(u_a, i_a), "u_a + i_a");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(-1 - n1, -2 - n2, -3 - n3), subU3I3(u_b, i_b), "u_b + i_b");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+0 - +0, +0 - +0, +0 - +0), subU3I3(u_c, i_c), "u_c + i_c");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(+1 - n1, +2 - n2, +3 - n3), subU3I3(u_a, i_b), "u_a + i_b");
	TEST_ASSERT_EQUAL_UINT3_MESSAGE(uint3(-1 - +1, -2 - +2, -3 - +3), subU3I3(u_b, i_a), "u_b + i_a");
}

void test_canSubtractI2U2() {
	pointI2_t i_a = int2(+1, +2);
	pointI2_t i_b = int2(-1, -2);
	pointI2_t i_c = int2(+0, +0);
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 - +1, +2 - +2), subI2U2(i_a, u_a), "i_a + u_a");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(-1 - -1, -2 - -2), subI2U2(i_b, u_b), "i_b + u_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+0 - +0, +0 - +0), subI2U2(i_c, u_c), "i_c + u_c");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(+1 - -1, +2 - -2), subI2U2(i_a, u_b), "i_a + u_b");
	TEST_ASSERT_EQUAL_INT2_MESSAGE(int2(-1 - +1, -2 - +2), subI2U2(i_b, u_a), "i_b + u_a");
}

void test_canSubtractI3U3() {
	pointI3_t i_a = int3(+1, +2, +3);
	pointI3_t i_b = int3(-1, -2, -3);
	pointI3_t i_c = int3(+0, +0, +0);
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 - +1, +2 - +2, +3 - +3), subI3U3(i_a, u_a), "u_a + i_a");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(-1 - -1, -2 - -2, -3 - -3), subI3U3(i_b, u_b), "u_b + i_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+0 - +0, +0 - +0, +0 - +0), subI3U3(i_c, u_c), "u_c + i_c");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(+1 - -1, +2 - -2, +3 - -3), subI3U3(i_a, u_b), "u_a + i_b");
	TEST_ASSERT_EQUAL_INT3_MESSAGE(int3(-1 - +1, -2 - +2, -3 - +3), subI3U3(i_b, u_a), "u_b + i_a");
}

void test_canSubtractF2U2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - +1, +2.0f - +2), subF2U2(f_a, u_a), "f_a - u_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f - n1, -2.0f - n2), subF2U2(f_b, u_b), "f_b - u_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.0f - +0, +0.0f - +0), subF2U2(f_c, u_c), "f_c - u_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0.5f - +1, -0.5f - +2), subF2U2(f_d, u_a), "f_d - u_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1.0f - n1, +2.0f - n2), subF2U2(f_a, u_b), "f_a - u_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(-1.0f - +1, -2.0f - +2), subF2U2(f_b, u_a), "f_b - u_a");
}

void test_canSubtractF3U3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;
	unsigned int n3 = -3;

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - +1, +2.0f - +2, +3.0f - +3), subF3U3(f_a, u_a), "f_a - u_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f - n1, -2.0f - n2, -3.0f - n3), subF3U3(f_b, u_b), "f_b - u_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.0f - +0, +0.0f - +0, +0.0f - +0), subF3U3(f_c, u_c), "f_c - u_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0.5f - +1, -0.5f - +2, +0.5f - +3), subF3U3(f_d, u_a), "f_d - u_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1.0f - n1, +2.0f - n2, +3.0f - n3), subF3U3(f_a, u_b), "f_a - u_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(-1.0f - +1, -2.0f - +2, -3.0f - +3), subF3U3(f_b, u_a), "f_b - u_a");
}

void test_canSubtractU2F2() {
	pointF2_t f_a = float2(+1.0f, +2.0f);
	pointF2_t f_b = float2(-1.0f, -2.0f);
	pointF2_t f_c = float2(+0.0f, +0.0f);
	pointF2_t f_d = float2(+0.5f, -0.5f);
	pointU2_t u_a = uint2(+1, +2);
	pointU2_t u_b = uint2(-1, -2);
	pointU2_t u_c = uint2(+0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;

	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1 - +1.0f, +2 - +2.0f), subU2F2(u_a, f_a), "u_a - f_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(n1 - -1.0f, n2 - -2.0f), subU2F2(u_b, f_b), "u_b - f_b");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+0 - +0.0f, +0 - +0.0f), subU2F2(u_c, f_c), "u_c - f_c");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1 - +0.5f, +2 - -0.5f), subU2F2(u_a, f_d), "u_a - f_d");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(n1 - +1.0f, n2 - +2.0f), subU2F2(u_b, f_a), "u_b - f_a");
	TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(float2(+1 - -1.0f, +2 - -2.0f), subU2F2(u_a, f_b), "u_a - f_b");
}

void test_canSubtractU3F3() {
	pointF3_t f_a = float3(+1.0f, +2.0f, +3.0f);
	pointF3_t f_b = float3(-1.0f, -2.0f, -3.0f);
	pointF3_t f_c = float3(+0.0f, +0.0f, +0.0f);
	pointF3_t f_d = float3(+0.5f, -0.5f, +0.5f);
	pointU3_t u_a = uint3(+1, +2, +3);
	pointU3_t u_b = uint3(-1, -2, -3);
	pointU3_t u_c = uint3(+0, +0, +0);

	unsigned int n1 = -1;
	unsigned int n2 = -2;
	unsigned int n3 = -3;

	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1 - +1.0f, +2 - +2.0f, +3 - +3.0f), subU3F3(u_a, f_a), "u_a - f_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(n1 - -1.0f, n2 - -2.0f, n3 - -3.0f), subU3F3(u_b, f_b), "u_b - f_b");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+0 - +0.0f, +0 - +0.0f, +0 - +0.0f), subU3F3(u_c, f_c), "u_c - f_c");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1 - +0.5f, +2 - -0.5f, +3 - +0.5f), subU3F3(u_a, f_d), "u_a - f_d");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(n1 - +1.0f, n2 - +2.0f, n3 - +3.0f), subU3F3(u_b, f_a), "u_b - f_a");
	TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(float3(+1 - -1.0f, +2 - -2.0f, +3 - -3.0f), subU3F3(u_a, f_b), "u_a - f_b");
}

int main() {
	UNITY_BEGIN();

	RUN_TEST(test_canConstructInt2);
	RUN_TEST(test_canConstructUInt2);
	RUN_TEST(test_canConstructFloat2);
	RUN_TEST(test_canConstructInt3);
	RUN_TEST(test_canConstructUInt3);
	RUN_TEST(test_canConstructFloat3);

	RUN_TEST(test_canAddF2F2);
	RUN_TEST(test_canAddF3F3);
	RUN_TEST(test_canAddI2I2);
	RUN_TEST(test_canAddI3I3);
	RUN_TEST(test_canAddU2U2);
	RUN_TEST(test_canAddU3U3);

	RUN_TEST(test_canAddF2I2);
	RUN_TEST(test_canAddF3I3);
	RUN_TEST(test_canAddF2U2);
	RUN_TEST(test_canAddF3U3);

	RUN_TEST(test_canAddI2U2);
	RUN_TEST(test_canAddI3U3);

	RUN_TEST(test_canSubtractF2F2);
	RUN_TEST(test_canSubtractF3F3);
	RUN_TEST(test_canSubtractI2I2);
	RUN_TEST(test_canSubtractI3I3);
	RUN_TEST(test_canSubtractU2U2);
	RUN_TEST(test_canSubtractU3U3);

	RUN_TEST(test_canSubtractF2I2);
	RUN_TEST(test_canSubtractF3I3);
	RUN_TEST(test_canSubtractI2F2);
	RUN_TEST(test_canSubtractI3F3);

	RUN_TEST(test_canSubtractU2I2);
	RUN_TEST(test_canSubtractU3I3);
	RUN_TEST(test_canSubtractI2U2);
	RUN_TEST(test_canSubtractI3U3);

	RUN_TEST(test_canSubtractF2U2);
	RUN_TEST(test_canSubtractF3U3);
	RUN_TEST(test_canSubtractU2F2);
	RUN_TEST(test_canSubtractU3F3);

	return UNITY_END();
}
#include "unity.h"

#define TEST_ASSERT_EQUAL_INT2_MESSAGE(expected, actual, message) ({   \
	pointI2_t _expected = (expected);                                  \
	pointI2_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_INT32_MESSAGE(_expected.x, _actual.x, message);  \
	TEST_ASSERT_EQUAL_INT32_MESSAGE(_expected.y, _actual.y, message);  \
})

#define TEST_ASSERT_EQUAL_INT3_MESSAGE(expected, actual, message) ({   \
	pointI3_t _expected = (expected);                                  \
	pointI3_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_INT32_MESSAGE(_expected.x, _actual.x, message);  \
	TEST_ASSERT_EQUAL_INT32_MESSAGE(_expected.y, _actual.y, message);  \
	TEST_ASSERT_EQUAL_INT32_MESSAGE(_expected.z, _actual.z, message);  \
})

#define TEST_ASSERT_EQUAL_UINT2_MESSAGE(expected, actual, message) ({  \
	pointU2_t _expected = (expected);                                  \
	pointU2_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(_expected.x, _actual.x, message); \
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(_expected.y, _actual.y, message); \
})

#define TEST_ASSERT_EQUAL_UINT3_MESSAGE(expected, actual, message) ({  \
	pointU3_t _expected = (expected);                                  \
	pointU3_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(_expected.x, _actual.x, message); \
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(_expected.y, _actual.y, message); \
	TEST_ASSERT_EQUAL_UINT32_MESSAGE(_expected.z, _actual.z, message); \
})

#define TEST_ASSERT_EQUAL_FLOAT2_MESSAGE(expected, actual, message) ({ \
	pointF2_t _expected = (expected);                                  \
	pointF2_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_MESSAGE(_expected.x, _actual.x, message);        \
	TEST_ASSERT_EQUAL_MESSAGE(_expected.y, _actual.y, message);        \
})

#define TEST_ASSERT_EQUAL_FLOAT3_MESSAGE(expected, actual, message) ({ \
	pointF3_t _expected = (expected);                                  \
	pointF3_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_MESSAGE(_expected.x, _actual.x, message);        \
	TEST_ASSERT_EQUAL_MESSAGE(_expected.y, _actual.y, message);        \
	TEST_ASSERT_EQUAL_MESSAGE(_expected.z, _actual.z, message);        \
})

#define TEST_ASSERT_EQUAL_INT2(expected, actual) ({                    \
	pointI2_t _expected = (expected);                                  \
	pointI2_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_INT32(_expected.x, _actual.x);                   \
	TEST_ASSERT_EQUAL_INT32(_expected.y, _actual.y);                   \
})

#define TEST_ASSERT_EQUAL_INT3(expected, actual) ({                    \
	pointI3_t _expected = (expected);                                  \
	pointI3_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_INT32(_expected.x, _actual.x);                   \
	TEST_ASSERT_EQUAL_INT32(_expected.y, _actual.y);                   \
	TEST_ASSERT_EQUAL_INT32(_expected.z, _actual.z);                   \
})

#define TEST_ASSERT_EQUAL_UINT2(expected, actual) ({                   \
	pointU2_t _expected = (expected);                                  \
	pointU2_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_UINT32(_expected.x, _actual.x);                  \
	TEST_ASSERT_EQUAL_UINT32(_expected.y, _actual.y);                  \
})

#define TEST_ASSERT_EQUAL_UINT3(expected, actual) ({                   \
	pointU3_t _expected = (expected);                                  \
	pointU3_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL_UINT32(_expected.x, _actual.x);                  \
	TEST_ASSERT_EQUAL_UINT32(_expected.y, _actual.y);                  \
	TEST_ASSERT_EQUAL_UINT32(_expected.z, _actual.z);                  \
})

#define TEST_ASSERT_EQUAL_FLOAT2(expected, actual) ({                  \
	pointF2_t _expected = (expected);                                  \
	pointF2_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL(_expected.x, _actual.x);                         \
	TEST_ASSERT_EQUAL(_expected.y, _actual.y);                         \
})

#define TEST_ASSERT_EQUAL_FLOAT3(expected, actual) ({                  \
	pointF3_t _expected = (expected);                                  \
	pointF3_t _actual = (actual);                                      \
	TEST_ASSERT_EQUAL(_expected.x, _actual.x);                         \
	TEST_ASSERT_EQUAL(_expected.y, _actual.y);                         \
	TEST_ASSERT_EQUAL(_expected.z, _actual.z);                         \
})

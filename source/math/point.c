#include "point.h"

#pragma region OPERATORS
#pragma region ADD
pointF2_t addF2F2(pointF2_t a, pointF2_t b) { 
	return float2(a.x + b.x, a.y + b.y);
}

pointF3_t addF3F3(pointF3_t a, pointF3_t b) {
	return float3(a.x + b.x, a.y + b.y, a.z + b.z);
}

pointI2_t addI2I2(pointI2_t a, pointI2_t b) {
	return int2(a.x + b.x, a.y + b.y);
}

pointI3_t addI3I3(pointI3_t a, pointI3_t b) {
	return int3(a.x + b.x, a.y + b.y, a.z + b.z);
}

pointU2_t addU2U2(pointU2_t a, pointU2_t b) {
	return uint2(a.x + b.x, a.y + b.y);
}

pointU3_t addU3U3(pointU3_t a, pointU3_t b) {
	return uint3(a.x + b.x, a.y + b.y, a.z + b.z);
}

pointF2_t addF2I2(pointF2_t a, pointI2_t b) {
	return float2(a.x + b.x, a.y + b.y);
}

pointF3_t addF3I3(pointF3_t a, pointI3_t b) {
	return float3(a.x + b.x, a.y + b.y, a.z + b.z);
}

pointF2_t addF2U2(pointF2_t a, pointU2_t b) {
	return float2(a.x + b.x, a.y + b.y);
}

pointF3_t addF3U3(pointF3_t a, pointU3_t b) {
	return float3(a.x + b.x, a.y + b.y, a.z + b.z);
}

pointI2_t addI2U2(pointI2_t a, pointU2_t b) {
	return int2(a.x + b.x, a.y + b.y);
}

pointI3_t addI3U3(pointI3_t a, pointU3_t b) {
	return int3(a.x + b.x, a.y + b.y, a.z + b.z);
}

#pragma endregion ADD
#pragma region SUB
pointF2_t subF2F2(pointF2_t a, pointF2_t b) {
	return float2(a.x - b.x, a.y - b.y);
}

pointF3_t subF3F3(pointF3_t a, pointF3_t b) {
	return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointI2_t subI2I2(pointI2_t a, pointI2_t b) {
	return int2(a.x - b.x, a.y - b.y);
}

pointI3_t subI3I3(pointI3_t a, pointI3_t b) {
	return int3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointU2_t subU2U2(pointU2_t a, pointU2_t b) {
	return uint2(a.x - b.x, a.y - b.y);
}

pointU3_t subU3U3(pointU3_t a, pointU3_t b) {
	return uint3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointF2_t subF2I2(pointF2_t a, pointI2_t b) {
	return float2(a.x - b.x, a.y - b.y);
}

pointF3_t subF3I3(pointF3_t a, pointI3_t b) {
	return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointF2_t subI2F2(pointI2_t a, pointF2_t b) {
	return float2(a.x - b.x, a.y - b.y);
}

pointF3_t subI3F3(pointI3_t a, pointF3_t b) {
	return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointU2_t subU2I2(pointU2_t a, pointI2_t b) {
	return uint2(a.x - b.x, a.y - b.y);
}

pointU3_t subU3I3(pointU3_t a, pointI3_t b) {
	return uint3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointI2_t subI2U2(pointI2_t a, pointU2_t b) {
	return int2(a.x - b.x, a.y - b.y);
}

pointI3_t subI3U3(pointI3_t a, pointU3_t b) {
	return int3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointF2_t subF2U2(pointF2_t a, pointU2_t b) {
	return float2(a.x - b.x, a.y - b.y);
}

pointF3_t subF3U3(pointF3_t a, pointU3_t b) {
	return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

pointF2_t subU2F2(pointU2_t a, pointF2_t b) {
	return float2(a.x - b.x, a.y - b.y);
}

pointF3_t subU3F3(pointU3_t a, pointF3_t b) {
	return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

#pragma endregion SUB
#pragma endregion OPERATORS
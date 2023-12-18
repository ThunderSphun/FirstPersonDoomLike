#include "point.h"

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

pointF2_t addF2I2(pointF2_t a, pointI2_t b) {
	return float2(a.x + b.x, a.y + b.y);
}

pointF3_t addF3I3(pointF3_t a, pointI3_t b) {
	return float3(a.x + b.x, a.y + b.y, a.z + b.z);
}

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

pointF2_t subF2I2(pointF2_t a, pointI2_t b) {
	return float2(a.x - b.x, a.y - b.y);
}

pointF3_t subF3I3(pointF3_t a, pointI3_t b) {
	return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}
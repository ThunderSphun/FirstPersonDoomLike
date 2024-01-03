#include "point.h"

#pragma region OPERATORS
#pragma region ADD

pointF2_t addF2F2(pointF2_t lhs, pointF2_t rhs) { return float2(lhs.x + rhs.x, lhs.y + rhs.y); }
pointF3_t addF3F3(pointF3_t lhs, pointF3_t rhs) { return float3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
pointI2_t addI2I2(pointI2_t lhs, pointI2_t rhs) { return int2(lhs.x + rhs.x, lhs.y + rhs.y); }
pointI3_t addI3I3(pointI3_t lhs, pointI3_t rhs) { return int3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
pointU2_t addU2U2(pointU2_t lhs, pointU2_t rhs) { return uint2(lhs.x + rhs.x, lhs.y + rhs.y );}
pointU3_t addU3U3(pointU3_t lhs, pointU3_t rhs) { return uint3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }

pointF2_t addF2I2(pointF2_t lhs, pointI2_t rhs) { return float2(lhs.x + rhs.x, lhs.y + rhs.y); }
pointF3_t addF3I3(pointF3_t lhs, pointI3_t rhs) { return float3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
pointF2_t addF2U2(pointF2_t lhs, pointU2_t rhs) { return float2(lhs.x + rhs.x, lhs.y + rhs.y); }
pointF3_t addF3U3(pointF3_t lhs, pointU3_t rhs) { return float3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }

pointI2_t addI2U2(pointI2_t lhs, pointU2_t rhs) { return int2(lhs.x + rhs.x, lhs.y + rhs.y); }
pointI3_t addI3U3(pointI3_t lhs, pointU3_t rhs) { return int3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }

#pragma endregion ADD
#pragma region SUB

pointF2_t subF2F2(pointF2_t lhs, pointF2_t rhs) { return float2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointF3_t subF3F3(pointF3_t lhs, pointF3_t rhs) { return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
pointI2_t subI2I2(pointI2_t lhs, pointI2_t rhs) { return int2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointI3_t subI3I3(pointI3_t lhs, pointI3_t rhs) { return int3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
pointU2_t subU2U2(pointU2_t lhs, pointU2_t rhs) { return uint2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointU3_t subU3U3(pointU3_t lhs, pointU3_t rhs) { return uint3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

pointF2_t subF2I2(pointF2_t lhs, pointI2_t rhs) { return float2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointF3_t subF3I3(pointF3_t lhs, pointI3_t rhs) { return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
pointF2_t subI2F2(pointI2_t lhs, pointF2_t rhs) { return float2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointF3_t subI3F3(pointI3_t lhs, pointF3_t rhs) { return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

pointU2_t subU2I2(pointU2_t lhs, pointI2_t rhs) { return uint2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointU3_t subU3I3(pointU3_t lhs, pointI3_t rhs) { return uint3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
pointI2_t subI2U2(pointI2_t lhs, pointU2_t rhs) { return int2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointI3_t subI3U3(pointI3_t lhs, pointU3_t rhs) { return int3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

pointF2_t subF2U2(pointF2_t lhs, pointU2_t rhs) { return float2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointF3_t subF3U3(pointF3_t lhs, pointU3_t rhs) { return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
pointF2_t subU2F2(pointU2_t lhs, pointF2_t rhs) { return float2(lhs.x - rhs.x, lhs.y - rhs.y); }
pointF3_t subU3F3(pointU3_t lhs, pointF3_t rhs) { return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

#pragma endregion SUB
#pragma endregion OPERATORS
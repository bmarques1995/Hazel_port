#ifndef IMATH_HPP
#define IMATH_HPP

#include <eigen3/Eigen/Eigen>
#include <cmath>

namespace Hazel
{
	typedef Eigen::Vector2f float2;
	typedef Eigen::Vector3f float3;
	typedef Eigen::Vector4f float4;
	typedef Eigen::RowVector2f rfloat2;
	typedef Eigen::RowVector3f rfloat3;
	typedef Eigen::RowVector4f rfloat4;
	typedef Eigen::Matrix3f float3x3;
	typedef Eigen::Matrix4f float4x4;
	typedef Eigen::Quaternionf quaternion;

	float4x4 Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
	float4x4 Eye4();
	float ToDegrees(float radians);
	float ToRadians(float degrees);
	float4x4 Inverse4(const float4x4& input);
	float4x4 Translate(const float4x4& input, const float3& position);
	float4x4 Rotate(const quaternion& input, float angle, const float3& axis);

	//
	/*
	Implementar

	-> Translate
	--> Scale
	-> Rotate
	-> Ortho
	--> Perspective
	-> Inverse
	*/
}

#endif
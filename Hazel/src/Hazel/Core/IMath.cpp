#include "Hazel/Core/IMath.hpp"
#include <glm/gtc/matrix_transform.hpp> 

Hazel::float4x4 Hazel::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	float4x4 ortho(float4x4::Zero());
	ortho(0, 0) = 2.0f / (right - left);
	ortho(1, 1) = 2.0f / (top - bottom);
	ortho(2, 2) = 2.0f / (zFar - zNear);
	ortho(3, 3) = 1.0f;
	return ortho;
}

Hazel::float4x4 Hazel::Eye4()
{
	return float4x4::Identity();
}

float Hazel::ToDegrees(float radians)
{
	return (180.0f * radians) / std::acosf(-1.0);
}

float Hazel::ToRadians(float degrees)
{
	return (std::acosf(-1.0) * degrees) / 180.0f;
}

Hazel::float4x4 Hazel::Inverse4(const float4x4& input)
{
	float4x4 result = input;
	result.inverse();
	return result;
}

Hazel::float4x4 Hazel::Translate(const float4x4& input, const float3& position)
{
	float4x4 translation = input;
	translation(3, 0) += position(0);
	translation(3, 1) += position(1);
	translation(3, 2) += position(2);
	return translation;
}

Hazel::float4x4 Hazel::Rotate(const quaternion& input, float angle, const float3& axis)
{
	float4x4 output = float4x4::Identity();
	Eigen::Quaternionf rotationQuaternion;
	rotationQuaternion = Eigen::AngleAxisf(angle, axis);

	float3x3 rotation_result = rotationQuaternion.toRotationMatrix();

	for (size_t i = 0; i < rotation_result.rows(); i++)
		for (size_t j = 0; j < rotation_result.cols(); j++)
			output(i, j) = rotation_result(i, j);

	return output;
}



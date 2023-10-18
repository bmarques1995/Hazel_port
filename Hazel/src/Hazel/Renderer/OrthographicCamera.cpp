#include "hzpch.hpp"
#include "OrthographicCamera.hpp"

//#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: m_ProjectionMatrix(Hazel::Ortho(left, right, bottom, top, 0.0f, 1.0f)), m_ViewMatrix(Hazel::Eye4())
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		float4x4 transform = Hazel::Rotate(quaternion::Identity(), Hazel::ToRadians(m_Rotation), float3(0, 0, 1)) * Hazel::Translate(Hazel::Eye4(), m_Position);

		m_ViewMatrix = Hazel::Inverse4(transform).transpose();
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

}
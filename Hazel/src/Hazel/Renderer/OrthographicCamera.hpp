#ifndef ORTHOGRAPHIC_CAMERA_HPP
#define ORTHOGRAPHIC_CAMERA_HPP

#include "Hazel/Core/IMath.hpp"
#include "Hazel/Core.hpp"

namespace Hazel {

	class HAZEL_API OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		const float3& GetPosition() const { return m_Position; }
		void SetPosition(const float3& position) { m_Position = position; RecalculateViewMatrix(); }

		float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		const float4x4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const float4x4& GetViewMatrix() const { return m_ViewMatrix; }
		const float4x4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	private:
		void RecalculateViewMatrix();
	private:
		float4x4 m_ProjectionMatrix;
		float4x4 m_ViewMatrix;
		float4x4 m_ViewProjectionMatrix;

		float3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};

}

#endif

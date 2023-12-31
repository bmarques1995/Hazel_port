#include "hzpch.hpp"
#include "OpenGLRendererAPI.hpp"

#include <glad/gl.h>

void Hazel::OpenGLRendererAPI::SetClearColor(const float4& color)
{
	glClearColor(color(0), color(1), color(2), color(3));
}

void Hazel::OpenGLRendererAPI::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Hazel::OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
{
	glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}


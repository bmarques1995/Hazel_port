#include "hzpch.hpp"
#include "VertexArray.hpp"

#include "Renderer.hpp"
#include "Platform/OpenGL/OpenGLVertexArray.hpp"

Hazel::VertexArray* Hazel::VertexArray::Create()
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLVertexArray();
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}

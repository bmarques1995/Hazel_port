#ifndef OPENGL_RENDERER_API_HPP
#define OPENGL_RENDERER_API_HPP

#include "Hazel/Renderer/RendererAPI.hpp"

namespace Hazel {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(const float4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};


}

#endif

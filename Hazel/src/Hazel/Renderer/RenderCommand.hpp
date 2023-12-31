#ifndef RENDER_COMMAND_HPP
#define RENDER_COMMAND_HPP

#include "RendererAPI.hpp"

namespace Hazel {

	class HAZEL_API RenderCommand
	{
	public:
		inline static void SetClearColor(const float4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};

}

#endif

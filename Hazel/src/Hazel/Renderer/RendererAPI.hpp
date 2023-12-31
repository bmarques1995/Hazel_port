#ifndef RENDERER_API_HPP
#define RENDERER_API_HPP

#include "Hazel/Core/IMath.hpp"

#include "VertexArray.hpp"

namespace Hazel {

	class HAZEL_API RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};
	public:
		virtual void SetClearColor(const float4& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};

}

#endif

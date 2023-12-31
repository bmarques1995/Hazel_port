#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "RenderCommand.hpp"

#include "OrthographicCamera.hpp"
#include "Shader.hpp"

namespace Hazel {

	class HAZEL_API Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			float4x4 ViewProjectionMatrix;
		};

		static SceneData* s_SceneData;
	};
}

#endif

#include "hzpch.hpp"
#include "Renderer.hpp"

Hazel::Renderer::SceneData* Hazel::Renderer::s_SceneData = new Renderer::SceneData;

void Hazel::Renderer::BeginScene(OrthographicCamera& camera)
{
	s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
}

void Hazel::Renderer::EndScene()
{
}

void Hazel::Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray)
{
	shader->Bind();
	shader->UploadUniformMat4("u_ViewProjection", &s_SceneData->ViewProjectionMatrix(0,0));

	vertexArray->Bind();
	RenderCommand::DrawIndexed(vertexArray);
}
#pragma once

#include <string>
#include <glm/glm.hpp>

#include "Hazel/Core.hpp"

namespace Hazel {

	class HAZEL_API Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		uint32_t m_RendererID;
	};

}
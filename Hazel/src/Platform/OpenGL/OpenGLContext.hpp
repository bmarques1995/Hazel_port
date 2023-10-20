#ifndef OPENGL_CONTEXT_HPP
#define OPENGL_CONTEXT_HPP

#include "Hazel/Renderer/GraphicsContext.hpp"

struct GLFWwindow;

namespace Hazel {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void Present() override;
		//this is thinking in D3D11, Vulkan and D3D12, that controls the VSync at graphics context
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() override;
	private:
		GLFWwindow* m_WindowHandle;
		bool m_VSync;
	};

}

#endif

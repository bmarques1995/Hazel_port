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
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}

#endif

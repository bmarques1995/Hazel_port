#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <GL/GL.h>

namespace Hazel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		std::string glInfo = reinterpret_cast<const char*>(glGetString(GL_VENDOR));

		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO("  Vendor: {0}", glInfo);
		glInfo = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
		HZ_CORE_INFO("  Renderer: {0}", glInfo);
		glInfo = reinterpret_cast<const char*>(glGetString(GL_VERSION));
		HZ_CORE_INFO("  Version: {0}", glInfo);

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
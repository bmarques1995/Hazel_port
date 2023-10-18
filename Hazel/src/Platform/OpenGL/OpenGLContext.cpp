#include "hzpch.hpp"
#include "OpenGLContext.hpp"

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


		Console::CoreLog("OpenGL Info:");
		Console::CoreLog("  Vendor: {0}", glInfo);
		glInfo = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
		Console::CoreLog("  Renderer: {0}", glInfo);
		glInfo = reinterpret_cast<const char*>(glGetString(GL_VERSION));
		Console::CoreLog("  Version: {0}", glInfo);

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
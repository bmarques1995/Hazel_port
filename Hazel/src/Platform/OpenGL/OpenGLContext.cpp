#include "hzpch.hpp"
#include "OpenGLContext.hpp"

#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <GL/GL.h>

Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
}

void Hazel::OpenGLContext::Init()
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

	glDepthRange(0.0f, 1.0f);
}

void Hazel::OpenGLContext::Present()
{
	glfwSwapBuffers(m_WindowHandle);
}

void Hazel::OpenGLContext::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);
	m_VSync = enabled;
}

bool Hazel::OpenGLContext::IsVSync()
{
	return m_VSync;
}

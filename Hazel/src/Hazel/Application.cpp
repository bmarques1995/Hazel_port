#include "hzpch.hpp"

#include "Application.hpp"
#include "Hazel/Console.hpp"
#include "Hazel/Renderer/Renderer.hpp"
#include "Input.hpp"

#include <glfw/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Hazel::Application* Hazel::Application::s_Instance = nullptr;

Hazel::Application::Application()
{
	HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;

	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

void Hazel::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void Hazel::Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
}

void Hazel::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
	{
		(*--it)->OnEvent(e);
		if (e.Handled)
			break;
	}
}

void Hazel::Application::Run()
{
	while (m_Running)
	{
		float time = (float)glfwGetTime();
		Timestep timestep = time - m_LastFrameTime;
		m_LastFrameTime = time;

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate(timestep);

		m_Window->OnUpdate();
	}
}

bool Hazel::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

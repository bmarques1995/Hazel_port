#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Core.hpp"

#include "Window.hpp"
#include "Hazel/LayerStack.hpp"
#include "Hazel/Events/Event.hpp"
#include "Hazel/Events/ApplicationEvent.hpp"

#include "Hazel/Core/Timestep.hpp"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

#endif
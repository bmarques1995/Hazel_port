#ifndef GLFW_WINDOW_HPP
#define GLFW_WINDOW_HPP

#include "Hazel/Window.hpp"
#include "Hazel/Renderer/GraphicsContext.hpp"

#include <GLFW/glfw3.h>

namespace Hazel {

	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowProps& props);
		virtual ~GLFWWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

		inline virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}

#endif

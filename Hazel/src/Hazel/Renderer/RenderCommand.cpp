#include "hzpch.hpp"
#include "RenderCommand.hpp"

#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

Hazel::RendererAPI* Hazel::RenderCommand::s_RendererAPI = new Hazel::OpenGLRendererAPI;

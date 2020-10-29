#pragma once

#include <glad/gl.h>
#include <glad/vulkan.h>
#include <GLFW/glfw3.h>

#include <Tracy.hpp>

namespace Core::Renderer
{
	enum class RendererType : char
	{
		OpenGL,
		Vulkan,
	};

	class Window
	{
	protected:
		GLFWwindow*		m_window{ nullptr };
		RendererType	m_rendererType;
	public:
		Window(RendererType = RendererType::OpenGL);

		bool	Init();

		void	SwapBuffers();
	};
}

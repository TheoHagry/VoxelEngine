#pragma once

#include <glad/gl.h>
#include <glad/vulkan.h>
#include <GLFW/glfw3.h>

#include "CoreMinimal.h"

namespace Core::Datastructure
{
	class EngineCore;
}

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
		Core::Datastructure::EngineCore* m_core;
		GLFWwindow*		m_window{ nullptr };
		RendererType	m_rendererType;
	public:
		Window(Core::Datastructure::EngineCore*, RendererType = RendererType::OpenGL) noexcept;

		bool	Init() noexcept;

		void	SwapBuffers() noexcept;

		bool	ShouldClose() const noexcept;
		GLFWwindow* GetWindow() noexcept { return m_window; }
	};
}

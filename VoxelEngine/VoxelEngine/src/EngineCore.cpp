#include "EngineCore.h"

namespace Core::Datastructure
{
	EngineCore::EngineCore() noexcept : m_window()
	{
	}

	bool EngineCore::Init() noexcept
	{
		return m_window.Init();
	}
	void EngineCore::MainLoop() noexcept
	{
		while (!m_window.ShouldClose() && !m_shouldClose)
		{
			glfwPollEvents();
			m_window.SwapBuffers();
		}
	}
}
	
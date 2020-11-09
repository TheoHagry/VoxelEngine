#include "EngineCore.h"
#include <iostream>

namespace Core::Datastructure
{
	EngineCore::EngineCore() noexcept : m_window{ this }, m_input{ this }
	{
	}

	bool EngineCore::Init() noexcept
	{
		return m_window.Init() && m_input.Init();
	}
	void EngineCore::MainLoop() noexcept
	{
		FrameMark
		while (!m_window.ShouldClose() && !m_shouldClose)
		{
			m_input.PollEvents();
			m_window.SwapBuffers();
			FrameMark
		}
	}
}
	
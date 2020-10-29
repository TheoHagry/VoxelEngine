#pragma once

#include "CoreMinimal.h"

#include "Window.h"

namespace Core::Datastructure
{
	class EngineCore
	{
	protected:
		Core::Renderer::Window	m_window;
		bool					m_shouldClose{ false };
	public:
		EngineCore() noexcept;

		bool	Init() noexcept;
		void	MainLoop() noexcept;

		void	Close() noexcept { m_shouldClose = true; };
	};
}


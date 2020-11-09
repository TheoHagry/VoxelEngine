#pragma once

#include "CoreMinimal.h"

#include "Window.h"
#include "InputManager.h"
#include "ResourceManager.h"

namespace Core::Datastructure
{
	class EngineCore
	{
	protected:
		Core::Renderer::Window				m_window;
		Core::Datastructure::InputManager	m_input;
		Core::Resources::ResourceManager	m_manager;
		bool								m_shouldClose{ false };
	public:
		EngineCore() noexcept;

		bool	Init() noexcept;
		void	MainLoop() noexcept;

		void	Close() noexcept { m_shouldClose = true; };

		Core::Renderer::Window&				GetWindow() noexcept { return m_window; }
		Core::Datastructure::InputManager&	GetInputSystem() noexcept { return m_input; }
	};
}


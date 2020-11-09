#pragma once

#include "CoreMinimal.h"
#include <unordered_map>
#include "Input.hpp"

namespace Core::Datastructure
{
	class EngineCore;

	/**
	 * Define cursor appearance type
	 */
	enum class ECursorAppearance
	{
		DEFAULT = 0,
		INVISIBLE = 1
	};

	class InputManager
	{
	protected:
		/* Stockage mouse buttons, keys and scroll */
		std::unordered_map<EKey, EStateKey> m_registeredKeys;
		std::unordered_map<EMouseButton, EStateMouseButton> m_registeredMouseButtons;
		ECursorAppearance m_cursorAppearance{ ECursorAppearance::DEFAULT };
		double m_registeredScroll{ 0.0 };

		/* Double click handling */
		std::chrono::time_point<std::chrono::system_clock> m_nowClock;
		std::chrono::time_point<std::chrono::system_clock> m_beforeClock;
		EMouseButton m_lastClickedButton{ EMouseButton::LEFT };
		bool m_isTimeSet = false;
		bool m_isActive = true;

		Core::Datastructure::EngineCore* m_core;

		void	ClearInputs() noexcept;
	public:
		InputManager(Core::Datastructure::EngineCore*) noexcept;
		bool	Init() noexcept;

		void	PollEvents() noexcept;
		void	ProcessKey(EKey key, EStateKey action) noexcept 
		{
			m_registeredKeys[key] = action;
			//std::cout << ToString(key) << " " << ToString(action) << std::endl;
		}
		void	ProcessMouseButton(EMouseButton key, EStateMouseButton action) noexcept 
		{
			m_registeredMouseButtons[key] = action;
			//std::cout << ToString(key) << " " << ToString(action) << std::endl;
		}
		void	ProcessScroll(double yOffset) noexcept
		{
			m_registeredScroll += yOffset;
			//std::cout << "Scroll " << yOffset << std::endl;
		}

		EStateKey	GetKeyState(EKey key);
	};
}

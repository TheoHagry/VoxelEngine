#include "InputManager.h"

#include "Window.h"
#include "EngineCore.h"
#include <iostream>

namespace Core::Datastructure
{
	void InputManager::ClearInputs() noexcept
	{
		ZoneScoped
		// Clearing keys
		for (auto itr = m_registeredKeys.begin(); itr != m_registeredKeys.end();)
		{
			if (itr->second == EStateKey::PRESS)
			{
				itr->second = EStateKey::DOWN;
				++itr;
			}
			else if (itr->second == EStateKey::UP)
				itr = m_registeredKeys.erase(itr);
			else
				++itr;
		}

		// Clearing mouse buttons
		for (auto itr = m_registeredMouseButtons.begin(); itr != m_registeredMouseButtons.end();)
		{
			if (itr->second == EStateMouseButton::PRESS)
			{
				itr->second = EStateMouseButton::DOWN;
				++itr;
			}
			else if (itr->second == EStateMouseButton::UP || itr->second == EStateMouseButton::DOUBLECLICK)
				itr = m_registeredMouseButtons.erase(itr);
			else
				++itr;
		}

		// Clearing scroll
		m_registeredScroll = 0.0;
	}

	InputManager::InputManager(Core::Datastructure::EngineCore* core) noexcept : m_core{ core }
	{
	}

	bool InputManager::Init() noexcept
	{
		ZoneScoped
		GLFWkeyfun key_callback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			ZoneScopedN("InputSystemKeyUpdate")
				ZoneText("Updating key presses", 21)
			EngineCore* core = reinterpret_cast<EngineCore*>(glfwGetWindowUserPointer(window));
			if (core)
			{
				core->GetInputSystem().ProcessKey(static_cast<EKey>(key), static_cast<EStateKey>(action));
			}
		};
		
		GLFWmousebuttonfun mouse_button_callback = [](GLFWwindow* window, int key, int action, int mods)
		{
			ZoneScopedN("InputSystemMouseButtonUpdate")
				ZoneText("Updating MouseButton presses", 29)
				EngineCore* core = reinterpret_cast<EngineCore*>(glfwGetWindowUserPointer(window));
			if (core)
			{
				core->GetInputSystem().ProcessMouseButton(static_cast<EMouseButton>(key), static_cast<EStateMouseButton>(action));
			}
		}; 
		
		GLFWscrollfun scroll_callback = [](GLFWwindow* window, double xoffset, double yoffset)
		{
			ZoneScopedN("InputSystemScrollUpdate")
				ZoneText("Updating Scrolling", 19)
				EngineCore* Core = reinterpret_cast<EngineCore*>(glfwGetWindowUserPointer(window));
			if (Core)
			{
				Core->GetInputSystem().ProcessScroll(yoffset);
			}
		};

		glfwSetKeyCallback(m_core->GetWindow().GetWindow(), key_callback);
		glfwSetMouseButtonCallback(m_core->GetWindow().GetWindow(), mouse_button_callback);
		glfwSetScrollCallback(m_core->GetWindow().GetWindow(), scroll_callback);
		return true;
	}

	void InputManager::PollEvents() noexcept
	{
		ZoneScoped
		ClearInputs();
		glfwPollEvents();
	}
}

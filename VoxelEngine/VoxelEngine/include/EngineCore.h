#pragma once

#include <Tracy.hpp>

#include "Window.h"

namespace Core::Datastructure
{
	class EngineCore
	{
	protected:
		Core::Renderer::Window m_window;
	public:
		EngineCore();
	};
}


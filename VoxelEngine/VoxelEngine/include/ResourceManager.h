#pragma once

#include "CoreMinimal.h"
#include "Resource.h"

#include <list>
#include <memory>

namespace Core::Resources
{
	class ResourceManager
	{
	protected:
		std::list<std::shared_ptr<Resource>>	m_resources;
	public:
		ResourceManager() noexcept;

		std::shared_ptr<Resource>	AddResouce(std::shared_ptr<Resource> newResource) noexcept;

		int						RemoveUnusedResources() noexcept;
	};
}


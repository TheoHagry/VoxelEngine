#include "ResourceManager.h"
#include <iostream>

namespace Core::Resources
{
	ResourceManager::ResourceManager() noexcept
	{
	}

	std::shared_ptr<Resource> ResourceManager::AddResouce(std::shared_ptr<Resource> newResource) noexcept
	{
		m_resources.push_back(newResource);
		return newResource;
	}

	int ResourceManager::RemoveUnusedResources() noexcept
	{
		int i = 0;
		for (auto it = m_resources.begin(); it != m_resources.end();)
		{
			if (it->use_count() == 1)
			{
				it = m_resources.erase(it);
				std::cout << "Removed 1 unused resource" << std::endl;
				++i;
			}
			else
				++it;
		}
		std::cout << "Removed " << i << " total resources" << std::endl;
	}
}

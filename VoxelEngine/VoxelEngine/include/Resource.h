#pragma once

#include "CoreMinimal.h"

namespace Core::Resources
{
	class Resource
	{
	public:
		Resource() noexcept;
		virtual ~Resource() noexcept;
	};
}
#pragma once

#pragma warning(disable : 4201)

#include <cmath>

namespace Maths
{
	template <unsigned Line, unsigned Column>
	concept MatSquare = Line == Column;

	/*
	* Val is superior or equal to Min but inferior to Max
	*/
	template <unsigned Min, unsigned Max, unsigned Val>
	concept InRange = Val >= Min && Max > Val;
}

#ifndef FORCEINLINE
#if __GNUC__ || __has_attribute(always_inline)
#define FORCEINLINE __attribute__((always_inline))
#elif defined(_MSC_VER) && !__INTEL_COMPILER && _MSC_VER >= 1310 // since Visual Studio .NET 2003
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE inline
#endif
#endif
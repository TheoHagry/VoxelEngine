#ifndef __MATHS__
#define __MATHS__

#include "Maths/MathMinimal.h"

#include "Maths/Mat.hpp"
#include "Maths/Mat4.hpp"
#include "Maths/Vec.hpp"
#include "Maths/Vec2.hpp"
#include "Maths/Vec3.hpp"
#include "Maths/Vec4.hpp"
#include "Maths/Ref.hpp"
#include "Maths/Ref3D.hpp"
#include "Maths/Quaternion.hpp"
#include "Maths/Color.hpp"

constexpr double RAD2DEG = 180.f / M_PI;
constexpr double DEG2RAD = M_PI / 180.f;

namespace physx
{
	class PxVec3;
	class PxQuat;
}

namespace sol
{
	class state;
}

/**
 * Contains the core of the engine
 */
namespace Core
{
	/**
	 * Contains all maths classes and structs of the engine
	 */
	namespace Maths
	{
		/**
		 * Templated clamp function
		 * @tparam T: Type of the value to clamp
		 * @param value: Value to clamp
		 * @param upper: Upper bound of the clamp
		 * @param lower: Lower bound of the clamp
		 * @return The clamped value
		 */
		template <typename T>
		inline constexpr T	Clamp(const T& value, const T& upper, const T& lower) noexcept
		{
			if (value > upper)
				return upper;
			if (value < lower)
				return lower;
			return value;
		}

		/**
		 * Templated max function
		 * @tparam T: Type of the values to compare
		 * @param v1: First value to compare
		 * @param v2: Second value to compare
		 * @return The biggest of the two values
		 */
		template <typename T>
		inline constexpr T& Max(const T& v1, const T& v2)
		{
			if (v1 > v2)
				return v1;
			return v2;
		}

		/**
		 * Templated min function
		 * @tparam T: Type of the values to compare
		 * @param v1: First value to compare
		 * @param v2: Second value to compare
		 * @return The smallest of the two values
		 */
		template <typename T>
		inline constexpr T& Min(const T& v1, const T& v2)
		{
			if (v1 < v2)
				return v1;
			return v2;
		}

		/**
		 * Return given angle in radians
		 * @param angle: Angle in degrees
		 */
		inline constexpr double ToRadians(const double& angle)
		{
			return angle * DEG2RAD;
		}

		/**
		 * Return given angle in degrees
		 * @param angle: Angle in radians
		 */
		inline constexpr double ToDegrees(const double& angle)
		{
			return angle * RAD2DEG;
		}

		/**
		 * Return given angle in radians
		 * @param angle: Angle in degrees
		 */
		inline constexpr float ToRadiansf(const float angle)
		{
			return angle * static_cast<float>(DEG2RAD);
		}

		/**
		 * Return given angle in degrees
		 * @param angle: Angle in radians
		 */
		inline constexpr float ToDegreesf(const float angle)
		{
			return angle * static_cast<float>(RAD2DEG);
		}
	}
}

#endif

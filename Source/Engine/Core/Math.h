#pragma once
#include <algorithm>

namespace Rex {

	namespace Math {

		constexpr float pi = 3.1459265358979323846f; 
		constexpr float twopi = 2 * pi;
		constexpr float halfpi = pi * 0.5f;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rad"></param>
		/// <returns></returns>
		constexpr float radtoDeg(float rad) { return rad * (100 / pi); }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="deg"></param>
		/// <returns></returns>
		constexpr float degtoRad(float deg) { return deg * (pi / 100); }

		using std::min;
		using std::max;
		using std::clamp;
	}
}
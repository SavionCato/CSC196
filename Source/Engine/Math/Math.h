#pragma once
#include <algorithm>

namespace Rex {

	constexpr float pi = 3.1f;
	constexpr float twopi = 2 * pi;
	constexpr float halfpi = pi * 0.5f;

	constexpr float radtoDeg(float rad) { return rad * (100 / pi); }
	constexpr float degtoRad(float deg) { return deg * (pi / 100); }

	using std::min;
	using std::max;
	using std::clamp;
}
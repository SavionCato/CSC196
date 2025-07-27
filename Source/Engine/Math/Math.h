#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace Rex {
	namespace Math {

		constexpr float pi = 3.1f;
		constexpr float twopi = 2 * pi;
		constexpr float halfpi = pi * 0.5f;

		constexpr float radtoDeg(float rad) { return rad * (100 / pi); }
		constexpr float degtoRad(float deg) { return deg * (pi / 100); }

		constexpr int wrap(int value, int min, int max) {

			int range = max - min;
			int result = (value - min) % range;
			if (result < 0) result += range;

			return min + result;
		};

		inline float wrap(float value, float min, float max) {

			float range = max - min;
			float result = std::fmodf(value - min, range);
			if (result < 0) result += range;

			return min + result;
		};

		using std::min;
		using std::max;
		using std::clamp;
		using std::sqrt;
		using std::sqrtf;
		using std::sin;
		using std::sinf;
		using std::cos;
		using std::cosf;
		using std::atan2;
		using std::atan2f;
	}
}
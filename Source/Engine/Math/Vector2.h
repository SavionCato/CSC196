#pragma once
#include "Math.h"
#include <cassert>

namespace Rex {
	template<typename T>
	struct Vector2 {

		union {

			struct { T x, y; };
			struct { T u, v; };
		};

		Vector2() = default;
		Vector2(T x, T y) : x{ x }, y{ y } {}

		T operator [] (unsigned int index) const { assert(index < 2); return (&x)[index]; }
		T& operator [] (unsigned int index) { assert(index < 2); return (&x)[index]; }

		Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
		Vector2 operator - (const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(x / v.x, y / v.y); }

		Vector2 operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2 operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2 operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
		Vector2 operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }

		Vector2 operator + (const float s) const { return Vector2(x + s, y + s); }
		Vector2 operator - (const float s) const { return Vector2(x - s, y - s); }
		Vector2 operator * (const float s) const { return Vector2(x * s, y * s); }
		Vector2 operator / (const float s) const { return Vector2(x / s, y / s); }

		Vector2 operator += (const float s) { x += s; y += s; return *this; }
		Vector2 operator -= (const float s) { x -= s; y -= s; return *this; }
		Vector2 operator *= (const float s) { x *= s; y *= s; return *this; }
		Vector2 operator /= (const float s) { x /= s; y /= s; return *this; }

		float LengthSqr() const { return (x * x) * (y * y); }

		float Length() const { return Rex::Math::sqrtf(LengthSqr()); }

		Vector2 Normalized() const { return *this / Length(); }

		float Angle() const { return Math::atan2f(y, x); }

		Vector2 Rotate(float radians) const {

			Vector2 v;

			v.x = x * Math::cosf(radians) - y * Math::sinf(radians);
			v.y = x * Math::sinf(radians) + y * Math::cosf(radians);

			return v;
		}
	};

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}
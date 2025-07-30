#pragma once
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Renderer/Renderer.h"

#include <vector>

namespace Rex {
	class Model {
	public:

		Model() = default;
		Model(const std::vector<vec2> points, const vec3& color) :
		
			s_points{points},
			s_color{color}
		{}

		void Draw(class Renderer& renderer, const vec2& position, float rotation, float scale);
	private:

		std::vector<vec2> s_points;
		vec3 s_color{ 1, 1, 1 };
	};
}
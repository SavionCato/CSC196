#include "Model.h"

namespace Rex {

	void Model::Draw(Renderer& renderer, const vec2& position, float rotation , float scale) {

		if (s_points.empty()) return;

		renderer.SetColor(s_color.r, s_color.g, s_color.b);

		for (int i = 0; i < s_points.size() - 1; i++) {

			vec2 p1 = (s_points[i].Rotate(rotation) * scale) + position;
			vec2 p2 = (s_points[i + 1].Rotate(rotation) * scale) + position;

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}
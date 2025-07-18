#pragma once
#include <vector>
#include <memory>

namespace Rex {
	class Scene {
	public:

		Scene() = default;

		void Update(float dt);
		void Draw();
	private:
	};
}
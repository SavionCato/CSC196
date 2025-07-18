#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <memory>

namespace Rex {
	class Actor {
	public:

		Actor() = default;
		//Actor();

		virtual void Update(float dt);
		virtual void Draw();
	private:

		
	};
}
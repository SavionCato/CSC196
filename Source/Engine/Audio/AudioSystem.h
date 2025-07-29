#pragma once
#include "../Core/StringHelper.h"

#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <map>

namespace Rex {
	class AudioSystem {
	public:

		AudioSystem() = default;

		bool Initialize();
		void Shutdown();

		void Update();

		bool AddSound(const std::string& filename, const std::string& name);
		bool PlaySound(const std::string& name);
	private:

		bool CheckFMODResult(FMOD_RESULT result);
	private:

		FMOD::System* s_system = nullptr;
		std::map<std::string, FMOD::Sound*> s_sounds;
	};
}

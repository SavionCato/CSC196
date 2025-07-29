#include "AudioSystem.h"

namespace Rex {

	bool AudioSystem::CheckFMODResult(FMOD_RESULT result) {
	
		if (result != FMOD_OK) {

			std::cerr << FMOD_ErrorString(result) << std::endl;
			return false;
		}

		return true;
	}

	bool AudioSystem::Initialize() {

		FMOD_RESULT result = FMOD::System_Create(&s_system);
		
		
		if (!CheckFMODResult(result)) return false;
		
		void* extradriverdata = nullptr;
		s_system->init(32, FMOD_INIT_NORMAL, extradriverdata);

		if (!CheckFMODResult(result)) return false;

		return true;
	}

	void AudioSystem::Shutdown() {
				
		if (!CheckFMODResult(s_system->release()));
	}

	void AudioSystem::Update() {

		if (!CheckFMODResult(s_system->update()));
	}

	bool AudioSystem::AddSound(const std::string& filename, const std::string& name) {

		std::string key = (name.empty()) ? filename : name;
		key = tolower(key);

		if(s_sounds.find(key) != s_sounds.end()) {
		
			std::cerr << "[Error] : Audio key already exists. " << key << std::endl;
			return false;
		}

		FMOD::Sound* sound = nullptr;
		FMOD_RESULT result = s_system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
		
		if (!CheckFMODResult(result)) return false;

		s_sounds[key] = sound;

		return true;
	}

	bool AudioSystem::PlaySound(const std::string& name)	{

		std::string key = name;
		key = tolower(key);

		if (s_sounds.find(key) == s_sounds.end()) {

			std::cerr << "[Error] : Audio name does not exist. " << key << std::endl;
			return false;
		}

		FMOD_RESULT result = s_system->playSound(s_sounds[key], 0, false, nullptr);
		if (!CheckFMODResult(result)) return false;

		return true;
	}
}
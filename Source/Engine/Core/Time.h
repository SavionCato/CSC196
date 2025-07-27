#pragma once
#include<chrono>

namespace Rex {
	class Time {
	private:

		using clock = std::chrono::high_resolution_clock;
	public:

		Time() {
		
			m_startTime = clock::now();
			m_frameTime = clock::now();
		}

		void Tick();
		void Reset() { m_startTime = clock::now(); }

		float GetTime() const { return s_time; }
		float GetDeltaTime() const { return s_deltaTime; }
	private:

		float s_time = 0;
		float s_deltaTime = 0;

		clock::time_point m_startTime;
		clock::time_point m_frameTime;
	};
}

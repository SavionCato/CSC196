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

	private:

		clock::time_point m_startTime;
		clock::time_point m_frameTime;
	};
}

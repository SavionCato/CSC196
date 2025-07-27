#include "Time.h"

namespace Rex {
	void Rex::Time::Tick() {

		clock::time_point now = clock::now();
		s_time = std::chrono::duration<float>(now - m_startTime).count();
		s_deltaTime = std::chrono::duration<float>(now - m_frameTime).count();
		m_frameTime = now;
	}
}

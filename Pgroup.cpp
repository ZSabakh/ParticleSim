#include "Pgroup.h"


namespace cof {
	Pgroup::Pgroup(): lastTime(0) {
		m_pParticles = new Particle[NPARTICLES];
	}

	Pgroup::~Pgroup() {
		delete[] m_pParticles;
	}

	void Pgroup::update(int elapsed) {

		int interval = elapsed - lastTime;

		for (int i = 0; i < Pgroup::NPARTICLES; i++) {
			m_pParticles[i].update(interval);

		}

		lastTime = elapsed;
	}

}
#pragma once
#include "Particle.h"

namespace cof {
	class Pgroup
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		Particle* m_pParticles;
		int lastTime;

	public:
		Pgroup();
		virtual ~Pgroup();
		void update(int elapsed);

		const Particle* const getParticles() { return m_pParticles; };
	};
}


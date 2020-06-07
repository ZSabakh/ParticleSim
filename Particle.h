#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace cof {
	struct Particle
	{
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;
		void init();

	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	};
}

#endif PARTICLE_H_

#include <iostream>
#include <iomanip>
#include <SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Pgroup.h"

#undef main

using namespace std;
using namespace cof;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error! Screen didn't initliaze " << endl;
	}

	Pgroup pgroup;

	while (true) {

		int elapsed = SDL_GetTicks();

		
		pgroup.update(elapsed);

		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const Particle* const pParticles = pgroup.getParticles();


		for (int i = 0; i < Pgroup::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
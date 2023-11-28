#include "Engine.h"


// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();


RenderWindow m_Window;

//vector for Particles
vector<Particle> m_particles;

// Private functions for internal use only
void input();
void update(float dtAsSeconds);
void draw();

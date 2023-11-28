#include "Engine.h"


// The Engine constructor
Engine::Engine();

// Run will call all the private functions
Engine::void run();


Engine::RenderWindow m_Window;

//vector for Particles
vector<Particle> m_particles;

// Private functions for internal use only
void Engine::input();
void Engine::update(float dtAsSeconds);
void Engine::draw();

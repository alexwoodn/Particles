#include "Engine.h"
#using namespace sf;
#using namespace std;

// The Engine constructor
Engine::Engine()
{
	VideoMode desktop = VideoMode::getDesktopMode();
	RenderWindow m_Window(desktop, "Particles", Style::Default);
}
// Run will call all the private functions
void Engine::run()
{
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;
  
}

// Private functions for internal use only
void Engine::input()
{
	
}
void Engine::update(float dtAsSeconds)
{
	
}
void Engine::draw()
{
	window.clear()
	window.draw(Particles);
    
}

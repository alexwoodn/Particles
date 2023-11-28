#include "Engine.h"
#using namespace sf;
#using namespace std;

// The Engine constructor
Engine::Engine()
{
    
}
// Run will call all the private functions
Engine::void run()
{
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
  
}


Engine::RenderWindow m_Window
{
  	VideoMode desktop = VideoMode::getDesktopMode();
    RenderWindow window(desktop, "Particle Viewer",
}

//vector for Particles
vector<Particle> m_particles
{
  
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
  
}

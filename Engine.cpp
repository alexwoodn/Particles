#include "Engine.h"
#using namespace sf;
#using namespace std;

// The Engine constructor
Engine::Engine()
    : m_Window(VideoMode::getDesktopMode(), "Particle System"), m_particles()
{}


// Run will call all the private functions
void Engine::run()
{
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;
  
	Clock clock;

   	 while (m_Window.isOpen())
    	{
        	Time dt = clock.restart();
       		float dtAsSeconds = dt.asSeconds();

       		input();
        	update(dtAsSeconds);
        	draw();
   	}
}

// Input function
void Engine::input() {
    Event event;
    while (m_Window.pollEvent(event)) {
        // Handle the Escape key pressed and closed events
        if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
            m_Window.close();
        }

        // Handle the left mouse button pressed event
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            // Create 5 particles
            for (int i = 0; i < 5; ++i) {
                int numPoints = rand() % 26 + 25;  // Random number in the range [25:50]
                Particle newParticle(m_Window, numPoints, { event.mouseButton.x, event.mouseButton.y });
                m_particles.push_back(newParticle);
            }
        }
    }
}


// Update function
void Engine::update(float dtAsSeconds) {
    auto it = m_particles.begin();
    while (it != m_particles.end()) {
        if (it->getTTL() > 0.0) {
            it->update(dtAsSeconds);
            ++it;  
        } else {
            it = m_Particles.erase(it);
        }
    }
}


// Draw function
void Engine::draw() {
    // clear the window
    m_Window.clear();

    for (const auto& particle : m_particles) {
        particle.draw(m_Window);
    }

    // display the window
    m_Window.display();
}


#include "Engine.h"
using namespace sf;
using namespace std;

// The Engine constructor
Engine::Engine()
{
	m_Window.create(VideoMode::getDesktopMode(), "Particles");
}



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
void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
        {
            m_Window.close();
        }
        else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            // Create 5 particles
            for (int i = 0; i < 5; ++i)
            {
                int numPoints = rand() % 26 + 25; // Random number in the range [25:50]
                Vector2i mousePos = Mouse::getPosition(m_Window);
                m_particles.push_back(Particle(m_Window, numPoints, {mousePos.x, mousePos.y}));
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
            it = m_particles.erase(it);
        }
    }
}


// Draw function
void Engine::draw() {
    // clear the window
    m_Window.clear();

    for (const auto& particle : m_particles) {
        particle.draw(m_Window,RenderStates::Default);
    }

    // display the window
    m_Window.display();
}


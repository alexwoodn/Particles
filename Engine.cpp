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

// Input function
void Engine::input() {
    sf::Event event;
    while (m_Window.pollEvent(event)) {
        // Handle the Escape key pressed and closed events so your program can exit
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            m_Window.close();
        }

        // Handle the left mouse button pressed event
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            // Create 5 particles
            for (int i = 0; i < 5; ++i) {
                int numPoints = rand() % 26 + 25;  // Random number in the range [25:50]
                Particle newParticle(m_Window, numPoints, { event.mouseButton.x, event.mouseButton.y });
                m_Particles.push_back(newParticle);
            }
        }
    }
}


// Update function
void Engine::update(float dtAsSeconds) {
    auto it = m_Particles.begin();
    while (it != m_Particles.end()) {
        // Loop through m_particles and call update on each Particle in the vector whose ttl has not expired
        if (it->getTTL() > 0.0) {
            it->update(dtAsSeconds);
            ++it;  // increment the iterator
        } else {
            // If a particle's ttl has expired, erase it from the vector
            it = m_Particles.erase(it);
            // erase returns an iterator that points to the next element after deletion, or end if it is the end of the vector
        }
    }
}


// Draw function
void Engine::draw() {
    // clear the window
    m_Window.clear();

    // Loop through each Particle in m_Particles
    for (const auto& particle : m_Particles) {
        // Pass each element into m_Window.draw()
        particle.draw(m_Window);
    }

    // display the window
    m_Window.display();
}


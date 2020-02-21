#include "App.hpp"
#include <iostream>
#include <SFML/Window/Event.hpp>

App::App(int width, int height, const std::string& title)
: m_window(sf::VideoMode(width, height), title)
{
    std::cout << "App ctor()\n";
    m_window.setVerticalSyncEnabled(true);
}

void App::run()
{
    sf::Clock clock;

    while(m_window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        processEvents();
        update(elapsedTime);
        render(elapsedTime);
    }
}

void App::update(sf::Time dt)
{
    
}

void App::processEvents()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                m_window.close();
                break;
            default:
                break;
        }
    }
}

void App::render(sf::Time dt)
{
    m_window.clear();

    m_window.display();
}
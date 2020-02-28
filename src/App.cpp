#include "App.hpp"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "ecs/RenderSystem.hpp"
#include "ecs/ColorChangeSystem.hpp"

App::App(int width, int height, const std::string& title)
: m_window(sf::VideoMode(width, height), title)
{
    std::cout << "App ctor()\n";
    // m_window.setVerticalSyncEnabled(true);
}

void App::run()
{
    sf::Clock clock;

    /*m_engine.init();*/
    m_engine.addSystem(std::move(std::make_unique<ecs::RenderSystem>(m_engine, &m_window)));
    m_engine.addSystem(std::move(std::make_unique<ecs::ColorChangeSystem>(m_engine)));

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
    m_engine.update(dt);
    std::cout << "FPS: " << 1.0f / dt.asSeconds() << "\n";
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
    m_engine.render(dt);
    m_window.display();
}
#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "ecs/Engine.hpp"

class App
{
public:
    App(int width, int height, const std::string& title);
    void run();
    void index();

private:
    void update(sf::Time dt);
    void processEvents();
    void render(sf::Time dt);

    sf::RenderWindow m_window;
    ecs::Engine m_engine;
};

#endif
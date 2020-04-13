#include "Game.h"

Game::Game()
: m_Window(sf::VideoMode(640, 480), "SFML Application")
{
    m_Player.setRadius(10.f);
    m_Player.setPosition(m_Window.getSize().x/2, m_Window.getSize().y/2);
    sf::FloatRect rect = m_Player.getLocalBounds();
    m_Player.setOrigin(rect.left + rect.width/2, rect.top + rect.height/2);
    m_Player.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
    while (m_Window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        m_Window.close();
    }
}

void Game::update()
{
    
}

void Game::render()
{
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.display();
}


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
    sf::Clock clock;
    
    while (m_Window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
                
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
                
            case sf::Event::Closed:
                m_Window.close();
                break;
                
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    
    if (m_IsMovingUp)
        movement.y -= m_speed;
    if (m_IsMovingDown)
        movement.y += m_speed;
    if (m_IsMovingLeft)
        movement.x -= m_speed;
    if (m_IsMovingRight)
        movement.x += m_speed;
    
    m_Player.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Z)
        m_IsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        m_IsMovingDown = isPressed;
    else if (key == sf::Keyboard::Q)
        m_IsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        m_IsMovingRight = isPressed;
}



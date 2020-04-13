#include "Game.h"

const sf::Time Game::m_timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: m_window(sf::VideoMode(640, 480), "SFML Application")
{
    m_player.setRadius(10.f);
    m_player.setPosition(m_window.getSize().x/2, m_window.getSize().y/2);
    sf::FloatRect rect = m_player.getLocalBounds();
    m_player.setOrigin(rect.left + rect.width/2, rect.top + rect.height/2);
    m_player.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while (m_window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > m_timePerFrame)
        {
            timeSinceLastUpdate -= m_timePerFrame;
            processEvents();
            update(m_timePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
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
                m_window.close();
                break;
                
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    
    if (m_isMovingUp)
        movement.y -= m_speed;
    if (m_isMovingDown)
        movement.y += m_speed;
    if (m_isMovingLeft)
        movement.x -= m_speed;
    if (m_isMovingRight)
        movement.x += m_speed;
    
    m_player.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Z)
        m_isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        m_isMovingDown = isPressed;
    else if (key == sf::Keyboard::Q)
        m_isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        m_isMovingRight = isPressed;
}



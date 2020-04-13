#include "Game.h"

const sf::Time Game::m_timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: m_window(sf::VideoMode(1200, 600), "Pong")
{
    m_player1.setSize({10,100});
    m_player1.setPosition(m_window.getSize().x/15, m_window.getSize().y/2);
    sf::FloatRect rectPlay1 = m_player1.getLocalBounds();
    m_player1.setOrigin(rectPlay1.left + rectPlay1.width/2, rectPlay1.top + rectPlay1.height/2);
    m_player1.setFillColor(sf::Color::Cyan);
    m_player2.setSize({10,100});
    m_player2.setPosition(m_window.getSize().x*14/15, m_window.getSize().y/2);
    sf::FloatRect rectPlay2 = m_player2.getLocalBounds();
    m_player2.setOrigin(rectPlay2.left + rectPlay2.width/2, rectPlay2.top + rectPlay2.height/2);
    m_player2.setFillColor(sf::Color::Red);
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
    sf::Vector2f movementP1(0.f, 0.f);
    sf::Vector2f movementP2(0.f, 0.f);
    sf::FloatRect rectPlay1 = m_player1.getGlobalBounds();
    sf::FloatRect rectPlay2 = m_player2.getGlobalBounds();
    
    if (m_isP1MovingUp && rectPlay1.top >= 0)
        movementP1.y -= m_speed;
    if (m_isP1MovingDown && rectPlay1.top + rectPlay1.height  <= m_window.getSize().y)
        movementP1.y += m_speed;
    if (m_isP2MovingUp && rectPlay2.top >= 0)
        movementP2.y -= m_speed;
    if (m_isP2MovingDown && rectPlay2.top + rectPlay2.height <= m_window.getSize().y)
        movementP2.y += m_speed;
    
    m_player1.move(movementP1 * deltaTime.asSeconds());
    m_player2.move(movementP2 * deltaTime.asSeconds());
}

void Game::render()
{
    m_window.clear();
    m_window.draw(m_player1);
    m_window.draw(m_player2);
    m_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Z)
        m_isP1MovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        m_isP1MovingDown = isPressed;
    else if (key == sf::Keyboard::O)
        m_isP2MovingUp = isPressed;
    else if (key == sf::Keyboard::L)
        m_isP2MovingDown = isPressed;
}



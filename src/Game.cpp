#include "Game.h"

const sf::Time Game::m_timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: m_window(sf::VideoMode(1100, 600), "Pong Game")
{
    m_player1.setPosition(m_window.getSize().x / 15, m_window.getSize().y / 2);
    m_player1.setFillColor(sf::Color::Cyan);
    
    m_player2.setPosition(m_window.getSize().x * 14 / 15, m_window.getSize().y / 2);
    m_player2.setFillColor(sf::Color::Red);
    
    m_ball.setPosition(m_window.getSize().x / 2, 0.f);
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
        
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::update(sf::Time deltaTime)
{
    handlePlayerInput();
    
    sf::Vector2f movementP1(0.f, 0.f);
    sf::Vector2f movementP2(0.f, 0.f);
    sf::Vector2f movementBall(0.f, 0.f);
    
    sf::FloatRect rectP1 = m_player1.getGlobalBounds();
    sf::FloatRect rectP2 = m_player2.getGlobalBounds();
    
    float tickMovement = Player::getSpeed() * m_timePerFrame.asSeconds();

    if (m_player1.isMovingUp() && rectP1.top >= tickMovement)
        movementP1.y -= m_player1.getSpeed();
    if (m_player1.isMovingDown() && rectP1.top + rectP1.height  <= m_window.getSize().y - tickMovement)
        movementP1.y += m_player1.getSpeed();
    if (m_player2.isMovingUp() && rectP2.top >= tickMovement)
        movementP2.y -= m_player2.getSpeed();
    if (m_player2.isMovingDown() && rectP2.top + rectP2.height <= m_window.getSize().y - tickMovement)
        movementP2.y += m_player2.getSpeed();
    
    m_player1.move(movementP1 * deltaTime.asSeconds());
    m_player2.move(movementP2 * deltaTime.asSeconds());
    m_ball.move(movementBall * deltaTime.asSeconds());
}

void Game::render()
{
    m_window.clear();
    m_window.draw(m_player1);
    m_window.draw(m_player2);
    m_window.draw(m_ball);
    m_window.display();
}

void Game::handlePlayerInput()
{
    m_player1.setMovingUp(sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
    m_player1.setMovingDown(sf::Keyboard::isKeyPressed(sf::Keyboard::S));
    m_player2.setMovingUp(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    m_player2.setMovingDown(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
}



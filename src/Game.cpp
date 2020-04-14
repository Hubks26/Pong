#include "Game.h"

const sf::Time Game::m_timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: m_window(sf::VideoMode(1200, 600), "Pong")
{
    m_player1.setSize({15,130});
    m_player1.setPosition(m_window.getSize().x/15, m_window.getSize().y/2);
    sf::FloatRect rectP1 = m_player1.getLocalBounds();
    m_player1.setOrigin(rectP1.left + rectP1.width/2, rectP1.top + rectP1.height/2);
    m_player1.setFillColor(sf::Color::Cyan);
    m_player2.setSize({15,130});
    m_player2.setPosition(m_window.getSize().x*14/15, m_window.getSize().y/2);
    sf::FloatRect rectP2 = m_player2.getLocalBounds();
    m_player2.setOrigin(rectP2.left + rectP2.width/2, rectP2.top + rectP2.height/2);
    m_player2.setFillColor(sf::Color::Red);
    m_ball.setRadius(10.f);
    m_ball.setPosition(m_window.getSize().x/2, 0.f);
    sf::FloatRect rectBall = m_ball.getLocalBounds();
    m_ball.setOrigin(rectBall.left + rectBall.width/2, rectBall.top);
    m_ball.setFillColor(sf::Color::White);
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
    if (!m_ballStartMovingForP2 && (m_isP1MovingUp || m_isP1MovingDown))
        m_ballStartMovingForP1 = true;
    if (m_ballStartMovingForP1)
        movementBall = {-m_speedBall, m_speedBall};
    if (!m_ballStartMovingForP1 && (m_isP2MovingUp || m_isP2MovingDown))
        m_ballStartMovingForP2 = true;
    if (m_ballStartMovingForP2)
        movementBall = {m_speedBall, m_speedBall};
    
    sf::FloatRect rectP1 = m_player1.getGlobalBounds();
    sf::FloatRect rectP2 = m_player2.getGlobalBounds();
    
    float tickMovement = m_speedPlayers * m_timePerFrame.asSeconds();

    if (m_isP1MovingUp && rectP1.top >= tickMovement)
        movementP1.y -= m_speedPlayers;
    if (m_isP1MovingDown && rectP1.top + rectP1.height  <= m_window.getSize().y - tickMovement)
        movementP1.y += m_speedPlayers;
    if (m_isP2MovingUp && rectP2.top >= tickMovement)
        movementP2.y -= m_speedPlayers;
    if (m_isP2MovingDown && rectP2.top + rectP2.height <= m_window.getSize().y - tickMovement)
        movementP2.y += m_speedPlayers;
    
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
    m_isP1MovingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    m_isP1MovingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
    m_isP2MovingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::U);
    m_isP2MovingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::N);
}



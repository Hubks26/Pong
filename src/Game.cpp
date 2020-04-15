#include "Game.h"

const sf::Time Game::m_timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: m_window(sf::VideoMode(1100, 600), "The Pong Game")
, m_acceleration(30.f)
{
    m_player1.setPosition(m_window.getSize().x / 15, m_window.getSize().y / 2);
    m_player1.setFillColor(sf::Color::Cyan);
    
    m_player2.setPosition(m_window.getSize().x * 14 / 15, m_window.getSize().y / 2);
    m_player2.setFillColor(sf::Color::Red);
    
    m_ball.setPosition(m_window.getSize().x / 2, 20.f);
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
    
    sf::FloatRect rectP1 = m_player1.getGlobalBounds();
    sf::FloatRect rectP2 = m_player2.getGlobalBounds();
    sf::FloatRect rectBall = m_ball.getGlobalBounds();
    
    float tickMovementPlayers = Player::getSpeed() * m_timePerFrame.asSeconds();
    float tickMovementBall = m_ball.getSpeed() / sqrt(2) * m_timePerFrame.asSeconds();

    float p1Top = rectP1.top;
    float p2Top = rectP2.top;
    float ballTop = rectBall.top;
    
    float p1Bot = rectP1.top + rectP1.height;
    float p2Bot = rectP2.top + rectP2.height;
    float ballBot = rectBall.top + rectBall.height;
    
    float p2Left = rectP2.left;
    float ballLeft = rectBall.left;
    
    float p1Right = rectP1.left + rectP1.width;
    float ballRight = rectBall.left + rectBall.width;
    
    if (m_player1.isMovingUp() && p1Top >= tickMovementPlayers)
        movementP1.y -= m_player1.getSpeed();
    if (m_player1.isMovingDown() && p1Bot  <= m_window.getSize().y - tickMovementPlayers)
        movementP1.y += m_player1.getSpeed();
    if (m_player2.isMovingUp() && p2Top >= tickMovementPlayers)
        movementP2.y -= m_player2.getSpeed();
    if (m_player2.isMovingDown() && p2Bot <= m_window.getSize().y - tickMovementPlayers)
        movementP2.y += m_player2.getSpeed();
    
    if (ballLeft < tickMovementBall || ballRight > m_window.getSize().x - tickMovementBall)
        m_ball.rebound(WallPosition::Vertical);
    if (ballTop < tickMovementBall || ballBot > m_window.getSize().y - tickMovementBall)
        m_ball.rebound(WallPosition::Horizontal);
    
    if (rectBall.intersects(rectP1) && ballLeft >= p1Right - tickMovementBall)
    {
        m_ball.rebound(WallPosition::Vertical);
        m_ball.acceleration(m_acceleration);
    }
    
    if (rectBall.intersects(rectP2) && ballRight <= p2Left + tickMovementBall)
    {
        m_ball.rebound(WallPosition::Vertical);
        m_ball.acceleration(m_acceleration);
    }  
    
    if (ballLeft < tickMovementBall || ballRight > m_window.getSize().x - tickMovementBall)
    {
        m_ball.setPosition(m_window.getSize().x / 2, 20.f);
        m_ball.setInitialSpeed();
    }
    
    m_player1.move(movementP1 * deltaTime.asSeconds());
    m_player2.move(movementP2 * deltaTime.asSeconds());
    m_ball.move(m_ball.getSpeedVect() * deltaTime.asSeconds());
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



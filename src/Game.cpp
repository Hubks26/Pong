#include "Game.h"

bool areIntersected(sf::Vector2f interval1, sf::Vector2f interval2)
{
    bool result = false;
    if (interval1.x <= interval2.x && interval1.y >= interval2.x)
        result = true;
    else if (interval1.x <= interval2.y && interval1.y >= interval2.y)
        result = true;
    else if (interval1.x >= interval2.x && interval1.y <= interval2.y)
        result = true;
    else if (interval1.x <= interval2.x && interval1.y >= interval2.y)
        result = true;
    return result;
}

const sf::Time Game::m_timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: m_window(sf::VideoMode(1100, 600), "Pong Game")
{
    m_player1.setPosition(m_window.getSize().x / 15, m_window.getSize().y / 2);
    m_player1.setFillColor(sf::Color::Cyan);
    
    m_player2.setPosition(m_window.getSize().x * 14 / 15, m_window.getSize().y / 2);
    m_player2.setFillColor(sf::Color::Red);
    
    m_ball.setPosition(m_window.getSize().x / 2, 10.f);
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
    float tickMovementBall = Ball::getSpeed() / sqrt(2) * m_timePerFrame.asSeconds();

    float rectP1Bot = rectP1.top + rectP1.height;
    float rectP2Bot = rectP2.top + rectP2.height;
    float rectBallBot = rectBall.top + rectBall.height;
    
    if (m_player1.isMovingUp() && rectP1.top >= tickMovementPlayers)
        movementP1.y -= m_player1.getSpeed();
    if (m_player1.isMovingDown() && rectP1Bot  <= m_window.getSize().y - tickMovementPlayers)
        movementP1.y += m_player1.getSpeed();
    if (m_player2.isMovingUp() && rectP2.top >= tickMovementPlayers)
        movementP2.y -= m_player2.getSpeed();
    if (m_player2.isMovingDown() && rectP2Bot <= m_window.getSize().y - tickMovementPlayers)
        movementP2.y += m_player2.getSpeed();
    
    if (rectBall.left < tickMovementBall || rectBall.left + rectBall.width > m_window.getSize().x - tickMovementBall)
        m_ball.rebound(true);
    if (rectBall.top < tickMovementBall || rectBallBot > m_window.getSize().y - tickMovementBall)
        m_ball.rebound(false);
    
    if (rectBall.left < tickMovementBall + rectP1.left + rectP1.width && rectBall.left > rectP1.left + rectP1.width && areIntersected({rectBall.top, rectBallBot}, {rectP1.top, rectP1Bot}))
        m_ball.rebound(true);
    if (rectBall.left + rectBall.width > rectP2.left - tickMovementBall && rectBall.left + rectBall.width < rectP2.left && areIntersected({rectBall.top, rectBallBot}, {rectP2.top, rectP2Bot}))
        m_ball.rebound(true);
        
    if (rectBall.left + rectBall.width > rectP1.left - tickMovementBall && rectBall.left + rectBall.width < rectP1.left && areIntersected({rectBall.top, rectBallBot}, {rectP1.top, rectP1Bot}))
        m_ball.rebound(true);
    if (rectBall.left < rectP2.left + rectP2.width + tickMovementBall && rectBall.left > rectP2.left + rectP2.width && areIntersected({rectBall.top, rectBallBot}, {rectP2.top, rectP2Bot}))
        m_ball.rebound(true);
        
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



#include "Ball.h"

const float initialSpeed = 550.f;

Ball::Ball()
: m_acceleration(30.f)
{
    if (!m_bufferRebound.loadFromFile("media/sounds/rebound.wav"))
        throw std::runtime_error ("Ball::Ball() - Failed to load 'media/sounds/rebound.wav'");
    m_soundRebound.setBuffer(m_bufferRebound);
    if (!m_bufferLaunch.loadFromFile("media/sounds/launch.wav"))
        throw std::runtime_error ("Ball::Ball() - Failed to load 'media/sounds/launch.wav'");
    m_soundLaunch.setBuffer(m_bufferLaunch);
    
    stop();
    setRadius(10.f);
    sf::FloatRect rectBall = getLocalBounds();
    setOrigin(rectBall.left + rectBall.width / 2, rectBall.top);
    setFillColor(sf::Color::White);
}

void Ball::rebound(WallPosition wallPosition)
{
    if (wallPosition == WallPosition::Vertical)
        m_speedVect.x = -m_speedVect.x;
    else if (wallPosition == WallPosition::Horizontal)
        m_speedVect.y = -m_speedVect.y;
    
    m_soundRebound.play();
}

void Ball::acceleration()
{
    m_speed += m_acceleration;
    m_speedVect.x = (m_speedVect.x / abs(m_speedVect.x)) * m_speed / sqrt(2);
    m_speedVect.y = (m_speedVect.y / abs(m_speedVect.y)) * m_speed / sqrt(2);
}

void Ball::stop()
{
    m_speed = 0.f;
    m_speedVect = {0.f, 0.f};
}

/*********
 *Setters*
 * *******/

void Ball::setServe(ServeDirection dir)
{
    m_speed = initialSpeed;
    
    switch (dir)
    {
        case ServeDirection::Right :
            m_speedVect.x = m_speed / sqrt(2);
            m_speedVect.y = m_speed / sqrt(2);
            break;
            
        case ServeDirection::Left :
            m_speedVect.x = -m_speed / sqrt(2);
            m_speedVect.y = m_speed / sqrt(2);
            break;
    }
    
    m_soundLaunch.play();
}

/*********
 *Getters*
 * *******/

float Ball::getSpeed() const
{
    return m_speed;
}

sf::Vector2f Ball::getSpeedVect() const
{
    return m_speedVect;
}

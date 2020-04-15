#include "Ball.h"

const float initialSpeed = 550.f;

Ball::Ball()
: m_speed(initialSpeed)
, m_speedVect(-m_speed / sqrt(2), m_speed / sqrt(2))
, m_acceleration(30.f)
{
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
}

void Ball::acceleration()
{
    m_speed += m_acceleration;
    m_speedVect.x = (m_speedVect.x / abs(m_speedVect.x)) * m_speed / sqrt(2);
    m_speedVect.y = (m_speedVect.y / abs(m_speedVect.y)) * m_speed / sqrt(2);
}

/*********
 *Setters*
 * *******/

void Ball::setInitialSpeed()
{
    m_speed = initialSpeed;
    m_speedVect.x = (m_speedVect.x / abs(m_speedVect.x)) * m_speed / sqrt(2);
    m_speedVect.y = (m_speedVect.y / abs(m_speedVect.y)) * m_speed / sqrt(2);
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

#include "Ball.h"

float Ball::m_speed = 700.f;

Ball::Ball()
: m_speedVect(-m_speed / sqrt(2), m_speed / sqrt(2))
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

/*********
 *Getters*
 * *******/

float Ball::getSpeed()
{
    return m_speed;
}

sf::Vector2f Ball::getSpeedVect() const
{
    return m_speedVect;
}

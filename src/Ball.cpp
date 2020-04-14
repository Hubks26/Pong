#include "Ball.h"


Ball::Ball()
: m_isMoving(false)
, m_speed(300.f)
{
    setRadius(10.f);
    sf::FloatRect rectBall = getLocalBounds();
    setOrigin(rectBall.left + rectBall.width / 2, rectBall.top);
    setFillColor(sf::Color::White);
}


/*********
 *Setters*
 * *******/

void Ball::setMoving(bool isMoving)
{
    m_isMoving = isMoving;
}


/*********
 *Getters*
 * *******/

float Ball::getSpeed() const
{
    return m_speed;
}

bool Ball::isMoving() const
{
    return m_isMoving;
}

#include "Ball.h"

/*********
 *Setters*
 * *******/

void Ball::setSpeed(float speed)
{
    m_speed = speed;
}

void Ball::setIsMoving(bool isMoving)
{
    m_isMoving = isMoving;
}


/*********
 *Getters*
 * *******/

float Ball::getSpeed()
{
    return m_speed;
}

bool Ball::getIsMoving()
{
    return m_isMoving;
}

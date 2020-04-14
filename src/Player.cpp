#include "Player.h"

float Player::m_speed = 450;

/*********
 *Setters*
 * *******/

void Player::setIsMovingUp(bool isMovingUp)
{
    m_isMovingUp = isMovingUp;
}

void Player::setIsMovingDown(bool isMovingDown)
{
    m_isMovingDown = isMovingDown;
}

/*********
 *Getters*
 * *******/

float Player::getSpeed()
{
    return m_speed;
}

bool Player::getIsMovingUp()
{
    return m_isMovingUp;
}

bool Player::getIsMovingDown()
{
    return m_isMovingDown;
}

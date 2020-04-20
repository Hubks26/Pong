#include "Player.h"

const float Player::m_speed = 800.f;

Player::Player()
: m_isMovingUp(false)
, m_isMovingDown(false)
{
    setSize({15u, 150u});
    sf::FloatRect rectP1 = getLocalBounds();
    setOrigin(rectP1.width / 2, rectP1.height / 2);
}

/*********
 *Setters*
 * *******/

void Player::setMovingUp(bool isMovingUp)
{
    m_isMovingUp = isMovingUp;
}

void Player::setMovingDown(bool isMovingDown)
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

bool Player::isMovingUp() const
{
    return m_isMovingUp;
}

bool Player::isMovingDown() const
{
    return m_isMovingDown;
}

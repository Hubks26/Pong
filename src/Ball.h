#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <cmath>

enum class WallPosition
{
    Vertical,
    Horizontal
};

class Ball : public sf::CircleShape
{
    public:
        
        Ball();
        
        void rebound(WallPosition);
        void acceleration();
        
        void setInitialSpeed();
        
        float getSpeed() const;
        sf::Vector2f getSpeedVect() const;
        
    private:
        
        float m_speed;
        sf::Vector2f m_speedVect;
        float m_acceleration;
};

#endif // BALL_H

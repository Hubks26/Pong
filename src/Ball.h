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
        
        static float getSpeed();
        sf::Vector2f getSpeedVect() const;
        
    private:
        
        static float m_speed;
        sf::Vector2f m_speedVect;
};

#endif // BALL_H

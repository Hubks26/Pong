#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
    public:
        
        Ball() = default;
        
        void setSpeed(float);
        void setIsMoving(bool);
        
        float getSpeed();
        bool getIsMoving();
        
    private:
        
        bool m_isMoving = false;
        
        float m_speed = 300.f;
};

#endif // BALL_H

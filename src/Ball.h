#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
    public:
        
        Ball();
        
        void setMoving(bool);
        
        float getSpeed() const;
        bool isMoving() const;
        
    private:
        
        bool m_isMoving;
        float m_speed;
};

#endif // BALL_H

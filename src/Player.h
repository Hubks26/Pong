#ifndef PLAYERS_H
#define PLAYERS_H

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape
{
    public:
        
        Player();
        
        void setMovingUp(bool);
        void setMovingDown(bool);
        
        static float getSpeed();
        bool isMovingUp() const;
        bool isMovingDown() const;
        
    private:
        
        bool m_isMovingUp;
        bool m_isMovingDown;
        
        static const float m_speed;
};

#endif // PLAYERS_H

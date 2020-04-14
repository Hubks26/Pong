#ifndef PLAYERS_H
#define PLAYERS_H

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape
{
    public:
        
        Player() = default;
        
        void setIsMovingUp(bool);
        void setIsMovingDown(bool);
        
        float getSpeed();
        bool getIsMovingUp();
        bool getIsMovingDown();
        
    private:
        
        bool m_isMovingUp = false;
        bool m_isMovingDown = false;
        
        static float m_speed;
};

#endif // PLAYERS_H

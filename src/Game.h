#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    public:
        
        Game();
        void run();
        
    private:
        
        void processEvents();
        void update(sf::Time);
        void render();
        
        void handlePlayerInput(sf::Keyboard::Key, bool);
        
    private:
        
        sf::RenderWindow m_window;
        sf::CircleShape m_player;
    
        static const sf::Time m_timePerFrame;
        
        float m_speed = 170.f;
        
        bool m_isMovingUp;
        bool m_isMovingDown;
        bool m_isMovingLeft;
        bool m_isMovingRight;
};

#endif // GAME_H

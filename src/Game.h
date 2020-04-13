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
        
        sf::RenderWindow m_Window;
        sf::CircleShape m_Player;
    
        float m_speed = 200.f;
        
        bool m_IsMovingUp;
        bool m_IsMovingDown;
        bool m_IsMovingLeft;
        bool m_IsMovingRight;
};

#endif // GAME_H

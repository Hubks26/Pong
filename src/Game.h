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
        sf::RectangleShape m_player1;
        sf::RectangleShape m_player2;
    
        static const sf::Time m_timePerFrame;
        
        float m_speed = 300.f;
        
        bool m_isP1MovingUp = false;
        bool m_isP1MovingDown = false;
        bool m_isP2MovingUp = false;
        bool m_isP2MovingDown = false;
};

#endif // GAME_H

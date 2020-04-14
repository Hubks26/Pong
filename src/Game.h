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
        
        void handlePlayerInput();
        
    private:
        
        sf::RenderWindow m_window;
        sf::RectangleShape m_player1;
        sf::RectangleShape m_player2;
        sf::CircleShape m_ball;
    
        static const sf::Time m_timePerFrame;
        
        float m_speedPlayers = 450.f;
        float m_speedBall = 400.f;
        
        bool m_isP1MovingUp = false;
        bool m_isP1MovingDown = false;
        bool m_isP2MovingUp = false;
        bool m_isP2MovingDown = false;
        
        bool m_ballStartMovingForP1 = false;
        bool m_ballStartMovingForP2 = false;
};

#endif // GAME_H

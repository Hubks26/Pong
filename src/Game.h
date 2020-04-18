#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Ball.h"

bool areIntersected(sf::Vector2f, sf::Vector2f);

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
        Player m_player1;
        Player m_player2;
        Ball m_ball;
    
        static const sf::Time m_timePerFrame;
        
        sf::SoundBuffer m_buffer;
        sf::Sound m_sound;
};

#endif // GAME_H

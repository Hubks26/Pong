#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Ball.h"
#include "Score.h"

class Game
{
    public:
        
        Game();
        void run();
        
        bool m_isLastPointForP1;
        bool m_isBallLaunched;
        
    private:
        
        void processEvents();
        void update(sf::Time);
        void render();
        
        void handlePlayerInput();
        
    private:
        
        sf::RenderWindow m_window;
        
        Player m_player1;
        Player m_player2;
        
        Score m_score1;
        Score m_score2;
        
        Ball m_ball;
    
        static const sf::Time m_timePerFrame;
        
        sf::SoundBuffer m_bufferStart;
        sf::SoundBuffer m_bufferGoal;
        sf::Sound m_soundStart;
        sf::Sound m_soundGoal;
};

#endif // GAME_H

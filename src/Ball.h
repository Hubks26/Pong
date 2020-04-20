#ifndef BALL_H
#define BALL_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>

enum class WallPosition
{
    Vertical,
    Horizontal
};

enum class ServeDirection
{
    Right,
    Left
};

class Ball : public sf::CircleShape
{
    public:
        
        Ball();
        
        void rebound(WallPosition);
        void acceleration();
        
        void setServe(ServeDirection);
        
        float getSpeed() const;
        sf::Vector2f getSpeedVect() const;
        
    private:
        
        float m_speed;
        sf::Vector2f m_speedVect;
        float m_acceleration;
        
        sf::SoundBuffer m_bufferRebound;
        sf::Sound m_soundRebound;
};

#endif // BALL_H

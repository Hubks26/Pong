#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <stdexcept>

class Score : public sf::Drawable, public sf::Transformable
{
    public:
        
        Score();
        
        void increase();
        
        sf::FloatRect getLocalBounds() const;
        
    private:
    
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        
        void update();
        
    private:
        
        unsigned m_value;
        
        sf::Font m_font;
        sf::Text m_text;
};

#endif // SCORE_H

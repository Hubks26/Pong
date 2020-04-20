#include "Score.h"

Score::Score()
: m_value(0u)
{
    if (!m_font.loadFromFile("media/fonts/arial.ttf"))
    {
        throw std::runtime_error ("Textbox::build() - Failed to load 'media/fonts/arial.ttf'");
    }
    m_text.setFont(m_font);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(45u);
    m_text.setStyle(sf::Text::Bold);
    m_text.setString("0");
}

void Score::increase()
{
    m_value++;
    update();
}

/**********
 * Getter *
 **********/

unsigned Score::getValue() const
{
    return m_value;
}

sf::FloatRect Score::getLocalBounds() const
{
    return m_text.getLocalBounds();
}

/***********
 * Private *
 ***********/

void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_text, states);
}

void Score::update()
{
    float preWidth = getLocalBounds().width;
    float originRatio;
    
    if (getOrigin().x == 0.f)
        originRatio = 0.f;
    else 
        originRatio = 1.f;

    m_text.setString(std::to_string(m_value));

    float postWidth = getLocalBounds().width;
    float deltaX = postWidth - preWidth;

    move(-deltaX * originRatio, 0.f);
}

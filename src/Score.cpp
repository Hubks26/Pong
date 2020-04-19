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
    m_text.setCharacterSize(50u);
    update();
}

void Score::increase()
{
    m_value++;
    update();
}

/**********
 * Getter *
 **********/

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
    m_text.setString(std::to_string(m_value));
}

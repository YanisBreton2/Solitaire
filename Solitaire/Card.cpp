#include "Card.h"

sf::Texture		*back_card_texture = NULL;

std::string cardTypeToString(int type)
{
	switch(type)
	{
	case DIAMOND:
		return "diamond";
	case SPADE:
		return "spade";
	case HEART:
		return "heart";
	case CLUB:
		return "club";
	}
	return "";
}

Card::Card(int type, int number): m_type(type), m_number(number)
{
	if (!back_card_texture)
	{
		back_card_texture = new sf::Texture();
		if (!back_card_texture->loadFromFile("../Ressource/cards/back_card.png"))
			exit(1);
	}
	if (!m_texture.loadFromFile("../Ressource/cards/"+ cardTypeToString(type) +"/" + std::to_string((long long)number) + ".png"))
		exit(1);
	m_sprite.setTexture(*back_card_texture);
	m_sprite.setScale(0.15f, 0.15f);
	m_hide = true;
}


Card::~Card(void)
{
}

int	Card::getType(void)
{
	return (m_type);
}

int Card::getNumber(void)
{
	return (m_number);
}

sf::Sprite Card::getSprite(void)
{
	return (m_sprite);
}

void	Card::hide(bool value)
{
	if (value)
		m_sprite.setTexture(*back_card_texture);
	else
		m_sprite.setTexture(m_texture);
	m_hide = value;
}

void	Card::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}
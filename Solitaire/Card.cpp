#include "Card.h"

std::string cardTypeToString(int type)
{
	switch(type)
	{
	case DIAMOND:
		return "DIAMOND";
	case SPADE:
		return "SPADE";
	case HEART:
		return "HEART";
	case CLUB:
		return "CLUB";
	}
}

Card::Card(int type, int number): m_type(type), m_number(number)
{
	//if (!m_texture.loadFromFile("../Ressource/card/"+cardTypeToString((long long)type)+"/" + + ".png"))
	//	exit(1);
	//m_sprite.setTexture(m_texture);
	m_hide = false;
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

void	Card::setVisible(bool value)
{
	m_hide = value;
}
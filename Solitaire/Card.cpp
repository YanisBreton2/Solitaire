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
	if (!m_texture.loadFromFile("../Ressource/card/"+cardTypeToString(type)+"/"+m_number+".png"))
		exit(1);
	m_sprite.setTexture(m_texture);
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

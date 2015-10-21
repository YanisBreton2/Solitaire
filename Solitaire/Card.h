#ifndef CARD_H_
# define CARD_H_

# include <SFML\Graphics.hpp>

# define DIAMOND (1) // Carreaux
# define SPADE   (2) // Pique
# define HEART   (3) // Coeur
# define CLUB    (4) // Trèfle

# define JACK  (11) // Valet
# define QUEEN (12) // Reine
# define KING  (13) // Roi
# define AS    (1)
class Card
{
public:
	Card(int type, int number);
	~Card(void);
	int	getType(void);
	int getNumber(void);
	sf::Sprite getSprite(void);

private:
	int			m_type;
	int			m_number;
	sf::Texture	m_texture;
	sf::Sprite	m_sprite;
};

#endif /* !CARD_H_ */
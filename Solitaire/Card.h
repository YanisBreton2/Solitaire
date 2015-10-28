#ifndef CARD_H_
# define CARD_H_

# if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#  include <SFML\Graphics.hpp>
# else
#  include <SFML/Graphics.hpp>
# endif /* !WINDOWS */

# define DIAMOND (1)  // Carreaux
# define SPADE   (2)  // Pique
# define HEART   (3)  // Coeur
# define CLUB    (4)  // Trèfle

# define JACK    (11) // Valet
# define QUEEN   (12) // Reine
# define KING    (13) // Roi
# define AS      (1)

# define SCALE	 (0.17f)

class			Card
{
public:
				Card(int type, int number);
				~Card(void);
	int			getType(void);
	int			getNumber(void);
	void		hide(bool value);
	sf::Sprite	getSprite(void);
	void		setPosition(float x, float y);

private:
	int			m_type;
	int			m_number;
	bool		m_hide; // false si la carte est face caché, true sinon
	sf::Texture	m_texture;
	sf::Sprite	m_sprite;
};

#endif /* !CARD_H_ */
